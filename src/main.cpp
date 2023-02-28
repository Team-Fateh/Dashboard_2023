//framework
#include <Arduino.h>

//libraries
#include <CAN.h>

//Variables
#include <varible_def.h>
//functions
#include <can_bus.cpp>
#include <HMI.cpp>



void setup(){
  Serial.begin(115200);
  Serial2.begin(9600);
  CAN_setup(CAN_FREQ);
  }




void loop(){

  CAN_get_data(&RPM,&temp,&volts);
  Serial.println(RPM);
  Serial.print(temp);
  Serial.print("\t");
  Serial.println(volts);
  
}