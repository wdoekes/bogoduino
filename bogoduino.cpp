#ifdef TEST_BUILD

#include "Arduino.h"
#include "Serial.h"
#include "SoftwareSerial.h"
#include "WString.h"

int main()
{
    String s = "test";
    s.remove(s.indexOf('s'));
    s += "ST";
    printf("[%s]\n", s.c_str());
    return 0;
}

/* vim: set ts=8 sw=4 sts=4 et ai: */
#endif //TEST_BUILD
