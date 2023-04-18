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

void startCount(int period)
{
  if(millis()-lastTime<period)
  return;
  Speed=((totalCounts*5032.832)/period)/slits;   
  Serial.println(Speed);
  //Serial.println(digitalRead(totalCounts));
  lastTime=millis();
  totalCounts=0;
}
