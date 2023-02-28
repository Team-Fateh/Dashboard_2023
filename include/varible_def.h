#ifndef VARIBLE_CAN_H
#define VARIBLE_CAN_H
    // CAN bus varibales
    #define RPM_PKT_ID 218099784
    #define TEMPBATT_PKT_ID 218101064
    #define CAN_FREQ  500E3

    bool CANstatus;
    int32_t packId;
    int32_t packetSize;

    int8_t rMSB=0,rLSB=0;
    int8_t tMSB=0,tLSB=0;
    int8_t vMSB=0,vLSB=0;
    int32_t RPM;
    float temp;
    float volts;
#endif