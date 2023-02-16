#include <SparkFunTSL2561.h>
#include <Wire.h>
#include <WiFi.h>

const char* ssid     = "immobladePoint";
const char* password = "3M_VT-MJ_SU-N3";

SFE_TSL2561 light;

boolean gain;
unsigned int ms;
void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Connecting to WiFi");
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.print("WiFi connected with ip ");  
  Serial.println(WiFi.localIP());

  Serial.println("TSL2561 example sketch");
  light.begin();
 
  unsigned char ID;
  if (light.getID(ID))
  {
    Serial.print("Got factory ID: 0X");
    Serial.print(ID,HEX);
    Serial.println(", should be 0X5X");
  }
  gain = 0;

  unsigned char time = 2;

  Serial.println("Set timing...");
  light.setTiming(gain,time,ms);

  Serial.println("Powerup...");
  light.setPowerUp();
}
void loop()
{
  delay(ms);

  unsigned int data0, data1;
  if (light.getData(data0,data1))
  {
  
    Serial.print("data0: ");
    Serial.print(data0);
    Serial.print(" data1: ");
    Serial.print(data1);
   
    double lux;
    boolean good;

    good = light.getLux(gain,ms,data0,data1,lux);

    Serial.print(" lux: ");
    Serial.print(lux);
    if (good) Serial.println(" (good)"); else Serial.println(" (BAD)");
  }
}
