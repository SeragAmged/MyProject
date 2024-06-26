#include <Arduino.h>
#include "uss.h"


long ussDistance(Ultrasonic &myUltrasonic)
{

  long microsec = myUltrasonic.timing();
  float msecToCM = myUltrasonic.convert(microsec, Ultrasonic::CM);
  Serial.println("cm: " + String(msecToCM));
  return msecToCM;
}

void ussSetup()
{
  pinMode(TRIG_PIN_Y, OUTPUT);
  pinMode(ECHO_PIN_Y, INPUT);

  pinMode(TRIG_PIN_R, OUTPUT);
  pinMode(ECHO_PIN_R, INPUT);

  pinMode(TRIG_PIN_G, OUTPUT);
  pinMode(ECHO_PIN_G, INPUT);
}

























// long ussDistance()
// {

//     long duration;

//     // Clear the trigPin
//     digitalWrite(TRIG_PIN, LOW);
//     delayMicroseconds(2);

//     // Set the trigPin on HIGH state for 10 microseconds
//     digitalWrite(TRIG_PIN, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(TRIG_PIN, LOW);

//     // Read the echoPin, pulseIn() returns the duration (in microseconds) of the pulse
//     duration = pulseIn(ECHO_PIN, HIGH);

//     // Calculate the distance (in centimeters) based on the speed of sound
//     return (duration / 2) / 29.1; // distance
// }

// long ussDistance(Ultrasonic ultrasonic)
// {
//     float msecToCM;
//     long microsec = ultrasonic.timing();
//     msecToCM = ultrasonic.convert(microsec, Ultrasonic::CM);
//     Serial.print(", CM: ");
//     Serial.print(msecToCM);
//     return microsec;
// }

// bool disposalsCounter(Ultrasonic ultrasonic)
// {
//     // Serial.printf("Distance is %ld\n", ussDistance());
//     // delay(1000);
//     //&& ussDistance() < 48
//     // Serial.println("Object detected! Count: " + String(objectCount++));
//     // delay(1000);
//     if (ussDistance(ultrasonic) <= 10)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
