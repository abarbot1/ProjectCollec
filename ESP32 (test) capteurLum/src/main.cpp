#include <Arduino.h>
#define LED 2

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
	digitalWrite(LED, LOW);
	delay(500);
  Serial.println("LED ON");
	digitalWrite(LED, HIGH);
	delay(500);
  digitalWrite(LED, LOW);
  Serial.println("LED OFF");
}