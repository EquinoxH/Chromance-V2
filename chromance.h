#pragma once
#include <string>
#include <vector>
#include <map>

#include "neopixel.h"
#include "colours.h"

#include "shapes/trail/trail.h"
#include "shapes/slowTrail/slowTrail.h"
#include "shapes/doubleTrail/doubleTrail.h"
#include "shapes/segment/segment.h"
#include "shapes/dot/dot.h"

namespace Chromance{
    enum DisplayMode{
        absolute,
        blend
    };

    extern const double currentLimit;
    extern int speed;
    extern int fps;
    extern bool trackCurrent;
    extern std::string profile;
    extern DisplayMode displayMode;
    extern Colour backgroundColour;

    extern NeoPixel strip0;
    extern NeoPixel strip1;
    extern NeoPixel strip2;
    extern NeoPixel strip3;

    extern int updateCount;

    extern std::vector<Trail*> trails;
    extern std::vector<SlowTrail> slowTrails;
    extern std::vector<DoubleTrail*> doubleTrails;
    extern std::vector<Segment> segments;
    extern std::vector<Dot> dots;

    extern std::vector<Trail*> deadTrails;
    extern std::map<Trail*, int> trailFadesRemainingMap;

    extern std::vector<DoubleTrail*> deadDoubleTrails;
    extern std::map<DoubleTrail*, int> doubleTrailFadesRemainingMap; 

    // Create Shape Functions

    void createTrail(Colour colour, int start, int lifeTime, bool immortal, double speed, int length, bool hasDeathEffect, bool mergeColours);
    void createSlowTrail(Colour colour, int start, int lifeTime, bool immortal, int speed, bool hasDeathEffect, bool mergeColours);
    void createDoubleTrail(Colour colour, int start, int trailLength, int speed, int lifeTime, bool immortal, bool deathEffect, bool mergeColours);
    void createSegment(int segmentID, std::vector<Colour> colours, int startIndex);
    void createDot(Colour colour, int start, int lifeTime);
    void createDrawing(Colour colour, std::vector<int> segments);
    void createCircle(Colour colour, int hubID, int lifeTime);

    // Shape Functions

    int getNumTrails();
    int getNumSlowTrails();
    int getNumDoubleTrails();
    int getNumSegments();
    int getNumDots();

    void clearSegments();

    // Strip Functions

    void off();
    void test();
    void fill(Colour colour);
    void writeUpdates();

    // void minorFadeAll();
    // void fadeAll();
    // void superFadeAll();
    void doUpdate();

    double getCurrent();
    double getActualCurrent();
    double calculateBrightnessLimit();
    void setBrightness();
    // int getNumOnLEDs();

    NeoPixel& getStrip(int stripID);
    Colour getLED(int stripID, int index);
    Colour getLED(int ledNumber);

    void fadeLED(int stripID, int index, double amount);
    void fadeLED(int ledNumber, double amount);

    void setLEDColour(int stripID, int index, Colour colour);
    void setLEDColour(int ledNumber, Colour colour);

    void addToLEDColour(int stripID, int index, Colour colour);
    void addToLEDColour(int ledNumber, Colour colour);
}