Bogoduino
=========

A few h/cpp files to aid testing Arduino/ESP8266 code on different platforms.

Usage
-----

Check out this code in the ``./bogoduino`` directory::

    git submodule add https://github.com/wdoekes/bogoduino.git

Add ``-I./bogoduino`` subdirectory to the ``CPPFLAGS``::

    CPPFLAGS = -DTEST_BUILD -g -I./bogoduino


Tips for compiler warnings
--------------------------

As always, compiler warnings are generally useful. However, the *Arduino
IDE* does a job of hiding them. This may lead you to create code like:

.. code-block:: c

    int value = 123456;

And that code will run fine on your *Intel* or *Xtensa* (ESP8266). But
it would get truncated on the *AVR* (Atmel, Arduino) which has 16 bit
integers.

To remedy this, you can enable warnings:

* There are predefined values for the compiler flags. You can find them
  in a file similar to ``hardware/arduino/avr/platform.txt`` (exact location on
  your system may differ)::

    $ grep ^compiler.warning_flags /snap/arduino/current/hardware/arduino/avr/platform.txt
    compiler.warning_flags=-w
    compiler.warning_flags.none=-w
    compiler.warning_flags.default=
    compiler.warning_flags.more=-Wall
    compiler.warning_flags.all=-Wall -Wextra

* Exit the *Arduino IDE* and look for a file called ``preferences.txt``
  (again, the file may be elsewhere on your system)::

    $ grep ^compiler.warning ~/snap/arduino/current/.arduino15/preferences.txt
    compiler.warning_level=none

  Edit it so it says: ``compiler.warning_level=all``

* Start the *Arduino IDE* and go to  *File* -> *Preferences* ->
  *Settings* to find a checkbox called *"Show verbose output during
  compilation"*. Check it.

Now, when compiling, you'll get a whole bunch more output. But also
things like::

    /snap/arduino/50/hardware/tools/avr/bin/avr-g++ -c -g -Os -Wall
      -Wextra -std=gnu++11 -fpermissive -fno-exceptions
      -ffunction-sections -fdata-sections -fno-threadsafe-statics
      -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L
      -DARDUINO=10813 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR
      -I/snap/arduino/50/hardware/arduino/avr/cores/arduino
      -I/snap/arduino/50/hardware/arduino/avr/variants/standard
      /tmp/arduino_build_940516/sketch/int_size_test.ino.cpp -o
      /tmp/arduino_build_940516/sketch/int_size_test.ino.cpp.o
    ~/Arduino/proj/int_size_test/int_size_test.ino:1:13:
      warning: overflow in implicit constant conversion [-Woverflow]
     int value = 123456;
                 ^~~~~~

Better!
