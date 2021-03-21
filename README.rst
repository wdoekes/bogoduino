Bogoduino
=========

A few h/cpp files to aid testing Arduino/ESP8266 code on different platforms.

Usage
-----

Check out this code in the ``./bogoduino`` directory::

    git submodule add https://github.com/wdoekes/bogoduino.git

Add ``-I./bogoduino`` subdirectory to the ``CPPFLAGS``::

    CPPFLAGS = -DTEST_BUILD -g -I./bogo
