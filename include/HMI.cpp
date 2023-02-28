#include <varible_def.h>
void HMI_print(int placeholder, int32_t value){
    Serial2.print("t");
    Serial2.print(placeholder);
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print(value);
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

}

void HMI_print(int placeholder, float value){
    Serial2.print("t");
    Serial2.print(placeholder);
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print(value);
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

}

void hmiCANRed(){
    Serial2.print("r1.pco=");       
    Serial2.print("63488");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.print("r1.bco=");       
    Serial2.print("63488");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

    Serial2.print("t1");           //63488 Red colour
    Serial2.print(".");
    Serial2.print("pco");
    Serial2.print("=");
    Serial2.print("63488");
    Serial2.write(0xff);
    Serial2.write(0xff);
    
}

void hmiCANGreen(){
    Serial2.print("r1.pco=");       
    Serial2.print("1024");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.print("r1.bco=");       
    Serial2.print("1024");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

    Serial2.print("t1");          //1024 Green colour
    Serial2.print(".");
    Serial2.print("pco");
    Serial2.print("=");
    Serial2.print("1024");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
}