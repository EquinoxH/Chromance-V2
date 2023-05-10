#include "colours.h"
#include "myRandom.h"
#include "debugTools.h"

#include <algorithm>

#define pixelMinCurrent 10
#define pixelMaxCurrent 55

// Constructors

Colour::Colour(){
    r = 0;
    g = 0;
    b = 0;
}

Colour::Colour(int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
}

// Public Functions

double Colour::calculateCurrent(){
    double ratio = (r + g + b) / (double)(3 * 255);
    return pixelMinCurrent + (ratio * (pixelMaxCurrent - pixelMinCurrent));
}

Colour Colour::getColourAtBrightness(double brightness){
    return Colour((int)(r * brightness), (int)(g * brightness), (int)(b * brightness));
}

bool Colour::isOff(){
    return r == 0 && g == 0 && b == 0;
}

std::string Colour::toString(){
    return "(" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ")";
}

// Static Functions

namespace Colours{
    Colour getRandomColour(){
        int r = Random::getRandomInt(256);
        int g = Random::getRandomInt(256);
        int b = Random::getRandomInt(256);
        return Colour(r, g, b);
    }

    Colour sumColours(std::vector<Colour>& colours){
        if(colours.size() == 0) return Colours::off;

        if(debugBlendMode) printf("Summing %d colours\n", colours.size());

        int r = 0;
        int g = 0;
        int b = 0;
    
        for(Colour colour: colours){
            r += colour.r;
            g += colour.g;
            b += colour.b;
        }

        if(debugBlendMode) printf("Sum: (%d,%d,%d)\n", r, g, b);
        Colour result(std::min(r, 255), std::min(g, 255), std::min(b, 255));
        if(debugBlendMode) printf("Result: (%d,%d,%d)\n", result.r, result.g, result.b);
        return result;
    }
}