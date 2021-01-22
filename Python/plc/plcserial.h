#ifndef serial_h
#define serial_h

#include "Ticker.h"

String _serialPayload;
byte banner2 = 0;

void serialStart(){
  
  Serial.begin(memoryGetSerialBaudrate());
}

void serialLoop(){
  
  if(banner2==0){banner2 = 1;Serial.println("serialLoop function executing on core: " + String(xPortGetCoreID()));}
  
  if(Serial.available() > 0){
    
    _serialPayload = _serialPayload + (char)Serial.read();
    Serial.println("Recibido: " + _serialPayload);
    
      if (_serialPayload=="Q0:1"){turnQ0(1);}
      if (_serialPayload=="Q0:0"){turnQ0(0);}
      if (_serialPayload=="Q1:1"){turnQ1(1);}
      if (_serialPayload=="Q1:0"){turnQ1(0);}
      if (_serialPayload=="Q2:1"){turnQ2(1);}
      if (_serialPayload=="Q2:0"){turnQ2(0);}
      if (_serialPayload=="Q3:1"){turnQ3(1);}
      if (_serialPayload=="Q3:0"){turnQ3(0);}  
      if (_serialPayload=="Q4:1"){turnQ4(1);}
      if (_serialPayload=="Q4:0"){turnQ4(0);}
      if (_serialPayload=="Q5:1"){turnQ5(1);}
      if (_serialPayload=="Q5:0"){turnQ5(0);}
      
      if (_serialPayload=="I0:"){_serialPayload = "I0:" + digitalReadI0(); Serial.println(_serialPayload);}
      if (_serialPayload=="I1:"){_serialPayload = "I1:" + digitalReadI1(); Serial.println(_serialPayload);}
      if (_serialPayload=="I2:"){_serialPayload = "I2:" + digitalReadI2(); Serial.println(_serialPayload);}
      if (_serialPayload=="I3:"){_serialPayload = "I3:" + digitalReadI3(); Serial.println(_serialPayload);}
      if (_serialPayload=="I4:"){_serialPayload = "I4:" + digitalReadI4(); Serial.println(_serialPayload);}
      if (_serialPayload=="I5:"){_serialPayload = "I5:" + digitalReadI5(); Serial.println(_serialPayload);}
    }
  else {
    _serialPayload = "";
  }
}

Ticker asynchronusTask2;

void serialLoopStart(bool state){
  if(state == true){
  Serial.println("serialBegin function executing on core: " + String(xPortGetCoreID()));
  asynchronusTask2.attach(.001, serialLoop); //Start task2 to executing of a asynchronus way
  }
  else {
  asynchronusTask2.detach(); //End task1 to executing of a asynchronus way
  banner2 = 0;
  }
}

#endif
