#ifndef display_h
#define display_h

#include "Wire.h"     // libreria para bus I2C
#include "Adafruit_SSD1306.h"   // libreria para controlador SSD1306

Adafruit_SSD1306 oled(128, 64, &Wire, 4);  // crea objeto

void displayStart() {

  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C 
}

void displayPresentation() {
  
  oled.clearDisplay(); 
  oled.setTextColor(WHITE);   
  oled.setCursor(16, 0);    
  oled.setTextSize(2);     
  oled.print("PLC NODE"); 
  oled.setCursor (52, 28);  
  oled.setTextSize(2);     
  oled.print("V4");     
  oled.display();    

  delay(1000);
}
 
void displayTest() {

    for(int i = 1; i <= 4; i++)
  {
    oled.clearDisplay(); 
    oled.setTextColor(WHITE);   
    oled.setCursor(16, 0);    
    oled.setTextSize(2);     
    oled.print("PLC NODE"); 
    oled.setCursor (52, 28);  
    oled.setTextSize(2);     
    oled.print("V"); 
    oled.print(i);    
    oled.display();
    delay(150);
  }
}

int displayMainMenu(){
  
    int option = 3;
    int desition = 1;
    
  oled.setTextColor(WHITE);
  
  while(true){
    oled.clearDisplay(); 
    oled.setCursor(20, 0);    
    oled.setTextSize(2);     
    oled.print("MENU"); 
    oled.setTextSize(1);
    oled.setCursor (0, 28);  
    oled.print("Select");
    oled.setCursor (64, 20); oled.print("Execute"); 
    oled.setCursor (64, 28); oled.print("Mode"); 
    oled.setCursor (64, 36); oled.print("cfg");
    
    if(option == 3){oled.setCursor (58, 20); oled.print(">"); }
    if(option == 2){oled.setCursor (58, 28); oled.print(">"); }
    if(option == 1){oled.setCursor (58, 36); oled.print(">"); }
    

    //Serial.println("  LEFT "+digitalReadBTNLEFT()+"  RIGHT "+digitalReadBTNRIGHT()+"  UP "+digitalReadBTNUP()+"  DOWN "+digitalReadBTNDOWN());
    
    if(digitalReadBTNLEFT()== "1"  ){delay(150);}
    if(digitalReadBTNRIGHT()== "1" ){desition = option; delay(150); break;}
    if(digitalReadBTNUP()== "1"    ){option++; if(option >= 3){option = 3;} delay(150);}
    if(digitalReadBTNDOWN()== "1"  ){option--; if(option <= 1){option = 1; } delay(150);}
    oled.display();
    }
    return desition;
}

void displayExecuting(){
  oled.setTextColor(WHITE);
    oled.clearDisplay();
    oled.setTextSize(2);  
    oled.setCursor(16, 0);    
    oled.print("PLC NODE");    
    oled.setCursor(16, 28);    
    oled.setTextSize(2);     
    oled.print("RUNNING"); 
    oled.display();
    delay(150);
}

int displayModeMain(){
  
    int option = 2;
    int desition = 1;
    
  oled.setTextColor(WHITE);
  
  while(true){
    oled.clearDisplay(); 
    oled.setCursor(20, 0);    
    oled.setTextSize(2);     
    oled.print("MENU"); 
    oled.setTextSize(1);
    oled.setCursor (0, 28);  
    oled.print("Mode");
    oled.setCursor (64, 20); oled.print("Wifi"); 
    oled.setCursor (64, 28); oled.print("Protocol"); 
    
    if(option == 2){oled.setCursor (58, 20); oled.print(">"); }
    if(option == 1){oled.setCursor (58, 28); oled.print(">"); }

    //Serial.println("  LEFT "+digitalReadBTNLEFT()+"  RIGHT "+digitalReadBTNRIGHT()+"  UP "+digitalReadBTNUP()+"  DOWN "+digitalReadBTNDOWN());
    
    if(digitalReadBTNLEFT()== "1"  ){desition = 0; delay(150); break;}
    if(digitalReadBTNRIGHT()== "1" ){desition = option; delay(150); break;}
    if(digitalReadBTNUP()== "1"    ){option++; if(option >= 2){option = 2;} delay(150);}
    if(digitalReadBTNDOWN()== "1"  ){option--; if(option <= 1){option = 1; } delay(150);}
    oled.display();
    }
    return desition;
}

