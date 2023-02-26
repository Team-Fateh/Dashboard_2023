#include <varible_def.h>
#include <CAN.h>


void CAN_get_data (unsigned long int *RPM, float *temp, float *volts){
    packetSize = CAN.parsePacket();
    if(packetSize){

        //RPM packet
        if(packId==RPM_PKT_ID){      
        int d=0;
        while (CAN.available()) {
            if (d==0){
                d++;
                rLSB=(int)CAN.read();
            }
            if (d==1){
                d++;
                rMSB=(int)CAN.read();
            }
            CAN.read(); d++;
        }
        *RPM=((rMSB*255)+rLSB);       
        }

        //Temp packet
        if(packId==TEMPBATT_PKT_ID){    
        int e=0;
        while (CAN.available()) {
            if (e==0){
                e++;
                vLSB=(int)CAN.read();
            }
            if (e==1){
                e++;
                vMSB=(int)CAN.read();
            }
            if (e==4){                                 
                e++;
                tLSB=(int)CAN.read();              //4th & 5th Byte are tremp data
            }
            if (e==5){
                e++;
                tMSB=(int)CAN.read();
            }
            CAN.read(); e++;
        }

        *temp =((tMSB*255)+tLSB)*0.1;
        *volts =((vMSB*256)+vLSB)*0.01;






        }
    }
}