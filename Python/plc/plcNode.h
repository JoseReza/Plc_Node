#ifndef PlcNode_h
#define PlcNode_h

#include "Ticker.h"
#include "plcmemory.h"
#include "plcinputsandoutputs.h"
#include "plcserial.h"
#include "plcdisplay.h"
#include "plcwebsockets.h"
#include "plcwifi.h"
#include "plcotaprogramming.h"
#include "plcmenu.h"

void plcNodeStart()
{
     //memorySetSerialBaudrate(115200);
    //memorySetWifiName(wifiname);                      // Initiators of memory eeprom
    //memorySetWifiPassword(wifipassword);
    //memorySetLocalIp(192, 168, 0, 10);
  
  serialStart();              // Obligatory
  inputandoutputsStart();     // Obligatory
  displayStart();             // Obligatory
  displayPresentation();      // Obligatory
  displayTest();
  executeMenu();              // Obligatory
  
  if(memoryGetWifiMode() == 2){wifiAPConnect(); }         // Wifi Acces point mode
  if(memoryGetWifiMode() == 1){wifiConnect(); }           // Wifi Client mode
  if(otaProgramming == true){otaStart();}
  
  toggleINDICATORLED(1);
  
  if(memoryGetProtocolMode() == 2){websocketLoopStart(1);} // Listenning via websockets for commands for PLC NODE // 1 to start // 0 to end
  if(memoryGetProtocolMode() == 1){serialLoopStart(1);}    // Listenning via serial for commands for PLC NODE // 1 to start // 0 to end  
}

int plcNodeRunning()
{
  if(digitalReadBTNLEFT()== "1"){ESP.restart();turnINDICATORLED(0); }
  if(otaProgramming == true){otaLoop(); return false;}
  if(otaProgramming == false){displayExecuting(); return true;}
}

#endif
