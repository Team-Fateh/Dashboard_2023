// // framework
#include <Arduino.h>
//libraries
#include <CAN.h>
#include <FastLED.h>
//Variables
#include <variable_def.h>
//functions
#include <HMI.cpp>
#include <can_bus.cpp>
#include <gear2018.cpp>
#include <RPM_led.cpp>
#include <xbee.cpp>
#include <speed.cpp>
#include <radiator_check.cpp>
#include <gyro_mpu_6050.cpp>
#include <SD_functions.cpp>
#include <speedRPM.cpp>

void setup(){
  EEPROM.begin(EEPROM_SIZE);
  Serial.begin(115200); // Serial monitor
  Serial2.begin(9600, SERIAL_8N1, 26, 25); //HMI Display connected at 26,25(rx.tx) pins
  Serial1.begin(230400, SERIAL_8N1, 33, 32);  // Xbee connected at 33,32(rx.tx) pins
  CAN_setup(CAN_FREQ);
  setup_SD();
  LED_setup();
  setup_MPU6050();
  setup_speed();
  }

void loop(){
  data_MPU6050();
  dur= pulseIn(gearPin,HIGH);
  gear2018();  
  CAN_get_data();  // can data
  SpeedCount(SPEED_UPDATE_FREQ); // Speed refresh at 100 ms
  // check_rad();
  showLightDis();
  speedRF();
  if(gear=='N'||((gear=='1' || gear =='2') && RPM<2700)){
    Speed=0.0;
  }
  dataLogging();

  if (millis() - xbeeLastTime >= xbeeTime)  //refresh screen at canTime
  {
    send_xbee();                      // xbee data send
    HMI_print(4,RPM);
    HMI_print(5,(int32_t)temp);
    HMI_print(10,volts); 
    HMI_print(6,(int32_t)Speed);
    xbeeLastTime = millis();
  }

  if (millis() - hmiLastTime >= hmiTime)  //refresh screen at canTime
  {
    CAN.end();
    CAN.begin(CAN_FREQ);
    hmiLastTime = millis(); 
  }

  if (canThisTime - canLastTime >= canCheckTime)  //refresh screen at canTime
  {
    hmiCANRed();
  }
}

