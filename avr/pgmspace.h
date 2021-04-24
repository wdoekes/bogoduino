#ifndef INCLUDED_BOGODUINO_AVG_PGMSPACE_H
#define INCLUDED_BOGODUINO_AVG_PGMSPACE_H

/**
 * Usage:
 *
 *   const char my_string[] PROGMEM = "my string";
 *   long value PROGMEM = 0x1234;
 *
 * my_string and value will now be stored in program memory (PGM/Flash)
 * rather than in SRAM.
 *
 * However, char*s cannot be used as regular char* pointers:
 *
 *   my_string[0]                 // BAD
 *   pgm_read_byte(my_string[0])  // good
 *
 * It's wise to cast these global PROGMEM strings to __FlashStringHelper
 * so the compiler can detect that you're using these type-safely [sic]:
 *
 *   #define AS_MEM_CSTR(x) reinterpret_cast<const char*>(x)
 *   #define AS_PGM_CSTR(x) reinterpret_cast<const __FlashStringHelper*>(x)
 *
 *   const __FlashStringHelper *my_pgm_string = to_PGM_P(my_string);
 *
 * And now you can/must use the <function>_P variants, like:
 *
 *   --> strcmp("abc", my_pgm_string)     // BAD
 *   error: cannot convert ‘const __FlashStringHelper*’ to ‘const char*’
 *
 *   --> strcmp_P("abc", my_pgm_string)   // good
 */
#include <cstring>

#define PROGMEM /* nothing */
class __FlashStringHelper; /* a.k.a. StringInProgramSpace */

char pgm_read_byte(const char *p) { return *p; }
int memcmp_P(const char *s1, const __FlashStringHelper *s2, size_t len) {
    return memcmp(s1, reinterpret_cast<const char*>(s2), len);
}
int strcmp_P(const char *s1, const __FlashStringHelper *s2) {
    return strcmp(s1, reinterpret_cast<const char*>(s2));
}

#endif //INCLUDED_BOGODUINO_AVG_PGMSPACE_H
