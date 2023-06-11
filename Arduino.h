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

/* ??? must be >= 100 somewhere.. */
#define ARDUINO 267

/* Misc datatypes */
typedef uint16_t word;
//#define bit(b) (1UL << (b))
//#define _BV(b) (1UL << (b))
typedef bool boolean;
typedef uint8_t byte;

/* See avr/pgmspace.h for more info/usage. */
class __FlashStringHelper;
#define F(x) reinterpret_cast<const __FlashStringHelper*>(x)

/* No need for these to be static/inline/constexpr; we run bogoduino on
 * platforms with plenty of RAM. */
const uint8_t A0 = 0;
const uint8_t INPUT = 0;
const uint8_t OUTPUT = 1;
const uint8_t INPUT_PULLUP = 2;
const uint8_t LOW = 0;
const uint8_t HIGH = 1;

template<class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template<class T> inline T max(T a, T b) { return (a > b) ? a : b; }

void delay(unsigned long ms);
unsigned long millis(unsigned long set_millis=0);
void pinMode(uint8_t pin, uint8_t mode);
int analogRead(uint8_t pin);
void digitalWrite(uint8_t pin, uint8_t val);

#endif //INCLUDED_BOGODUINO_ARDUINO_H
