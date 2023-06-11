#include "Arduino.h"

void delay(unsigned long ms) {}

static unsigned long _millis = 50000;
unsigned long millis(unsigned long set_millis) {
    if (set_millis) {
	_millis = set_millis;
    } else {
	_millis++;
    }
    return _millis++;
}

void pinMode(uint8_t pin, uint8_t mode) {}
int analogRead(uint8_t pin) { return 21; }

void digitalWrite(uint8_t pin, uint8_t val) {
    printf("[digitalWrite(%d, %d)]\n", pin, val);
}
