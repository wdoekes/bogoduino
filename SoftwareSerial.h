#ifndef INCLUDED_BOGODUINO_SOFTWARESERIAL_H
#define INCLUDED_BOGODUINO_SOFTWARESERIAL_H

const int SWSERIAL_7E1 = 0;

// This is a wrapper class that allows flash strings to be used as a
// class, this means that type checking and function overloading can be
// used with flash strings.
class __FlashStringHelper;

class SoftwareSerial {
public:
  SoftwareSerial(int, int, bool) {}
  void begin(long, unsigned short) {}
  int available() { return true; }
  int read() { return 0; }
  void print(const char *) {}
  void print(const __FlashStringHelper *) {}
};

#endif //INCLUDED_BOGODUINO_SOFTWARESERIAL_H
