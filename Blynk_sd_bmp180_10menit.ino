#include <Wire.h> 
#include <SPI.h>
#include <SD.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>
#include <SFE_BMP180.h>
#include <RtcDS1307.h>
#define BLYNK_PRINT Serial 
#define countof(a) (sizeof(a) / sizeof(a[0]))
#define IN_VALVE 2
#define OUT_VALVE 3

 //save interval//
#define saveInterval 60

char datestring[20];
const uint8_t chipSelect = SS;
//measurements taken at r_0 (sea level)
const float station_elev = 00.0; // station elevation (KNYC used here)
const float p_0 = 1017.3 * 100.0;
int Altitude = 190;/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

extern uint8_t SmallFont[];
extern unsigned char TinyFont[];

int counter = 0;

//create an BMP180 object using the I2C interface
SFE_BMP180 bmp180;
//Adafruit_BMP085 bmp180;
const char data[] = "what time is it";
RtcDS1307<TwoWire> Rtc(Wire);
#define TCAADDR 0x70

int analogPin= A0;
byte button1INT = 0; 
int valMultiplier = 10;

double P1,P2,P3,P4,P5,P6,P7,P8;
float temp_1,temp_2,temp_3;

char auth[] = "zwzxldZ_RPum_0BlstggNk0HUb-Ec-2C";

// Your WiFi credentials.

// Set password to "" for open networks.
//char ssid[] = "4G-UFI-2286";
//char pass[] = "1234567890";
char ssid[] = "I-O-T";
char pass[] = "*1234567890*";
//char ssid[] = "POCO";
//char pass[] = "a12345678";
//char ssid[] = "ichigo";
//char pass[] = "limolas99";
//char ssid[] = "EMOBILE-GL09P-BF27";
//char pass[] = "32243455";

ADC_MODE(ADC_VCC);

char filename[] = "YYYYMMDD_HHMM_XX.CSV";
void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission(); 
} 

