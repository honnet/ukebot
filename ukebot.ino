#include <Servo.h>
#include "ukeString.h"

#ifdef CORE_TEENSY
    const int PINS[] = {9, 10, 14, 15}; // PWM pins on teensy
    const int led = 11;
#else
    const int PINS[] = {5,  6,  9, 10}; // PWM pins on arduino
    const int led = 13;
#endif

const int MIDL[] = {110, 65, 75, 60};   // middle of rotation
const int N = 4;                        // number of strings
UkeString string[N];

bool b = LOW;

void setup()
{
    for (int i=0; i<N; i++)               // all servos are not exactly the same
        string[i].init(PINS[i], MIDL[i]); // so we calibrate them
    pinMode(led, OUTPUT);
  for(;;);
}

void loop()
{
    const int DELAY = 100;

    for (int i=0; i<N; i++)
    {
        string[i].strum();               // strum all strings almost in the same time
        delay(DELAY);                    // but add a little delay to sound better
    }

    for (int i=N-1; i>=0; i--)
    {
        string[i].strum();               // strum all strings almost in the same time
        delay(DELAY);                    // but add a little delay to sound better
    }

    digitalWrite(led, b = !b);
    delay(150);
}