int displayWifiMode() {
  
  int option = 2;
  int desition = 1;
  int wifiMode = memoryGetWifiMode();
  oled.setTextColor(WHITE);
  
  
  while(true){
    oled.clearDisplay(); 
    oled.setCursor(20, 0);    
    oled.setTextSize(2);     
    oled.print("MENU"); 
    oled.setTextSize(1);
    oled.setCursor (0, 28);  
    oled.print("Wifi");
    oled.setCursor (64, 28); oled.print("A.point"); 
    oled.setCursor (64, 36); oled.print("Client"); 

    if(wifiMode == 2){oled.setCursor (58, 28); oled.print("0"); }
    if(wifiMode == 1){oled.setCursor (58, 36); oled.print("0"); }
    
    if(option == 2){oled.setCursor (58, 28); oled.print(">"); }
    if(option == 1){oled.setCursor (58, 36); oled.print(">"); }

    if(digitalReadBTNLEFT()== "1"  ){option = 0; desition = option; delay(150); break;}
    if(digitalReadBTNRIGHT()== "1" ){wifiMode = option; delay(150); }
    if(digitalReadBTNUP()== "1"    ){option++; if(option >= 2){option = 2;} delay(150);}
    if(digitalReadBTNDOWN()== "1"  ){option--; if(option <= 1){option = 1; } delay(150);}
    oled.display();
    }
    memorySetWifiMode(wifiMode);
    return desition;
}

int displayProtocolMode() {
  
  int option = 2;
  int desition = 1;
  int protocolMode = memoryGetProtocolMode();
  oled.setTextColor(WHITE);
  
  
  while(true){
    oled.clearDisplay(); 
    oled.setCursor(20, 0);    
    oled.setTextSize(2);     
    oled.print("MENU"); 
    oled.setTextSize(1);
    oled.setCursor (0, 28);  
    oled.print("Protocol");
    oled.setCursor (64, 20); oled.print("Websocket"); 
    oled.setCursor (64, 28); oled.print("Serial"); 

    if(protocolMode == 2){oled.setCursor (58, 20); oled.print("0"); }
    if(protocolMode == 1){oled.setCursor (58, 28); oled.print("0"); }
    
    if(option == 2){oled.setCursor (58, 20); oled.print(">"); }
    if(option == 1){oled.setCursor (58, 28); oled.print(">"); }

    if(digitalReadBTNLEFT()== "1"  ){option = 0; desition = option; delay(150); break;}
    if(digitalReadBTNRIGHT()== "1" ){protocolMode = option; delay(150); }
    if(digitalReadBTNUP()== "1"    ){option++; if(option >= 2){option = 2;} delay(150);}
    if(digitalReadBTNDOWN()== "1"  ){option--; if(option <= 1){option = 1; } delay(150);}
    oled.display();
    }
    memorySetProtocolMode(protocolMode);
    return desition;
}

int displayConfigurationMenu(){
  
    int option = 2;
    int desition = 1;
    
  oled.setTextColor(WHITE);
  
  while(true){
    oled.clearDisplay(); 
    oled.setCursor(20, 0);    
    oled.setTextSize(2);     
    oled.print("MENU"); 
    oled.setTextSize(1);
    oled.setCursor (0, 20);  
    oled.print("Cfg");
    oled.setCursor (64, 28); oled.print("OTAProgram"); 
    oled.setCursor (64, 36); oled.print("Wifi"); 
    oled.setCursor (64, 44); oled.print("Protocol");

    if(option == 3){oled.setCursor (58, 28); oled.print(">"); }
    if(option == 2){oled.setCursor (58, 36); oled.print(">"); }
    if(option == 1){oled.setCursor (58, 44); oled.print(">"); }
    
    if(digitalReadBTNLEFT()== "1"  ){option = 0; desition = option; delay(150); break;}
    if(digitalReadBTNRIGHT()== "1" ){desition = option; delay(150); break;}
    if(digitalReadBTNUP()== "1"    ){option++; if(option >= 3){option = 3;} delay(150);}
    if(digitalReadBTNDOWN()== "1"  ){option--; if(option <= 1){option = 1; } delay(150);}
    oled.display();
    }
    return desition;
}

void displayOtaProgramming(int progress){
  
    oled.setTextColor(WHITE);
    oled.clearDisplay();
    oled.setTextSize(2);  
    oled.setCursor(42, 0);    
    oled.print("OTA"); 
    oled.setTextSize(1);
    oled.setCursor (8, 20); oled.print("Waiting program"); 
    oled.setCursor (8, 36); oled.print("Progress: ");
    oled.setTextSize(2);
    oled.setCursor (80, 44); oled.print(String(progress) + "%");
    oled.display();
}

