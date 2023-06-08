#include <varible_def.h>
#include<Arduino.h>
#include<CAN.h>

void speedISR()
{
  totalCounts++;
}
void setup_speed(){
    pinMode(speedPin,INPUT);
    attachInterrupt(digitalPinToInterrupt(speedPin),speedISR,FALLING);
}

void SpeedCount(unsigned long period)
{
  if(millis()-lastTime<period)
  return;
  Speed=((totalCounts*5032.832)/period)/slits;    //Speed=((totalCounts/slits)*(pi*(Wheel dia)/100)*3.6)/(period/1000) 
  lastTime=millis();                              // where wheel dia=44.5 cm ,
  totalCounts=0;
}

