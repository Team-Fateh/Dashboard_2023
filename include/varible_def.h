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
    #define gearPin 19\

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

    //SD_CARD
    #define EEPROM_SIZE 10  
    #define HSPI_MISO   13
    #define HSPI_MOSI   12
    #define HSPI_SCLK   14
    #define HSPI_SS     15
    #include<SPI.h>
    SPIClass *spi = new SPIClass(HSPI);
    String f;
    String b = "/Data";
    String c= ".txt";
    String mystr;
    String t ;
    int i=0;
    int sp = 27;
    int count = 0;
    int vari =0;
    int sv=0;
    int tempo;
    const char * file_name;
    const char* n;
    const char* input;
    char a ;
    int filecreate = 0;
    int datalog = 0;

    //SpeedRPM
    #define fdr 3.118    //Final Drive Rtaio
    #define pgr 2.667    //Primary Gear Ratio
    #define gr1 2.67
    #define gr2 1.86
    #define gr3 1.42
    #define gr4 1.14
    #define gr5 0.96
    #define gr6 0.84
    #define td 49.022    //Tire dia of Housier 19.3 inches
    float SpeedRPM = 0.0;
    float wheelRPM = 0.0;

#endif