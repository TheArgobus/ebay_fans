#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

const int ledPin =  6;  // the number of the LED pin (digital)

const int relayPin = 9; // the relay pin (digital)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT test."));
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  dht.begin();
}

void loop() {

  digitalWrite(ledPin, HIGH);

  float t = dht.readTemperature();

  if (isnan(t)) {
      Serial.println("Failed to read from DHT sensor.");
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
    } else {
      Serial.print("Temp: ");
      Serial.print(t);
      Serial.println("C");
      // if it's above 37C/99F
      if (t >= 37) {
        Serial.println("Temp High");
        digitalWrite(relayPin, HIGH);
        delay(600000);
      } else {
        Serial.println("Temp Normal");
        digitalWrite(relayPin, LOW);
      }
    }

    delay(1000);
  
}
