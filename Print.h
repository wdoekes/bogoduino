#ifndef INCLUDED_BOGODUINO_PRINT_H
#define INCLUDED_BOGODUINO_PRINT_H

#include <cmath> // not used here, but by others
#include <cstdint>
#include <cstdio>

#include "WString.h"

// This is a wrapper class that allows flash strings to be used as a
// class, this means that type checking and function overloading can be
// used with flash strings.
class __FlashStringHelper;

enum print_radix {
    BIN = 2,
    OCT = 8,
    DEC = 10,
    HEX = 16
};

static const char* radix_fmt[17] {
    "", "", "FIXME", "", "", "", "", "",
    "%o", "", "%d", "", "", "", "", "", "%X"};

class Print {
public:
    Print() {}
    virtual ~Print() {}

#define PRINT_FUNCTION(type, fmt) \
    size_t print(type p) { printf(fmt, p); return 0; } \
    size_t println(type p) { printf(fmt "\n", p); return 0; } \
    size_t print(type p, enum print_radix pr) { \
	if (pr != DEC) { printf(radix_fmt[pr], p); } \
	else { printf(fmt, p); } \
	return 0; } \
    size_t println(type p, enum print_radix pr) { \
	if (pr != DEC) { printf(radix_fmt[pr], p); printf("\n"); } \
	else { printf(fmt, p); } \
	return 0; }
#define PRINT_FUNCTION_CAST(type, fmt, cast) \
    size_t print(type p) { \
	printf(fmt, reinterpret_cast<cast>(p)); return 0; } \
    size_t println(type p) { \
	printf(fmt "\n", reinterpret_cast<cast>(p)); return 0; } \
    size_t print(type p, int) { \
	printf(fmt, reinterpret_cast<cast>(p)); return 0; } \
    size_t println(type p, int) { \
	printf(fmt "\n", reinterpret_cast<cast>(p)); return 0; }

    PRINT_FUNCTION_CAST(const __FlashStringHelper *, "%s", const char *);
    PRINT_FUNCTION(const char *, "%s");
    PRINT_FUNCTION(char, "%c");
    PRINT_FUNCTION(double, "%g");
    PRINT_FUNCTION(float, "%f");
    PRINT_FUNCTION(int, "%d");
    PRINT_FUNCTION(unsigned int, "%u");
    PRINT_FUNCTION(long, "%ld");
    PRINT_FUNCTION(unsigned long, "%ld");
#undef PRINT_FUNCTION

    size_t print(const String& s) { return print(s.c_str()); }
    size_t println(const String& s) { return println(s.c_str()); }

    size_t println() { printf("\n"); return 0; }

    size_t write(const uint8_t *buffer, size_t size) {
	return fwrite(buffer, 1, size, stdout);
    }
    size_t write(const char *buffer, size_t size) {
	return fwrite(buffer, 1, size, stdout);
    }
};

#endif //INCLUDED_BOGODUINO_PRINT_H
