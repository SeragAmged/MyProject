#include <Arduino.h>
#include "led.h"

void blinkLed(int seconds)
{
    digitalWrite(LED_PIN, HIGH);
    delay(seconds * 1000);
    digitalWrite(LED_PIN, LOW);
}

void ledSwitch(int data)
{
  if (data == 49)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else if (data == 48)
  {
    digitalWrite(LED_PIN, LOW);
  }

}