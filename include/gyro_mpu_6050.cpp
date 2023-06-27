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

float exponentialMovingAverage(float newValue)
{
  static float filteredValue = 0.0;  // Holds the filtered value

  filteredValue = (newValue * smoothingFactor) + (filteredValue * (1 - smoothingFactor));
  return filteredValue;
}


void dataMPU6050(){
    accelgyro.getAcceleration(&ax, &ay, &az);
    int16_t rawAcceleration[3];
   

   // Change this based on the axis you want to read
  totalX = totalX - readingsX[currentIndexX];  // Subtract the oldest reading
  readingsX[currentIndexX] = ax;       // Store the new reading
  totalX = totalX + readingsX[currentIndexX];  // Add the new reading

  totalY = totalY - readingsY[currentIndexY];  // Subtract the oldest reading
  readingsY[currentIndexY] = ay;       // Store the new reading
  totalY = totalY + readingsY[currentIndexY];

  currentIndexX++;
  if (currentIndexX >= numReadings) {
    currentIndexX = 0;
  }
currentIndexY++;
  if (currentIndexY >= numReadings) {
    currentIndexY = 0;
  }

  // Calculate the moving average
  float averageX = totalX / numReadings;
  float averageY = totalY / numReadings;
  float fax= exponentialMovingAverage(averageX);
  float fay= exponentialMovingAverage(averageY);
  g_x=(fax-ox)/16384;
  g_y=(fay-oy)/16384;
}