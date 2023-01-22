#ifndef INCLUDED_BOGODUINO_SERIAL_H
#define INCLUDED_BOGODUINO_SERIAL_H

#include "Print.h"

class BogoSerial : public Print {
public:
    BogoSerial() : Print() {}

    void begin(long baud) {}
    void begin(long baud, int mode) {}

    bool operator!() { return false; }
};

static BogoSerial Serial;

#endif //INCLUDED_BOGODUINO_SERIAL_H