int displayWifiConfig() {
  
    int option = 3;
    int desition = 1;
    
    oled.setTextColor(WHITE);
    
    while(true){
      oled.clearDisplay(); 
      oled.setCursor(20, 0);    
      oled.setTextSize(2);     
      oled.print("MENU"); 
      oled.setTextSize(1);
      oled.setCursor (0, 28);  
      oled.print("Wifi");
      oled.setCursor (64, 20); oled.print("Name"); 
      oled.setCursor (64, 28); oled.print("Password"); 
      oled.setCursor (64, 36); oled.print("Local Ip");
      
      if(option == 3){oled.setCursor (58, 20); oled.print(">"); }
      if(option == 2){oled.setCursor (58, 28); oled.print(">"); }
      if(option == 1){oled.setCursor (58, 36); oled.print(">"); }
  
      //Serial.println("  LEFT "+digitalReadBTNLEFT()+"  RIGHT "+digitalReadBTNRIGHT()+"  UP "+digitalReadBTNUP()+"  DOWN "+digitalReadBTNDOWN());
      
      if(digitalReadBTNLEFT()== "1"  ){desition = 0;  delay(150); break;}
      if(digitalReadBTNRIGHT()== "1" ){desition = option; delay(150); break;}
      if(digitalReadBTNUP()== "1"    ){option++; if(option >= 3){option = 3;} delay(150);}
      if(digitalReadBTNDOWN()== "1"  ){option--; if(option <= 1){option = 1; } delay(150);}
      oled.display();
      }
      return desition;
  }

int displayWifiName() {
  
      int option = 1;
      int desition = 1;
      char wifiName[sizeof(memoryGetWifiName())];
      int i = 0;
      oled.setTextColor(WHITE);
      memoryGetWifiName().toCharArray(wifiName, sizeof(memoryGetWifiName())+3);
      
      while(true)
      {
          oled.clearDisplay();     
          oled.setCursor(20, 0);    
          oled.setTextSize(2);     
          oled.print("MENU"); 
          oled.setTextSize(1);
          oled.setCursor (0, 20);  
          oled.print("WifiName");
          oled.setCursor (0, 36);  
          oled.print(wifiName);
          oled.setCursor (i*6, 44);
          oled.print("^");
          if(digitalReadBTNDOWN() == "1"  ) { i = i-1;}
          if(digitalReadBTNUP() == "1"  ){ i = i+1;}
          if(digitalReadBTNRIGHT() == "1"  )   {wifiName[i] = wifiName[i]+1;
                                                  if(wifiName[i]>=126){wifiName[i] = 32;}}
          if(digitalReadBTNLEFT() == "1"  ) {option = 0; desition = option; delay(150); break;}
          oled.display();
          if(i<=0){i = 0;} if(i>=sizeof(wifiName)){i = sizeof(wifiName);}
          delay(150);
      }
        memorySetWifiName(String(wifiName));
        return desition;
    }

int displayWifiPassword() {
  
      int option = 1;
      int desition = 1;
      
      char wifiPassword[sizeof(memoryGetWifiPassword())];
      int i = 0;
      oled.setTextColor(WHITE);
      memoryGetWifiPassword().toCharArray(wifiPassword, sizeof(memoryGetWifiPassword())+3);
      
      while(true)
      {
          oled.clearDisplay();     
          oled.setCursor(20, 0);    
          oled.setTextSize(2);     
          oled.print("MENU"); 
          oled.setTextSize(1);
          oled.setCursor (0, 20);  
          oled.print("WifiPassword");
          oled.setCursor (0, 36);  
          oled.print(wifiPassword);
          oled.setCursor (i*6, 44);
          oled.print("^");
          if(digitalReadBTNDOWN() == "1"  ) { i = i-1;}
          if(digitalReadBTNUP() == "1"  ){ i = i+1;}
          if(digitalReadBTNRIGHT() == "1"  )   {wifiPassword[i] = wifiPassword[i]+1; 
                                                  if(wifiPassword[i]>=126){wifiPassword[i] = 32;}}
          if(digitalReadBTNLEFT() == "1"  ) {option = 0; desition = option; delay(150); break;}
          oled.display();
          if(i<=0){i = 0;} if(i>=sizeof(wifiPassword)){i = sizeof(wifiPassword);}
          delay(150);
      }
        memorySetWifiPassword(String(wifiPassword));
        return desition;
}

