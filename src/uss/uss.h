#ifndef USS_H
#define USS_H
#include <Ultrasonic.h>

#define ECHO_PIN_Y 15
#define TRIG_PIN_Y 2

#define ECHO_PIN_R 19
#define TRIG_PIN_R 21

#define ECHO_PIN_G 34
#define TRIG_PIN_G 4


long ussDistance(Ultrasonic &myUltrasonic);
void ussSetup();

// bool disposalsCounter(Ultrasonic ultrasonic);

#endif