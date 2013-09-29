#ifndef UkeString_h
#define UkeString_h

#include <Arduino.h>
#include <Servo.h>

// TODO: debug print

class UkeString
{
    private:
        int middle;
        int delta;
        Servo myServo;

        void set(int angle);    // set angle between 0 and 180 degrees
        int get();              // return current angle between 0 and 180 degrees

    public:
        // pin must allow pwm; middle and delta are angles below 180 degrees:
        void init(int pin, int middle = 90, int delta = 30);
        void strum();           // toggle servo position (m + d <=> m - d)
        UkeString(){};
};

#endif

