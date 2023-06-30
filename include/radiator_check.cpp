#include <variable_def.h>
#include<Arduino.h>
#include<CAN.h>

void check_rad(){
    radCheck=digitalRead(radPin);
}