int displayLocalIp() {

      int option = 1;
      int desition = 1;
      
      oled.setTextColor(WHITE);
      
      while(true){
        oled.clearDisplay(); 
        oled.setCursor(20, 0);    
        oled.setTextSize(2);     
        oled.print("MENU"); 
        oled.setTextSize(1);
        oled.setCursor (0, 20);  
        oled.print("Local Ip");
        oled.setCursor (0, 36);  
        
        oled.setCursor(36, 36); oled.print(memoryGetLocalIp());
        if(digitalReadBTNLEFT() == "1"  ){desition = 0; delay(150); break;}
        oled.display();
        }
        return desition;
    }

int displayConfigurationProtocol() {
    
    int option = 2;
    int desition = 1;
    
    oled.setTextColor(WHITE);
    
    while(true){
      oled.clearDisplay(); 
      oled.setCursor(20, 0);    
      oled.setTextSize(2);     
      oled.print("MENU"); 
      oled.setTextSize(1);
      oled.setCursor (0, 28);  
      oled.print("Cfg");
      oled.setCursor (64, 20); oled.print("Websocket"); 
      oled.setCursor (64, 28); oled.print("Serial"); 
      
      if(option == 2){oled.setCursor (58, 20); oled.print(">"); }
      if(option == 1){oled.setCursor (58, 28); oled.print(">"); }
  
      if(digitalReadBTNLEFT()== "1"  ){option = 0; desition = option; delay(150); break;}
      if(digitalReadBTNRIGHT()== "1" ){desition = option; delay(150); break; }
      if(digitalReadBTNUP()== "1"    ){option++; if(option >= 2){option = 2;} delay(150);}
      if(digitalReadBTNDOWN()== "1"  ){option--; if(option <= 1){option = 1; } delay(150);}
      oled.display();
      }
      return desition;
}

int displayWebsocketConfig() {
      
      int option = 1;
      int desition = 1;
      
      oled.setTextColor(WHITE);
      
      while(true){
        oled.clearDisplay(); 
        oled.setCursor(20, 0);    
        oled.setTextSize(2);     
        oled.print("MENU"); 
        oled.setTextSize(1);
        oled.setCursor (0, 20);  
        oled.print("Link websocket config");
        oled.setCursor (0, 36); 
        
        oled.setCursor(30, 36); oled.print(memoryGetLocalIp());
        oled.setCursor( 0, 36); oled.print("ws://");
        
        if(digitalReadBTNLEFT() == "1"  ){desition = 0; delay(150); break;}
        oled.display();
        }
        return desition;
    }
    
int displaySerialConfig() {
      
      int option = 1;
      int desition = 1;
      int serialBaurate = memoryGetSerialBaudrate();
      
      if(serialBaurate == 9600)  {option = 5;}
      if(serialBaurate == 115200){option = 4;}
      if(serialBaurate == 256000){option = 3;}
      if(serialBaurate == 230400){option = 2;}
      if(serialBaurate == 512000){option = 1;}
      
      oled.setTextColor(WHITE);
      
      while(true){
        oled.clearDisplay(); 
        oled.setCursor(20, 0);    
        oled.setTextSize(2);     
        oled.print("MENU"); 
        oled.setTextSize(1);
        oled.setCursor (0, 20);  
        oled.print("Serial baudrate cfg");
        oled.setCursor (0, 36);  
        
        if(option == 5){oled.print("9600");}
        if(option == 4){oled.print("115200");}
        if(option == 3){oled.print("256000");}
        if(option == 2){oled.print("230400");}
        if(option == 1){oled.print("512000");}
        
        if(digitalReadBTNLEFT() == "1"  ){desition = 0; delay(150); break;}
        if(digitalReadBTNRIGHT()== "1" ){option = option + 1;   delay(150); }
        if(option == 6){option = 1;}
        oled.display();
        }
        if (option == 5){memorySetSerialBaudrate(9600);}
        if (option == 4){memorySetSerialBaudrate(115200);}
        if (option == 3){memorySetSerialBaudrate(256000);}
        if (option == 2){memorySetSerialBaudrate(230400);}
        if (option == 1){memorySetSerialBaudrate(512000);}
        return desition;
    }
    
#endif
