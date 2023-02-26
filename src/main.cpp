#include <Arduino.h>

//libraries
#include <CAN.h>

//Variables and function
#include <varible_def.h>

#include <can_bus.cpp>




void setup(){
  Serial.begin(115200);

  if (!CAN.begin(CAN_FREQ)) {
    //hmi_red
  }
}




void loop(){

CAN_get_data(&RPM,&temp,&volts);
  
 
}