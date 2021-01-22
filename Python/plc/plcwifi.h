#ifndef wifi_h
#define wifi_h

#include "WiFi.h"


char wifiname[20] = "FAMILIA ORTIZ";
char wifipassword[20] = "WIFINODE";
String localIp; 

void wifiConnect()
{  
  Serial.println("wifiConnect function executing on core: " + String(xPortGetCoreID()));
  Serial.println("wifiname: " + String(wifiname));
  Serial.println("wifipassword: " + String(wifipassword));
  Serial.println("Connecting");  

  memoryGetWifiName().toCharArray(wifiname,20);
  memoryGetWifiPassword().toCharArray(wifipassword,20);
  WiFi.begin(wifiname, wifipassword);

  while ( WiFi.status() != WL_CONNECTED )
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("Connected!");
  Serial.print("PLCNODE IP address: ");
  localIp = WiFi.localIP().toString();
  Serial.println("Local ip: " + localIp);
  memorySetLocalIp(localIp);
}

void wifiAPConnect()
{
  Serial.println("wifiAPConnect function executing on core: " + String(xPortGetCoreID()));
  Serial.println("wifiAPname: " + String(wifiname));
  Serial.println("wifiAPpassword: " + String(wifipassword));
  Serial.println("Connecting");

  memoryGetWifiName().toCharArray(wifiname,20);
  memoryGetWifiPassword().toCharArray(wifipassword,20);
  WiFi.softAP(wifiname, wifipassword);
  
  Serial.println("Connected!");
  Serial.print("PLCNODE IP address: ");
  localIp = WiFi.softAPIP().toString();
  Serial.println("Local ip: " + localIp);
  memorySetLocalIp(localIp);
}

#endif