BlynkTimer timer;
void sendSensor()
{
 // Read BMP180 Sensor #1   
 tcaselect(0);{
  char status;
  double T, P;
  status = bmp180.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp180.getTemperature(T);
    if (status != 0)
    {
      status = bmp180.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = bmp180.getPressure(P, T);
        delay(100);
        if (status != 0)
        {
          P1 = P;
        }
        else P1 = 0;
      }
      else P1 = 0;
    }
    else P1 = 0;
  }
  }

  // Read BMP180 Sensor #2  
 tcaselect(1);{
  char status;
  double T, P;
  status = bmp180.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp180.getTemperature(T);
    if (status != 0)
    {
      status = bmp180.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = bmp180.getPressure(P, T);
        delay(100);
        if (status != 0)
        {
          P2 = P;
        }
        else P2 = 0;
      }
      else P2 = 0;
    }
    else P2 = 0;
  }
  }
 // Read BMP180 Sensor #3   
 tcaselect(2);{
     char status;
  double T, P;
  status = bmp180.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp180.getTemperature(T);
    if (status != 0)
    {
      status = bmp180.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = bmp180.getPressure(P, T);
        delay(100);
        if (status != 0)
        {
          P3 = P;
        }
        else P3 = 0;
      }
      else P3 = 0;
    }
    else P3 = 0;
  }
  }
  
 // Read BMP180 Sensor #4   
 tcaselect(3);{
     char status;
  double T, P;
  status = bmp180.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp180.getTemperature(T);
    if (status != 0)
    {
      status = bmp180.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = bmp180.getPressure(P, T);
        delay(100);
        if (status != 0)
        {
          P4 = P;
        }
        else P4 = 0;
      }
      else P4 = 0;
    }
    else P4 = 0;
  }
  }

 // Read BMP180 Sensor #5   
 tcaselect(4);{
     char status;
  double T, P;
  status = bmp180.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp180.getTemperature(T);
    if (status != 0)
    {
      status = bmp180.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = bmp180.getPressure(P, T);
        delay(100);
        if (status != 0)
        {
          P5 = P;
        }
        else P5 = 0;
      }
      else P5 = 0;
    }
    else P5 = 0;
  }
  }
  
 // Read BMP180 Sensor #6  
 tcaselect(5);{
     char status;
  double T, P;
  status = bmp180.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp180.getTemperature(T);
    if (status != 0)
    {
      status = bmp180.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = bmp180.getPressure(P, T);
        delay(100);
        if (status != 0)
        {
          P6 = P;
        }
        else P6 = 0;
      }
      else P6 = 0;
    }
    else P6 = 0;
  }
  }
  
  // Read BMP180 Sensor #7  
 tcaselect(6);{
     char status;
  double T, P;
  status = bmp180.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp180.getTemperature(T);
    if (status != 0)
    {
      status = bmp180.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = bmp180.getPressure(P, T);
        delay(100);
        if (status != 0)
        {
          P7 = P;
        }
        else P7 = 0;
      }
      else P7 = 0;
    }
    else P7 = 0;
  }
  }

    // Read BMP180 Sensor #8
 tcaselect(7);{
     char status;
  double T, P;
  status = bmp180.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp180.getTemperature(T);
    if (status != 0)
    {
      status = bmp180.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = bmp180.getPressure(P, T);
        delay(100);
        if (status != 0)
        {
          P8 = P;
        }
        else P8 = 0;
      }
      else P8 = 0;
    }
    else P8 = 0;
  }
  }
      Serial.println("---------------------------------------------------");
    
    //-----------------------------
    Serial.print("P1:");
    Serial.println(P1,3);
    //-----------------------------
    Serial.print("P2:");
    Serial.println(P2,3);
    //-----------------------------
    Serial.print("P3:");
    Serial.println(P3,3);
    //-----------------------------
    Serial.print("P4:");
    Serial.println(P4,3);
    //-----------------------------
    Serial.print("P5:");
    Serial.println(P5,3);
    //-----------------------------
    Serial.print("P6:");
    Serial.println(P6,3);
    //-----------------------------
    Serial.print("P7:");
    Serial.println(P7,3);
    //-----------------------------
    Serial.print("P8:");
    Serial.println(P8,3);
    //-----------------------------
    Serial.print("VCC:");
    Serial.println(ESP.getVcc());
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V0, P1);
  Blynk.virtualWrite(V1, P2);
  Blynk.virtualWrite(V2, P3);
  Blynk.virtualWrite(V3, P4);
  Blynk.virtualWrite(V4, P5);
  Blynk.virtualWrite(V5, P6);
  Blynk.virtualWrite(V6, P7);
  Blynk.virtualWrite(V7, P8);
}

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  Wire.begin();
  //Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
 
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);

  
  Serial.println("Initializing SD card...");
delay(1000);


pinMode(IN_VALVE, OUTPUT);
pinMode(OUT_VALVE, OUTPUT);



  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  // see if the card is present and can be initialized:
    String logbmp = "";
logbmp += "Tanggal";
logbmp += ","; 
logbmp += "Jam";
logbmp += ","; 
logbmp += "P1";
logbmp += ",";
logbmp += "P2";
logbmp += ",";
logbmp += "P3";
logbmp += ",";
logbmp += "P4";
logbmp += ",";
logbmp += "P5";
logbmp += ",";
logbmp += "P6";
logbmp += ",";
logbmp += "P7";
logbmp += ",";
logbmp += "P8";
logbmp += ",";
logbmp += "VCC";
logbmp += ",";

  // if the file is available, write to it:
   File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(logbmp);
    dataFile.close();
    // print to the serial port too:
    Serial.println(logbmp);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }



Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);

    //--------RTC SETUP ------------
    // if you are using ESP-01 then uncomment the line below to reset the pins to
    // the available pins for SDA, SCL
    // Wire.begin(0, 2); // due to limited pins, use pin 0 and 2 for SDA, SCL
    
    Rtc.Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(compiled);
    Serial.println();

    if (!Rtc.IsDateTimeValid()) 
    {
        if (Rtc.LastError() != 0)
        {
            // we have a communications error
            // see https://www.arduino.cc/en/Reference/WireEndTransmission for 
            // what the number means
            Serial.print("RTC communications error = ");
            Serial.println(Rtc.LastError());
        }
        else
        {
            Serial.println("RTC lost confidence in the DateTime!");
            Rtc.SetDateTime(compiled);
        }
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }

    // never assume the Rtc was last configured by you, so
    // just clear them to your needed state
    Rtc.SetSquareWavePin(DS1307SquareWaveOut_Low); 

