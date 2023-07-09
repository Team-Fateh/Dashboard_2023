#include<Arduino.h>
#include <variable_def.h>

void speedRF(){
    if(gear == 'N'){
        SpeedRPM = 0.0;
    }
    if(gear == '1'){
        wheelRPM = RPM/(22.203);
        SpeedRPM = wheelRPM*0.08618;
    }
    if(gear == '2'){
        wheelRPM = RPM/(15.467);
        SpeedRPM = wheelRPM*0.08618;
    }
    if(gear == '3'){
        wheelRPM = RPM/(11.808);
        SpeedRPM = wheelRPM*0.08618;
    }
    if(gear == '4'){
        wheelRPM = RPM/(9.480);
        SpeedRPM = wheelRPM*0.08618;
    }
    if(gear == '5'){
        wheelRPM = RPM/(7.983);
        SpeedRPM = wheelRPM*0.08618;
    }
    if(gear == '6'){
        wheelRPM = RPM/(6.985);
        SpeedRPM = wheelRPM*0.08618;
    }
}