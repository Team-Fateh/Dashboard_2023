//framework
#include <Arduino.h>

//libraries
#include <CAN.h>
#include <FastLED.h>
//Variables
#include <varible_def.h>
//functions
#include <can_bus.cpp>
#include <HMI.cpp>
#include <gear2018.cpp>
#include <RPM_led.cpp>
#include <xbee.cpp>
#include <speed.cpp>

void setup(){
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 26, 25);// rx tx
  Serial1.begin(230400, SERIAL_8N1, 33, 32); 
  CAN_setup(CAN_FREQ);
  LED_setup();
  setup_speed();
  }




void loop(){

  // dur= pulseIn(18,HIGH);            // gear time

  CAN_get_data(&RPM,&temp,&volts);  // can data

  send_xbee();                      // xbee data send

  if (millis() - canLastTime >=canTime){
    // CAN_setup(CAN_FREQ);
  HMI_print(4,RPM);
  HMI_print(5,(int32_t)temp);
  HMI_print(10,volts);
  HMI_print(6,(int32_t)Speed);
  canLastTime = millis();
  }
    gear2018();
    showLightDis();

  startCount(100);
 Serial.println("now");
}