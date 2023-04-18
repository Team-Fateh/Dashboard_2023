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
#include <radiator_ckeck.cpp>

void setup(){
  Serial.begin(115200); // Serial monitor
  Serial2.begin(9600, SERIAL_8N1, 26, 25); //HMI Display connected at 26,25(rx.tx) pins
  Serial1.begin(230400, SERIAL_8N1, 33, 32);  // Xbee connected at 33,32(rx.tx) pins
  CAN_setup(CAN_FREQ);
  LED_setup();
  setup_speed();
  }




void loop(){
  dur= pulseIn(gearPin,HIGH);
  CAN_get_data(&RPM,&temp,&volts);  // can data
  send_xbee();                      // xbee data send 
  gear2018();  
  showLightDis();
  SpeedCount(SPEED_UPDATE_FREQ); // Speed refresh at 100 ms
  check_rad();
  Serial.println(radCheck);
  if (millis() - canLastTime >=canTime)  //refresh screen at canTime
  {
  HMI_print(4,RPM);
  HMI_print(5,(int32_t)temp);
  HMI_print(10,volts);
  HMI_print(6,(int32_t)Speed);
  canLastTime = millis();
  }
  
}