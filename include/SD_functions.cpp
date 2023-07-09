#include<Arduino.h>
#include<CAN.h>
#include<SD.h>
#include<EEPROM.h>
#include<FS.h>

void readFile(fs::FS &fs, const char * path){
    Serial.printf("Reading file: %s\n", path);
    File file = fs.open(path);
    if(!file){
        Serial.println("Failed to open file for reading");
        return;
    }
    Serial.print("Read from file: ");
    while(file.available()){
        Serial.write(file.read());
    }
    file.close();
}

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);
    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void appendFile(fs::FS &fs, const char * path, const char * message){
   // Serial.printf("Appending to file: %s\n", path);
    File file = fs.open(path, FILE_APPEND);
    if(!file){
       // Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print(message)){
        Serial.println("Data logged to SD card.");
    } else {
        Serial.println("Append failed");
    }
    file.close();
}

void startLog(){
    datalog = 1;
    filecreate = 1;
}

void setup_SD(){
    pinMode(sp,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(sp),startLog,FALLING);
}

void dataLogging(){
    if (datalog == 1){
        if (filecreate == 1){
            a=EEPROM.read(i);
            tempo = (int)a;
            tempo++;
            t = (String)tempo;
            const char* n = t.c_str();
            f= b+n+c;
            file_name = f.c_str() ;
            EEPROM.write(i,tempo);
            EEPROM.commit();
            SPI.end();
            spi->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);  
            if(!SD.begin(HSPI_SS,*spi)){
                Serial.println("Card Mount Failed");
                return;
            }
            uint8_t cardType = SD.cardType();
            if(cardType == CARD_NONE){
                Serial.println("No SD card attached");
                return;
            }   
            writeFile(SD, file_name, "Time,RPM,Temperature,Gear,SpeedRPM,Brake Pressure,Battery Voltage,Data Logging,Accelerometer X,Accelerometer Y\n");
            filecreate = 0;
        }
        String temp_SD = (String)temp ;
        String RPM_SD = (String)RPM ;
        String gear_SD = (String)gear;
        String speed_SD = (String)Speed;
        String speedRPM_SD = (String)SpeedRPM;
        String battery_SD = (String)volts;
        // String rad_SD = (String)radCheck;
        String data_SD = (String)datalog;
        String brake_SD = (String)brake;
        String accelx_SD = (String)g_x;
        String accely_SD = (String)g_y;
        String comma = "," ;
        String end = "\n";
        int m = millis();
        String mystr = m+comma+RPM_SD+comma+temp_SD+comma+gear_SD
                        +comma+comma+speedRPM_SD+comma+brake_SD+comma+battery_SD
                        +comma+data_SD+comma+accelx_SD+comma+accely_SD+end;
        const char * input = mystr.c_str();
        appendFile(SD, file_name, input);
        if(digitalRead(sp)==0){
        }
        else{
            datalog=0;
        }
    }
}