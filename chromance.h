#pragma once
#include <string>
#include <vector>

#include "neopixel.h"
#include "colours.h"

namespace Chromance{
    extern const double currentLimit;
    extern double speed;
    extern bool trackCurrent;
    extern std::string profile;

    extern NeoPixel strip0;
    extern NeoPixel strip1;
    extern NeoPixel strip2;
    extern NeoPixel strip3;

    extern bool strip0Initialised;
    extern bool strip1Initialised;
    extern bool strip2Initialised;
    extern bool strip3Initialised;

    // extern std::vector<Trail> trails;
    // extern std::vector<Dot> dots;
    // extern std::vector<Drawings> drawings;
    // extern std::vector<Circle> circles;
    // extern std::vector<Segment> segments;

    // Create Shape Functions

    void createTrail(Colour colour, int start, int lifeTime, bool immortal, double speed, bool hasDeathEffect);
    void createSegment(Colour colour, int start);
    void createDot(Colour colour, int start, int lifeTime);
    void createDrawing(Colour colour, std::vector<int> segments);
    void createCircle(Colour colour, int hubID, int lifeTime);

    // Strip Functions

    void off();
    void test();
    void test2();
    void writeUpdates();

    void fadeAll();
    void superFadeAll();
    void doUpdate();

    double getCurrent();
    double getActualCurrent();
    double calculateBrightnessLimit();
    void setBrightness();
    // int getNumOnLEDs();

    NeoPixel getStrip(int stripID);
    Colour getLED(int stripID, int index);
    Colour getLED(int ledNumber);

    void setLEDColour(int stripID, int index, Colour colour);
    void setLEDColour(int ledNumber, Colour colour);
}