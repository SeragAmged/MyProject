#ifndef MyServo_H
#define MyServo_H

#include <Servo.h>

#define SERVO_PIN_R 18
#define SERVO_PIN_G 12
#define SERVO_PIN_Y 5

#define SERVO_SPEED 1200
#define SERVO_DELAY 1000
#define NEUTRAL_POSITION 1500

#define SPEEDM(x) ((x) + NEUTRAL_POSITION)

void openServo(Servo &myServo, int speed, int time);
void closeServo(Servo &myServo, int speed, int time);
void servoSetupAndCloseAll(Servo& servoR, Servo& servoG,Servo& servoY);
void servoOpenAll(Servo& servoR, Servo& servoG,Servo& servoY);

#endif