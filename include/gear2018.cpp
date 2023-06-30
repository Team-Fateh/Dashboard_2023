#include <variable_def.h>
#include<Arduino.h>
#include<CAN.h>

void gear2018(){
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
        gear ='1';
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
        gear ='N';
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
        gear ='2';
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
        gear ='3';
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
        gear ='4';
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
        gear ='5';
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
        gear ='6';
    }
} 