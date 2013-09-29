#include "ukeString.h"

void UkeString::init(int p, int m, int d)
{
    middle = constrain(m, 45, 90 + 45);
    delta  = constrain(d, 15, 40);
    myServo.attach(p);
    myServo.write(middle);
}

void UkeString::set(int a)
{
    myServo.write(constrain(a, 0, 180));
}

int UkeString::get()
{
    return myServo.read();
}

void UkeString::strum()
{
    if (myServo.read() >= middle) {
        myServo.write(middle - delta);
    }
    else if (myServo.read() < middle) {
        myServo.write(middle + delta);
    }
}

