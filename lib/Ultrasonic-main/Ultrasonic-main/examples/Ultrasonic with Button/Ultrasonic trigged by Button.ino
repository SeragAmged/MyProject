#include <Arduino.h>
#include <Ultrasonic.h>   // https://github.com/meirarc/Ultrasonic.git
#include <Button.h>       // https://github.com/meirarc/Button.git

#define TRIGGER_PIN  4
#define ECHO_PIN     5

Button btn(0);
Ultrasonic ultrasonicY(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (btn.isPressed()){
    float msecToCM, msecToIN;
  long microsec = ultrasonicY.timing();

  msecToCM = ultrasonicY.convert(microsec, Ultrasonic::CM);
  msecToIN = ultrasonicY.convert(microsec, Ultrasonic::IN);
  Serial.print("MicroSec: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(msecToCM);
  Serial.print(", IN: ");
  Serial.println(msecToIN);
  delay(1000);
  }
}