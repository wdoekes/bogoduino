#include "Arduino.h"

void delay(unsigned long ms) {}
unsigned long millis() { static int m = 50000; return (m += 60000); }
void pinMode(uint8_t pin, uint8_t mode) {}
int analogRead(uint8_t pin) { return 21; }
void digitalWrite(uint8_t pin, uint8_t val) {}
