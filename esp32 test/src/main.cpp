#include <ClosedCube_STS35.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define UART_BAUD 115200
#define STS35_I2C_ADDRESS 0x4B

//Senard
//#define URL_SERVEUR "http://10.10.33.179:3000/fact"

//Lusia
#define URL_SERVEUR "http://10.10.33.161:3000/collectemp"

const char *ssid = "immobladePoint";
const char *password = "3M_VT-MJ_SU-N3";
  HTTPClient http;

ClosedCube::Sensor::STS35 sts35;
float derniereTemp=0;
void setup()
{
  Serial.begin(UART_BAUD);
  Wire.begin();

  Serial.println("ClosedCube STS35 Arduino Demo");
  sts35.address(STS35_I2C_ADDRESS); // I2C Address: either 0x4A or 0x04B
  Serial.println();
  Serial.println("Connecting to WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  Serial.print("WiFi connected with ip ");
  Serial.println(WiFi.localIP());
   
}
void loop()
{
  derniereTemp= sts35.readTemperature();
  Serial.print("T=");
  Serial.print(sts35.readTemperature());
  Serial.println(" C");
  //http.begin("http://10.10.33.179:3000/fact");
  http.begin(URL_SERVEUR);

  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST("temperature="+String(derniereTemp, 2));
  if (httpCode > 0)
  { // Check for the returning code

    //String payload = http.getString();
    Serial.println(httpCode);
    //Serial.println(payload);
  }
  else
  {

    Serial.println("Error on HTTP request");
  }

  http.end(); // Free the resources
  delay(5000); // 1 SECONDE DE DELAY
}
