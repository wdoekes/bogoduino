#ifndef INCLUDED_BOGODUINO_PRINT_H
#define INCLUDED_BOGODUINO_PRINT_H

// This is a wrapper class that allows flash strings to be used as a
// class, this means that type checking and function overloading can be
// used with flash strings.
class __FlashStringHelper;

class Print {
public:
    Print() {}
    void begin(long baud) {}
    void begin(long baud, int mode) {}

#define PRINT_FUNCTION(type, fmt) \
    size_t print(type p) { printf(fmt, p); return 0; } \
    size_t println(type p) { printf(fmt "\n", p); return 0; } \
    size_t print(type p, int) { printf(fmt, p); return 0; } \
    size_t println(type p, int) { printf(fmt "\n", p); return 0; }
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

    size_t println() { printf("\n"); return 0; }

    bool operator!() { return false; }
};

#endif //INCLUDED_BOGODUINO_PRINT_H
