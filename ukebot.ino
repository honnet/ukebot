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
    Serial.begin(115200);
}

void loop()
{
    const int DELAY = 140;
    static bool autoMode = false;
    int stringNum = 0;

    if (Serial.available() > 0) {

        stringNum = int(Serial.read());

        if (stringNum >= 1 && stringNum <= 4) { // control mode
            string[stringNum].strum();
            delay(DELAY);                       // TODO: non blocking func in doubleStrum(delay)
            string[stringNum].strum();
            delay(DELAY);
        } else {
            autoMode = (stringNum == 0);        // set auto mode ?
        }

    } else if (autoMode) {

        for (int i=0; i<N; i++)
        {
            string[i].strum();            // strum all strings almost in the same time
            delay(10);                    // but add a little delay to sound better
        }
        delay(DELAY);
    }

    delay(20);
    digitalWrite(led, b = !b);
}

