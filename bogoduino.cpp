#if defined(TEST_BUILD) && defined(TEST_BOGODUINO_ITSELF)

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

    Serial.println("Hello World!");
    Serial.print("(oct) 0o13 == 0o");
    Serial.println(013, OCT);
    Serial.print("(dec) 11 == ");
    Serial.println(11);
    Serial.print("(hex) 0xB == 0x");
    Serial.println(0xB, HEX);
    return 0;
}

/* vim: set ts=8 sw=4 sts=4 et ai: */
#endif //TEST_BUILD && TEST_BOGODUINO_ITSELF
