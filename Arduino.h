#ifndef INCLUDED_BOGODUINO_ARDUINO_H
#define INCLUDED_BOGODUINO_ARDUINO_H

#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "Serial.h"
#include "WString.h"

/* See avr/pgmspace.h for more info/usage. */
class __FlashStringHelper;
#define F(x) reinterpret_cast<const __FlashStringHelper*>(x)

const u_int8_t A0 = 0;
const u_int8_t INPUT = 0;
const u_int8_t OUTPUT = 1;

template<class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template<class T> inline T max(T a, T b) { return (a > b) ? a : b; }

void delay(unsigned long ms);
unsigned long millis();
void pinMode(u_int8_t pin, u_int8_t mode);
int analogRead(u_int8_t pin);

#endif //INCLUDED_BOGODUINO_ARDUINO_H
