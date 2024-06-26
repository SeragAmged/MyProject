#include <Arduino.h>
#include <WiFi.h>
#include <wifi/network.h>
#include <Ultrasonic.h>
#include <led/led.h>
#include <uss/uss.h>
#include <servo/MyServo.h>

Ultrasonic ultrasonicY(TRIG_PIN_Y, ECHO_PIN_Y);
Ultrasonic ultrasonicG(TRIG_PIN_G, ECHO_PIN_G);
Ultrasonic ultrasonicR(TRIG_PIN_R, ECHO_PIN_R);
Servo servoR, servoG, servoY;
long startTime = 0;

void setup()
{
  Serial.begin(9600);
  servoSetupAndCloseAll(servoR, servoG, servoY);
  // ussSetup();
  delay(1000);
  // connectToWifi(ssid, password);
}

void handleServoAction(Ultrasonic &ultrasonic, Servo &servo)
{
  if (startTime == 0)
  {
    startTime = millis();
  }

  openServo(servo, SERVO_SPEED, SERVO_DELAY);
  long elapsed = millis() - startTime;

  if (elapsed > 5000)
  {
    closeServo(servo, SERVO_SPEED, SERVO_DELAY);
    Serial.println("Closed without verified: " + String(elapsed));
    currentData = 0;
    startTime = 0;
  }
  else if (ussDistance(ultrasonic) <= 20 && ussDistance(ultrasonic) != 0)
  {
    Serial.println("Verified: " + String(ussDistance(ultrasonic)));
    closeServo(servo, SERVO_SPEED, SERVO_DELAY);
    currentData = 0;
    startTime = 0;
  }
}

void handleClientData()
{
  switch (currentData)
  {
  case 49: // '1'
    handleServoAction(ultrasonicY, servoY);
    break;
  case 50: // '2'
    handleServoAction(ultrasonicR, servoR);
    break;
  case 51: // '3'
    handleServoAction(ultrasonicG, servoG);
    break;
  }
}

void loop()
{
  // receiveClientData();
  // handleClientData();
  servoOpenAll(servoR, servoG, servoY);
}
