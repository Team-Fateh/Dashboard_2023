#include <varible_def.h>        //Include variables in each function.cpp file
                                //To avoid conflits #ifndef is used in variable.h
#include<Arduino.h>

#include<CAN.h>

void CAN_setup (long freq ){                            //Starts CAN & puts out message if CAN starting failed  
     if(!CAN.begin(freq)){                              //freq is the CAN freq 500E3 or 1000E3 etc
        //Serial.println("Starting CAN failed");
        CANstatus=0;
  }
    else{
        CANstatus=1;
    }
}





void CAN_get_data (){      //Puts data to the pointer 
    packetSize = CAN.parsePacket();                                     //returns 1 if packet received or else 0
    if(packetSize){
        hmiCANGreen();
        canLastTime = canThisTime;
        canThisTime = millis();
        packId = CAN.packetId();                                        //packetId is defined by Pe3 Standard Messages, follow link for more 
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
        RPM=((rMSB*255)+rLSB);       
        }

        //Temp packet
        if(packId==TEMPBATT_PKT_ID){     
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
        temp =((tMSB*256)+tLSB)*0.1;
        volts =((vMSB*256)+vLSB)*0.01;
        }
    }
}

