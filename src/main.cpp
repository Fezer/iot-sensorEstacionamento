#include <Arduino.h>
#include <Ultrasonic.h>

#define pino_ultrason_trigger 4
#define pino_ultrason_echo 5
#define NOTE_A4 440

Ultrasonic ultrasonic(pino_ultrason_trigger, pino_ultrason_echo);

const int pinBuzz = 8;
const int pinLED1 = 10;
const int pinLED2 = 11;
const int pinLED3 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);

  pinMode(pinBuzz, OUTPUT);
}

void loop() {
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  Serial.print("\n");
  Serial.print(cmMsec);

  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
  noTone(pinBuzz);

  if(cmMsec < 30 && cmMsec >= 20){
    Serial.print("\n1 LED");
    digitalWrite(pinLED1, HIGH);
    tone(pinBuzz, NOTE_A4);
    delay(300);
    noTone(pinBuzz);
    delay(300);
  }
  if(cmMsec < 20 && cmMsec >= 10){
    Serial.print("\n2 LED");
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, HIGH);
    tone(pinBuzz, NOTE_A4);
    delay(200);
    noTone(pinBuzz);
    delay(200);
  }
  if(cmMsec < 10){
    Serial.print("\n3 LED");
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, HIGH);
    digitalWrite(pinLED3, HIGH);
    tone(pinBuzz, NOTE_A4);
    delay(100);
    noTone(pinBuzz);
    delay(100);
  }
}