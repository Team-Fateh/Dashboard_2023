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


void setup(){
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 26, 25);// rx tx
  Serial1.begin(230400, SERIAL_8N1, 33, 32); 
  CAN_setup(CAN_FREQ);
  LED_setup();
  }




void loop(){
  // Serial1.println("hello Bhorld");       // xbee check
  dur= pulseIn(18,HIGH);

  CAN_get_data(&RPM,&temp,&volts);

  send_xbee();

  if (millis() - canLastTime >=canTime){
    CAN_setup(CAN_FREQ);
  HMI_print(4,RPM);
  HMI_print(5,(int32_t)temp);
  HMI_print(10,volts);


  // Serial.println();
  canLastTime = millis();
  }


    gear2018();
    showLightDis();
  // delay(100);
}