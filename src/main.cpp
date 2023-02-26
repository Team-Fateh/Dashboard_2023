#include <Arduino.h>
//libraries
#include <CAN.h>

//Variables and function
#include <varible_def.h>




void setup() {
  Serial.begin(115200);

  if (!CAN.begin(CAN_FREQ)) {
    Serial.println("CAN failed!");
    while (1); // if failed stuck in this loop
  }
}




void loop() {

  int packetSize = CAN.parsePacket();
  if (packetSize) {
  long packId = CAN.packetId();
    if(packId==RPM_PKT_ID){      
      int d=0;
      while (CAN.available()) {
        if (d==0){
          d++;
          LSB=(int)CAN.read();
        }
        if (d==1){
          d++;
          MSB=(int)CAN.read();
        }
          CAN.read(); d++;
      }
      RPM=((MSB*255)+LSB);       

      Serial.println(RPM);
      Serial.println();
    
    }

    if(packId==TEMP_PKT_ID){    
    
      int e=0;
      while (CAN.available()) {
        
        
        if (e==4){
          e++;
          tLSB=(int)CAN.read();
        }
        if (e==5){
          e++;
          tMSB=(int)CAN.read();
        }
          CAN.read(); e++;
      }

      temp=((tMSB*255)+tLSB)*0.1;
      Serial.print(temp);
      Serial.println();
      Serial.print(tMSB);
      Serial.print("    ");
      Serial.print(tLSB);  
    }
    Serial.println();
  }
 
}