#ifndef websockets_h
#define websockets_h

#include "WebSocketsServer.h" //We must to install "websockets" library made by Markus Sattler, this library
WebSocketsServer webSocket = WebSocketsServer(80);// can be found in "library mangement" of Arduino IDE
#include <Ticker.h>

char payload;
String _websocketPayload;
uint8_t _num;
IPAddress remoteIp;
     

void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  Serial.println("onWebSocketEvent function executing on core: " + String(xPortGetCoreID()));
  switch (type)
  {
    // Client has disconnected
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;

    // New client has connected
    case WStype_CONNECTED:
      {
        remoteIp = webSocket.remoteIP(num);
        Serial.printf("[%u] Connection from ", num);
        _num = num;
        Serial.println(remoteIp);
        Serial.println("Remote IP: "+String(remoteIp));
      }
      break;

    // Echo text message back to client
    case WStype_TEXT:
      Serial.printf("[%u] Text: %s\n", num, payload);
      _websocketPayload = "";
      for (int i = 0; i < sizeof(payload); i++) {
      _websocketPayload = _websocketPayload + char(payload[i]);
      }
      Serial.println(_websocketPayload);
      break;

    // For everything else: do nothing
    case WStype_BIN:
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}


byte banner1 = 0;

void websocketLoop(){
  
  if(banner1==0){
  Serial.println("websocketLoop function executing on core: " + String(xPortGetCoreID()));
  banner1 = 1;
  }
   webSocket.loop();
  
  if (_websocketPayload=="Q0:1"){turnQ0(1);}
  if (_websocketPayload=="Q0:0"){turnQ0(0);}
  if (_websocketPayload=="Q1:1"){turnQ1(1);}
  if (_websocketPayload=="Q1:0"){turnQ1(0);}
  if (_websocketPayload=="Q2:1"){turnQ2(1);}
  if (_websocketPayload=="Q2:0"){turnQ2(0);}
  if (_websocketPayload=="Q3:1"){turnQ3(1);}
  if (_websocketPayload=="Q3:0"){turnQ3(0);}  
  if (_websocketPayload=="Q4:1"){turnQ4(1);}
  if (_websocketPayload=="Q4:0"){turnQ4(0);}
  if (_websocketPayload=="Q5:1"){turnQ5(1);}
  if (_websocketPayload=="Q5:0"){turnQ5(0);}
  
  if (_websocketPayload=="I0:"){_websocketPayload = "I0:" + digitalReadI0(); webSocket.sendTXT(_num,_websocketPayload);}
  if (_websocketPayload=="I1:"){_websocketPayload = "I1:" + digitalReadI1(); webSocket.sendTXT(_num,_websocketPayload);}
  if (_websocketPayload=="I2:"){_websocketPayload = "I2:" + digitalReadI2(); webSocket.sendTXT(_num,_websocketPayload);}
  if (_websocketPayload=="I3:"){_websocketPayload = "I3:" + digitalReadI3(); webSocket.sendTXT(_num,_websocketPayload);}
  if (_websocketPayload=="I4:"){_websocketPayload = "I4:" + digitalReadI4(); webSocket.sendTXT(_num,_websocketPayload);}
  if (_websocketPayload=="I5:"){_websocketPayload = "I5:" + digitalReadI5(); webSocket.sendTXT(_num,_websocketPayload);}
}

Ticker asynchronusTask1;

void websocketLoopStart(bool state) {
  
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
  
  if(state == true){
  Serial.println("websocketBegin function executing on core: " + String(xPortGetCoreID()));
  asynchronusTask1.attach(.001, websocketLoop); //Start task1 to executing of a asynchronus way
  }
  else {
  asynchronusTask1.detach(); //End task1 to executing of a asynchronus way
  banner1 = 0;
  }
}

#endif
