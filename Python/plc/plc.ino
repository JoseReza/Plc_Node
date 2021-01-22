#include "rutine.h"


void setup() 
{
 plcNodeStart();
}

void loop() 
{
 if(plcNodeRunning())
 {
  rutine();
 }
  
}
