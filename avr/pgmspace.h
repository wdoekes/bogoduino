#ifndef INCLUDED_BOGODUINO_AVG_PGMSPACE_H
#define INCLUDED_BOGODUINO_AVG_PGMSPACE_H

/**
 * Usage:
 *
 *   const char my_string[] PROGMEM = "my string";
 *
 * my_string will now be stored in program memory (PGM/Flash)
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
 *   typedef __FlashStringHelper pgm_char;
 *   #define from_pgm_char_p(x) reinterpret_cast<const char*>(x)
 *   #define to_pgm_char_p(x) reinterpret_cast<const pgm_char*>(x)
 *
 *   const pgm_char *my_pgm_string = to_pgm_char_p(my_string);
 *
 * And now you can/must use the <function>_P variants, like:
 *
 *   --> strcmp("abc", my_pgm_string)     // BAD
 *   error: cannot convert ‘const __FlashStringHelper*’ to ‘const char*’
 *
 *   --> strcmp_P("abc", my_pgm_string)   // good
 *
 * But... see also progmem.h (not in bogoduino), which defines this:
 *
 *   #define DECLARE_PGM_CHAR_P(identifier, value) \
 *     const char (char_ ## identifier)[] PROGMEM = value; \
 *     const pgm_char *const identifier = to_pgm_char_p(char_ ## identifier)
 *
 * Instead of the my_string[] initializer above, you can now do:
 *
 *   DECLARE_PGM_CHAR_P(my_string, "my string");
 *
 * It's not the prettiest, but it will create an opaque char_my_string
 * for you (in flash memory) and assign it to my_string.
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
