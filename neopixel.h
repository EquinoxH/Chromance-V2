#pragma once

#include <vector>
#include <pico/stdlib.h>
#include <hardware/pio.h>
#include <hardware/clocks.h>
#include <ws2812.pio.h>

#include "colours.h"

class NeoPixel{
private:
    
    // Members

    int pin;
    int numLEDs;
    double stripBrightness;

    std::vector<Colour> trueColours;
    std::vector<double> pixelBrightnessValues;

    // Functions

    void initialisePin();
    void putPixel(uint32_t pixelRGB);
    uint32_t urgbToU32(uint8_t r, uint8_t g, uint8_t b);
    uint32_t urgbToU32(Colour colour);

public:

    // Constructor

    NeoPixel(int gpioPin, int leds);

    // Functions

    double getCurrent();
    double getActualCurrent();

    Colour getPixelColour(int index);
    double getPixelBrightness(int index);

    void setPixelColour(int index, Colour color);
    void setPixelBrightness(int index, double brightness);
    void setStripBrightness(double brightness);

    void off();
    void test();
    void test2();
    void fill(Colour color);
    void writeUpdates();

    void fadePixel(int index, double amount);
    void fadeAll();
    void superFadeAll();
};