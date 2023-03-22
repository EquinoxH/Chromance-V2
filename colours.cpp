#include "colours.h"
#define PIXEL_MAX_CURRENT 55

double Colour::calculateCurrent(){
    return PIXEL_MAX_CURRENT * (r + g + b) / (3 * 255);
}

Colour::Colour(int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
}

Colour Colour::getColourAtBrightness(double brightness){
    return Colour((int)(r * brightness), (int)(g * brightness), (int)(b * brightness));
}

bool Colour::isOff(){
    return r == 0 && g == 0 && b == 0;
}