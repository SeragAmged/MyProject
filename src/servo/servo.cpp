#include "MyServo.h"

void openServo(Servo &myServo, int speed, int time)
{

  myServo.writeMicroseconds(SPEEDM(-speed));
  // myServo2.writeMicroseconds(SPEEDM(speed));
  delay(time);
  myServo.writeMicroseconds(SPEEDM(0));
  // myServo2.writeMicroseconds(SPEEDM(0));
}

void closeServo(Servo &myServo, int speed, int time)
{

  myServo.writeMicroseconds(SPEEDM(speed));
  // myServo2.writeMicroseconds(SPEEDM(-speed));

  delay(time);
  myServo.writeMicroseconds(SPEEDM(0));
  // myServo2.writeMicroseconds(SPEEDM(0));
}

void servoSetupAndCloseAll(Servo& servoR, Servo& servoG,Servo& servoY)
{

  servoR.attach(SERVO_PIN_R);
  closeServo(servoR, SERVO_SPEED, SERVO_DELAY);
  servoG.attach(SERVO_PIN_G);
  closeServo(servoG, SERVO_SPEED, SERVO_DELAY);
  servoY.attach(SERVO_PIN_Y);
  closeServo(servoY, SERVO_SPEED, SERVO_DELAY);
}

void servoOpenAll(Servo& servoR, Servo& servoG,Servo& servoY)
{

  openServo(servoR, SERVO_SPEED, SERVO_DELAY);
  openServo(servoG, SERVO_SPEED, SERVO_DELAY);
  openServo(servoY, SERVO_SPEED, SERVO_DELAY);
}