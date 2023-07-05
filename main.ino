#include <DHT.h>

#define DHTPIN 6
#define DHTTYPE DHT22

const int pinVermelho = 2;
const int pinAmarelo = 3;
const int pinVerde = 4;

const int pinBotao = 7;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVerde, OUTPUT);

  pinMode(pinBotao, INPUT_PULLUP);

  dht.begin();
}

void loop() {

    if (digitalRead(pinBotao) == LOW) {

        float temp = dht.readTemperature();

        if (temp >= 30) {
        digitalWrite(pinVermelho, HIGH);
        digitalWrite(pinAmarelo, LOW);
        digitalWrite(pinVerde, LOW);
        } else if (temp >= 20) {
        digitalWrite(pinVermelho, LOW);
        digitalWrite(pinAmarelo, HIGH);
        digitalWrite(pinVerde, LOW);
        } else {
        digitalWrite(pinVermelho, LOW);
        digitalWrite(pinAmarelo, LOW);
        digitalWrite(pinVerde, HIGH);
        }
  }
}