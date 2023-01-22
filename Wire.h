#ifndef INCLUDED_BOGODUINO_WIRE_H
#define INCLUDED_BOGODUINO_WIRE_H

struct TwoWire {
    void begin() {}
    void beginTransmission(uint8_t) {}
    void endTransmission() {}
    void requestFrom(uint8_t, uint8_t) {}
    uint8_t read() { return 0xFF; }
    void write(uint8_t, uint8_t = 0) {}
    void write(const uint8_t*, uint8_t) {}
};

extern TwoWire Wire;

#endif //INCLUDED_BOGODUINO_WIRE_H
