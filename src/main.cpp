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
  CAN.begin(CAN_FREQ);
  }




void loop(){

  hmiCANGreen(); // CAN connected 
  CAN_get_data(&RPM,&temp,&volts);
  Serial.println(RPM);
  HMI_print(4,RPM);
  HMI_print(5,temp);
  HMI_print(10,volts);
  


  hmiCANRed(); //CAN failed 





}