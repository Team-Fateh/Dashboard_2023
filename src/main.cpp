#include <Arduino.h>

//libraries
#include <CAN.h>

//Variables and function
#include <varible_def.h>
#include <can_bus.cpp>
#include <HMI.cpp>



void setup(){
  Serial.begin(115200);
  Serial2.begin(9600);
  }




void loop(){

if (CAN.begin(CAN_FREQ)) {
  hmiCANGreen(); // CAN connected 
  CAN_get_data(&RPM,&temp,&volts);
  HMI_print(4,RPM);
  HMI_print(5,temp);
  HMI_print(10,volts);
}

else{
  hmiCANRed(); //CAN failed 
}




}