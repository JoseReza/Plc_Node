#include "plcNode.h"

int delay1 = 500;

void rutine(){
  turnQ4(1);
  delay(delay1);
  turnQ4(0);
  delay(delay1);
  turnQ3(1);
  delay(delay1);
  turnQ3(0);
  delay(delay1);
  turnQ2(1);
  delay(delay1);
  turnQ2(0);
  delay(delay1);
}