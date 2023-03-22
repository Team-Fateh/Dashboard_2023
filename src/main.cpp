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
  dur= pulseIn(18,HIGH);

  CAN_get_data(&RPM,&temp,&volts);
  Serial.print(millis());
  Serial.print(RPM);
  Serial.print("\t");
  Serial.print(temp);
  Serial.print("\t");
  Serial.println(volts);

  HMI_print(4,RPM);
  HMI_print(5,(int32_t)temp);
  HMI_print(10,volts);



    if(dur>=700&&dur<=900)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("1");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }

    if(dur>=920&&dur<=1200)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("N");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }

    if(dur>=1220&&dur<=1500)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("2");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }

    if(dur>=1520&&dur<=2000)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("3");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }


    if(dur>=2020&&dur<=2500)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("4");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }

    if(dur>=2520&&dur<=3000)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("5");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }
    
    if(dur>=3020&&dur<=3500)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("6");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }
  delay(100);
}