#ifndef inputsandoutputs_h
#define inputsandoutputs_h

#include "Ticker.h"

String I0State = "0";
String I1State = "0";
String I2State = "0";
String I3State = "0";
String I4State = "0";
String I5State = "0";
String BTNLEFTState = "0";
String BTNRIGHTState = "0";
String BTNUPState = "0";
String BTNDOWNState = "0";

String Q0State = "0";
String Q1State = "0";
String Q2State = "0";
String Q3State = "0";
String Q4State = "0";
String Q5State = "0";
bool INDICATORLEDState = 0;

byte I0 = 36;
byte I1 = 39;
byte I2 = 34;      //Inputs PLC
byte I3 = 35;
byte I4 = 32;
byte I5 = 33;
byte BTNLEFT   = 26;
byte BTNRIGHT  = 27;    //Bottons for screen OLED_I2C
byte BTNUP     = 14;
byte BTNDOWN   = 12;

byte Q0 = 23;
byte Q1 = 19;
byte Q2 = 18;
byte Q3 = 5;     //Outputs PLC
byte Q4 = 4;
byte Q5 = 15;
byte INDICATORLED = 2;

void inputandoutputsStart() {
  
  pinMode(I0, INPUT);
  pinMode(I1, INPUT);
  pinMode(I2, INPUT);
  pinMode(I3, INPUT);
  pinMode(I4, INPUT);
  pinMode(I5, INPUT);  
  pinMode(BTNLEFT, INPUT);
  pinMode(BTNRIGHT, INPUT);
  pinMode(BTNUP, INPUT);
  pinMode(BTNDOWN, INPUT);
  
  pinMode(Q0, OUTPUT);
  pinMode(Q1, OUTPUT);
  pinMode(Q2, OUTPUT);
  pinMode(Q3, OUTPUT);
  pinMode(Q4, OUTPUT);
  pinMode(Q5, OUTPUT);
  pinMode(INDICATORLED, OUTPUT);

}

void turnQ0(bool state)
{
  if (state == 0) {
    digitalWrite(Q0, 0);
    Q0State = "0";
  } if (state == 1) {
    digitalWrite(Q0, 1);
    Q0State = "1";
  }
}
void turnQ1(bool state)
{
  if (state == 0) {
    digitalWrite(Q1, 0);
    Q1State = "0";
  } if (state == 1) {
    digitalWrite(Q1, 1);
    Q1State = "1";
  }
}
void turnQ2(bool state)
{
  if (state == 0) {
    digitalWrite(Q2, 0);
    Q2State = "0";
  } if (state == 1) {
    digitalWrite(Q2, 1);
    Q2State = "1";
  }
}
void turnQ3(bool state)
{
  if (state == 0) {
    digitalWrite(Q3, 0);
    Q3State = "0";
  } if (state == 1) {
    digitalWrite(Q3, 1);
    Q3State = "1";
  }
}
void turnQ4(bool state)
{
  if (state == 0) {
    digitalWrite(Q4, 0);
    Q4State = "0";
  } if (state == 1) {
    digitalWrite(Q4, 1);
    Q4State = "1";
  }
}
void turnQ5(bool state)
{
  if (state == 0) {
    digitalWrite(Q5, 0);
    Q5State = "0";
  } if (state == 1) {
    digitalWrite(Q5, 1);
    Q5State = "1";
  }
}

void turnINDICATORLED(bool state)
{
  if (state == true) {
    digitalWrite(INDICATORLED, HIGH);
    INDICATORLEDState = "1";
  } if (state == false) {
    digitalWrite(INDICATORLED, LOW);
    INDICATORLEDState = "0";
  }
}

Ticker asynchronusTask3;
bool _state = false;

void togglingINDICATORLED()
{
  _state = !_state;
  if (_state == true) {
    turnINDICATORLED(1);
  } else {
    turnINDICATORLED(0);
  }
}

void toggleINDICATORLED(bool state)
{
  if (state == true) {
    asynchronusTask3.attach(1.5, togglingINDICATORLED); //Start task3 to executing of a asynchronus way
  } if (state == false) {
    asynchronusTask3.detach(); //End task3 to executing of a asynchronus way
  }
}


String digitalReadI0() {
  I0State = String(digitalRead(I0));
  return I0State;
}
String digitalReadI1() {
  I1State = String(digitalRead(I1));
  return I1State;
}
String digitalReadI2() {
  I2State = String(digitalRead(I2));
  return I2State;
}
String digitalReadI3() {
  I3State = String(digitalRead(I3));
  return I3State;
}
String digitalReadI4() {
  I4State = String(digitalRead(I4));
  return I4State;
}
String digitalReadI5() {
  I5State = String(digitalRead(I5));
  return I5State;
}

String digitalReadQ0() {
  return Q0State;
}
String digitalReadQ1() {
  return Q1State;
}
String digitalReadQ2() {
  return Q2State;
}
String digitalReadQ3() {
  return Q3State;
}
String digitalReadQ4() {
  return Q4State;
}
String digitalReadQ5() {
  return Q5State;
}

String analogReadI0() {
  String n = "";
  n = String((analogRead(I0)*100)/4095);
  return n;
}
String analogReadI1() {
  String n = "";
  n = String((analogRead(I1)*100)/4095);
  return n;
}
String analogReadI2() {
  String n = "";
  n = String((analogRead(I2)*100)/4095);
  return n;
}
String analogReadI3() {
  String n = "";
  n = String((analogRead(I3)*100)/4095);
  return n;
}
String analogReadI4() {
  String n = "";
  n = String((analogRead(I4)*100)/4095);
  return n;
}
String analogReadI5() {
  String n = "";
  n = String((analogRead(I5)*100)/4095);
  return n;
}

String digitalReadBTNLEFT() {
  BTNLEFTState = String(digitalRead(BTNLEFT));
  return BTNLEFTState;
}
String digitalReadBTNRIGHT() {
  BTNRIGHTState = String(digitalRead(BTNRIGHT));
  return BTNRIGHTState;
}
String digitalReadBTNUP() {
  BTNUPState = String(digitalRead(BTNUP));
  return BTNUPState;
}
String digitalReadBTNDOWN() {
  BTNDOWNState = String(digitalRead(BTNDOWN));
  return BTNDOWNState;
}

#endif
