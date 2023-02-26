#ifndef VARIBLE_DEF_H
#define VARIBLE_DEF_H

    // CAN bus varibales
    #define RPM_PKT_ID 218099784
    #define TEMPBATT_PKT_ID 218101064
    #define CAN_FREQ  1000E3

    int rMSB=0,rLSB=0;
    int tMSB=0,tLSB=0;
    int vMSB=0,vLSB=0;
    unsigned long RPM;
    float temp;
    float volts;
    long packId;
    int packetSize;


#endif