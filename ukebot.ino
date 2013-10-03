#include <Servo.h>
#include "ukeString.h"

#ifdef CORE_TEENSY
    const int PINS[] = {9, 10, 14, 15}; // PWM pins on teensy
#else
    const int PINS[] = {5,  6,  9, 10}; // PWM pins on arduino
#endif

const int MIDL[] = {110, 70, 85, 70};   // middle of rotation
const int N = 4;                        // number of strings
UkeString string[N];

const int led = 11;
bool b = LOW;

void setup()
{
    for (int i=0; i<N; i++)               // all servos are not exactly the same
        string[i].init(PINS[i], MIDL[i]); // so we calibrate them
    pinMode(led, OUTPUT);
}

void loop()
{
    const int DELAY = 140;

    for (int i=0; i<N; i++)
    {
        string[i].strum();            // strum all strings almost in the same time
        delay(10);                    // but add a little delay to sound better
    }

    digitalWrite(led, b = !b);
    delay(DELAY);
}

