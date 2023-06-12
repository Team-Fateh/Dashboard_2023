#include <FastLED.h>
#ifndef VARIBLE_CAN_H
#define VARIBLE_CAN_H
    // CAN bus varibales
    #define RPM_PKT_ID 218099784
    #define TEMPBATT_PKT_ID 218101064
    #define CAN_FREQ  1000E3
    #define SPEED_UPDATE_FREQ 100
    

    //can
    bool CANstatus;
    int32_t packId;
    int32_t packetSize;

    int32_t rMSB=0,rLSB=0;
    int32_t tMSB=0,tLSB=0;
    int32_t vMSB=0,vLSB=0;
    int32_t RPM;
    float temp;
    float volts;
    long unsigned int canThisTime = 0, canLastTime = 0, canCheckTime = 1000;

    //hmi
    long unsigned int hmiLastTime = 0, hmiTime = 500;

    //xbee
    long unsigned int xbeeLastTime = 0, xbeeTime = 50;

    //Radiator check
    bool radCheck;
    #define radPin 21
    
    //gear
    int dur;
    char gear;
    #define gearPin 18

    //RPM led
    #define led_num  18
    #define ledPin  23
    CRGB leds[led_num];          
    int light=0;
    int ledDur,ledOldDur,red;
    char comm;

    //speed
    volatile unsigned int totalCounts;
    #define speedPin 22    //front right
    #define slits 28   //Front wheel
    int lastTime=0;      
    float Speed;      

    //Gyro MPU6050
    int16_t ax, ay, az;
    float g_x, g_y, g_z;
    int ox=220;
    int oy=-260;
    int oz=0;
    #define OUTPUT_READABLE_ACCELGYRO  

#endif