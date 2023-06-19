#include <varible_def.h>        //Include variables in each function.cpp file
                                //To avoid conflits #ifndef is used in variable.h
#include<Arduino.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif
MPU6050 accelgyro;

void setupMPU6050(){
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    accelgyro.initialize();
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void dataMPU6050(){
    accelgyro.getAcceleration(&ax, &ay, &az);
    g_x=float(ax-ox)/16384;
    g_y=float(ay-oy)/16384;
    g_z=float(az-oz)/16384;
    #ifdef OUTPUT_READABLE_ACCELGYRO
    #endif
}