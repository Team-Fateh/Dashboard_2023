// // framework
#include <Arduino.h>
//libraries
#include <CAN.h>
#include <FastLED.h>
//Variables
#include <varible_def.h>
//functions
#include <HMI.cpp>
#include <can_bus.cpp>
#include <gear2018.cpp>
#include <RPM_led.cpp>
#include <xbee.cpp>
#include <speed.cpp>
#include <radiator_ckeck.cpp>
#include <gyro_mpu_6050.cpp>
#include <SD_functions.cpp>
#include <speedRPM.cpp>

void setup(){
  Serial.begin(115200); // Serial monitor
  Serial2.begin(9600, SERIAL_8N1, 26, 25); //HMI Display connected at 26,25(rx.tx) pins
  Serial1.begin(230400, SERIAL_8N1, 33, 32);  // Xbee connected at 33,32(rx.tx) pins
  EEPROM.begin(EEPROM_SIZE);
  setupSD();
  CAN_setup(CAN_FREQ);
  LED_setup();
  setupMPU6050();
  // setup_speed();
  }

void loop(){
  dataMPU6050();
  dur= pulseIn(gearPin,HIGH);
  gear2018();  
  CAN_get_data();  // can data
  // SpeedCount(SPEED_UPDATE_FREQ); // Speed refresh at 100 ms
  check_rad();
  showLightDis();
  speedRF();

  if (datalog == 1){
    if (filecreate == 1){
      a=EEPROM.read(i);
      tempo = (int)a;
      tempo++;
      t = (String)tempo;
      const char* n = t.c_str();
      f= b+n+c;
      file_name = f.c_str() ;
      EEPROM.write(i,tempo);
      EEPROM.commit();
      SPI.end();
      spi->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);  
      if(!SD.begin(HSPI_SS,*spi)){
        Serial.println("Card Mount Failed");
        return;
      }
      uint8_t cardType = SD.cardType();
      if(cardType == CARD_NONE){
        Serial.println("No SD card attached");
        return;
      }   
      writeFile(SD, file_name, "Time,RPM,Temp,Gear,Speed,Battery,Radiator,AccelerometerX,AccelerometerY\n");
      readFile(SD, file_name);
      filecreate = 0;
    }
    String end = "\n";
    String temp_SD = (String)temp ;
    String RPM_SD = (String)RPM ;
    String gear_SD = (String)gear;
    String speed_SD = (String)SpeedRPM;
    String battery_SD = (String)volts;
    String rad_SD = (String)radCheck;
    String accelx_SD = (String)g_x;
    String accely_SD = (String)g_y;
    String comma = "," ;
    int m = millis();
    String mystr = m+comma+RPM_SD+comma+temp_SD+comma+gear_SD+comma+speed_SD+comma+battery_SD+comma+rad_SD+comma+accelx_SD+comma+accely_SD+end;
    const char * input = mystr.c_str();
    appendFile(SD, file_name, input);
    if(digitalRead(sp)==0){
    }
    else{
      datalog=0;
    }
  }

  if (millis() - xbeeLastTime >= xbeeTime)  //refresh screen at canTime
  {
    send_xbee();                      // xbee data send
    HMI_print(4,RPM);
    HMI_print(5,(int32_t)temp);
    HMI_print(10,volts); 
    HMI_print(6,(int32_t)SpeedRPM);
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

  Serial.print(millis());
  Serial.print(",");
  Serial.print(RPM);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(gear);
  Serial.print(",");
  Serial.print(SpeedRPM);   //speed
  Serial.print(",");
  Serial.print(volts);
  Serial.print(",");
  Serial.print(radCheck);   //radiator
  Serial.print(",");
  Serial.print(g_x);   //accelerometer x-axis
  Serial.print(",");
  Serial.println(g_y);   //accelerometer y-axis
}

// #include <Wire.h>

// # define SDApin 21
// # define SCLpin 22

// void setup()
// {
//   Serial.begin (115200);
//   Wire.begin (SDApin, SCLpin);   // sda= GPIO_21 /scl= GPIO_22
// }

// void Scanner ()
// {
//   Serial.println ();
//   Serial.println ("I2C scanner. Scanning ...");
//   byte count = 0;

//   Wire.begin();
//   for (byte i = 8; i < 120; i++)
//   {
//     Wire.beginTransmission (i);        // Begin I2C transmission Address (i)
//     if (Wire.endTransmission () == 0)  // Receive 0 = success (ACK response)
//     {
//       Serial.print ("Found address: ");
//       Serial.print (i, DEC);
//       Serial.print (" (0x");
//       Serial.print (i, HEX);     // PCF8574 7 bit address
//       Serial.println (")");
//       count++;
//     }
//   }
//   Serial.print ("Found ");
//   Serial.print (count, DEC);        // numbers of devices
//   Serial.println (" device(s).");
// }

// void loop()
// {
//   Scanner ();
//   delay (100);
// }