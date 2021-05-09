#ifndef INCLUDED_BOGODUINO_ARDUINO_H
#define INCLUDED_BOGODUINO_ARDUINO_H

#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "Serial.h"
#include "WString.h"

/* See avr/pgmspace.h for more info/usage. */
class __FlashStringHelper;
#define F(x) reinterpret_cast<const __FlashStringHelper*>(x)

const uint8_t A0 = 0;
const uint8_t INPUT = 0;
const uint8_t OUTPUT = 1;

template<class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template<class T> inline T max(T a, T b) { return (a > b) ? a : b; }

void delay(unsigned long ms);
unsigned long millis();
void pinMode(uint8_t pin, uint8_t mode);
int analogRead(uint8_t pin);

#endif //INCLUDED_BOGODUINO_ARDUINO_H
