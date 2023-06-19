#include <varible_def.h>        //Include variables in each function.cpp file
                                //To avoid conflits #ifndef is used in variable.
#include<Arduino.h>
#include<CAN.h>

void CAN_setup (long freq ){                            //Starts CAN & puts out message if CAN starting failed  
     if(!CAN.begin(freq)){                              //freq is the CAN freq 500E3 or 1000E3 etc
        Serial.println("Starting CAN failed");
        CANstatus=0;
  }
    else{
        Serial.println("CAN Started");
        CANstatus=1;
    }
}

void CAN_get_data (int32_t *p_RPM, float *p_temp, float *p_volts){      //Puts data to the pointer 
    Serial.println("Can_get_data_called");
    packetSize = CAN.parsePacket();                                     //returns 1 if packet received or else 0
        Serial.print("Packet Size     ");
        Serial.println(packetSize);
    if(packetSize){
        Serial.println("Packet Received");
        packId = CAN.packetId();                                        //packetId is defined by Pe3 Standard Messages, follow link for more 
        Serial.print("Packet ID     ");
        Serial.println(packId);
        //RPM packet                                                    //https://github.com/Team-Fateh/ECU/blob/main/Documentation%20%26%20Resources/AN400_CAN_Protocol_C.pdf
        if(packId==RPM_PKT_ID){                                         //RPM_PKT_ID 218099784
        int d=0;
        while (CAN.available()) {
            if (d==0){                            //0th and 1st Byte are RPM data
                d++;
                rLSB=(int)CAN.read();
            }
            if (d==1){
                d++;
                rMSB=(int)CAN.read();
            }
            CAN.read(); d++;
        }
        *p_RPM=((rMSB*256)+rLSB);      
        Serial.print("RPM   ");
        Serial.println((rMSB*256)+rLSB); 
        }
        //Temp packet
        if(packId==TEMPBATT_PKT_ID){                                    //TEMPBATT_PKT_ID 218101064
            Serial.println("temp");
        int e=0;
        while (CAN.available()) {
            if (e==0){                            //0th and 1st Byte are voltage data
                e++;
                vLSB=(int)CAN.read();
            }
            if (e==1){
                e++;
                vMSB=(int)CAN.read();
            }
            if (e==4){                                 
                e++;
                tLSB=(int)CAN.read();             //4th & 5th Byte are temp data
            }
            if (e==5){
                e++;
                tMSB=(int)CAN.read();
            }
            CAN.read(); e++;
        }
        *p_temp =(((tMSB*256)+tLSB)*0.1);
        Serial.print("TEMP   ");
        Serial.println(((tMSB*256)+tLSB)*0.1); 
        *p_volts =((vMSB*256)+vLSB)*0.01;
        Serial.print("RPM   ");
        Serial.println(((vMSB*256)+vLSB)*0.01); 
        }
    }
}