/* comment out on a second run to see that the info is stored long term */
    // Store something in memory on the RTC.......................................................................................................................................................................
    //Rtc.SetMemory(0, 13);
    //uint8_t written = Rtc.SetMemory(13, (const uint8_t*)data, sizeof(data) - 1); // remove the null terminator strings add
    //Rtc.SetMemory(1, written);

  
tcaselect(0);{
 if (bmp180.begin())
    Serial.println("S1 BMP180 init success");
  else P1 = 0;
 
}
tcaselect(1);{
 if (bmp180.begin())
    Serial.println("S2 BMP180 init success");
  else P2 = 0;
  
}
tcaselect(2);{
 if (bmp180.begin())
    Serial.println("S3 BMP180 init success");
  else P3 = 0;
}
tcaselect(3);{
 if (bmp180.begin())
    Serial.println("S3 BMP180 init success");
  else P4 = 0;
}
tcaselect(4);{
 if (bmp180.begin())
    Serial.println("S3 BMP180 init success");
  else P5 = 0;
}
tcaselect(5);{
 if (bmp180.begin())
    Serial.println("S3 BMP180 init success");
  else P6 = 0;
}
tcaselect(6);{
 if (bmp180.begin())
    Serial.println("S3 BMP180 init success");
  else P7 = 0;
}
tcaselect(7);{
 if (bmp180.begin())
    Serial.println("S3 BMP180 init success");
  else P8 = 0;
}



Serial.println("Sensors initialized");
 digitalWrite(IN_VALVE,HIGH);
 delay(100);
 digitalWrite(OUT_VALVE,HIGH);
 delay(100);
 digitalWrite(IN_VALVE,LOW);
 delay(100);
 digitalWrite(OUT_VALVE,LOW);
 delay(100);
}


void loop() {



//Upload to web server...........................
 Blynk.run();
 timer.run();

//...............................................


if (saveInterval == counter){

digitalWrite(IN_VALVE, HIGH);
counter = 0; 

}
if (counter == 1){    
    String logbmp = "";
logbmp += datestring;
logbmp += ","; 
logbmp += String(P1);
logbmp += ",";
logbmp += String(P2);
logbmp += ",";
logbmp += String(P3);
logbmp += ",";
logbmp += String(P4);
logbmp += ",";
logbmp += String(P5);
logbmp += ",";
logbmp += String(P6);
logbmp += ",";
logbmp += String(P7);
logbmp += ",";
logbmp += String(P8);
logbmp += ",";
logbmp += String(ESP.getVcc());
logbmp += ",";

  // if the file is available, write to it:
   File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(logbmp);
    dataFile.close();
    // print to the serial port too:
   
    digitalWrite(OUT_VALVE,HIGH);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
  
}
else if (counter == 2){
 digitalWrite(OUT_VALVE,LOW);
 digitalWrite(IN_VALVE,LOW);
}


  if (!Rtc.IsDateTimeValid()) 
    {
        if (Rtc.LastError() != 0)
        {
            Serial.print("RTC communications error = ");
            Serial.println(Rtc.LastError());
        }
        else
        {
            Serial.println("RTC lost confidence in the DateTime!");
        }
    }

    RtcDateTime now = Rtc.GetDateTime();

    printDateTime(now);
    Serial.println(datestring);

    
    uint8_t address = Rtc.GetMemory(0);
    if (address != 13)
    {
        Serial.println("address didn't match");
    }
    else
    {
        uint8_t count = Rtc.GetMemory(1);
        uint8_t buff[20];
        uint8_t gotten = Rtc.GetMemory(address, buff, count);
        if (gotten != count ||
            count != sizeof(data) - 1) // remove the extra null terminator strings add
        {
            Serial.print("something didn't match, count = ");
       
            
            Serial.println();
        }
      
       
    }


counter++;
 Serial.println(saveInterval);
 Serial.println("    ");
 Serial.println(counter);

delay(5000);
    
}

void printDateTime(const RtcDateTime& dt)
{
    snprintf_P(datestring,
    countof(datestring),
            PSTR("%02u/%02u/%04u,%02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
}
