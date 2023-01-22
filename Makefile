HEADERS = $(wildcard *.h)
OBJECTS = Arduino.o WString.o bogoduino.o

# --- Test mode ---
CXX = g++
CPPFLAGS = -DTEST_BUILD -DTEST_BOGODUINO_ITSELF -g
CXXFLAGS = -Wall -Os -fdata-sections -ffunction-sections
LDFLAGS = -Wl,--gc-sections # -s(trip)

.PHONY: test
test: ./bogoduino.test
	./bogoduino.test

.PHONY: clean
clean:
	$(RM) $(OBJECTS) ./bogoduino.test

$(OBJECTS): $(HEADERS)

bogoduino.test: $(OBJECTS)
	$(LINK.cc) -o $@ $^
