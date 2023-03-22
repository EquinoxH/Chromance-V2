#pragma once

class Colour{
public:
    int r, g, b;
    double calculateCurrent();

    Colour(int red, int green, int blue);
    Colour getColourAtBrightness(double brightness);
    bool isOff();
};

namespace Colours{
    const Colour off(0, 0, 0);
    
    const Colour test1(32, 0, 0);
    const Colour test2(0, 32, 0);
    const Colour test3(0, 0, 32);
    const Colour test4(32, 32, 32);
    
    const Colour red(255, 0, 0);
    const Colour blue(0, 0, 255);
}