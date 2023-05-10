#include "doubleTrail.h"
#include "hub.h"
#include "chromance.h"
#include "debugTools.h"

#include <math.h>

// Constructor

DoubleTrail::DoubleTrail(Colour _colour, int _start, int _trailLength, int _speed, int _lifeTime, bool _immortal, bool _deathEffect, bool _mergeMode){
    colour = _colour;
    currentPosition = _start;
    trailLength = _trailLength;
    speed = _speed;
    lifeTime = _lifeTime;
    immortal = _immortal;
    deathEffect = _deathEffect;
    mergeMode = _mergeMode;

    positionHistory.push_back(currentPosition);
    direction = _start % 2 == 0 ? 1 : -1;
    isAtStart = true;
    deviation = trailLength / 8.0;
}

// Public Functions

void DoubleTrail::moveWithSpeed(){
    for(int i = 0; i < speed; i++){
        move();
    }
}

void DoubleTrail::move(){
    int nextPosition = 0;
    if (Hubs::ledIsStartOrEnd(currentPosition) && !isAtStart){
        Hub currentHub = Hubs::getConnectedHub(currentPosition);
        nextPosition = currentHub.getRandomLEDExcept(currentPosition);
        direction = nextPosition % 2 == 0 ? 1 : -1;
        isAtStart = true;
    }
    else{
        nextPosition = currentPosition + direction;
        isAtStart = false;
    }

    currentPosition = nextPosition;
    positionHistory.push_back(currentPosition);
    if(positionHistory.size() > trailLength){
        positionHistory.erase(positionHistory.begin());
    }

    show();
    
    if(!immortal){
        --lifeTime;
    }
}

void DoubleTrail::show(){
    for(int i = 0; i < positionHistory.size(); i++){
        double brightness = getBrightnessAtPosition(i);
        if(!mergeMode){
            // Fade To BG Colour
            int rDiff = colour.r - Chromance::backgroundColour.r;
            int gDiff = colour.g - Chromance::backgroundColour.g;
            int bDiff = colour.b - Chromance::backgroundColour.b;

            int r = Chromance::backgroundColour.r + brightness * rDiff;
            int g = Chromance::backgroundColour.g + brightness * gDiff;
            int b = Chromance::backgroundColour.b + brightness * bDiff;

            Chromance::setLEDColour(positionHistory[i], Colour(r, g, b));
        }
        else{
            Chromance::addToLEDColour(positionHistory[i], colour.getColourAtBrightness(brightness));
        }
    }
}

void DoubleTrail::fade(){
    fadeProgress += 0.1;
    for(int i = 0; i < positionHistory.size(); i++){
        double brightness = getBrightnessAtPosition(i);
        brightness *= (1 - fadeProgress);
        if(mergeMode){
           Chromance::addToLEDColour(positionHistory[i], colour.getColourAtBrightness(brightness));
        }
        else{
            // Fade To BG Colour
            int rDiff = colour.r - Chromance::backgroundColour.r;
            int gDiff = colour.g - Chromance::backgroundColour.g;
            int bDiff = colour.b - Chromance::backgroundColour.b;

            int r = Chromance::backgroundColour.r + brightness * rDiff;
            int g = Chromance::backgroundColour.g + brightness * gDiff;
            int b = Chromance::backgroundColour.b + brightness * bDiff;

            Chromance::setLEDColour(positionHistory[i], Colour(r, g, b));
        }
    }
}

int DoubleTrail::getCurrentPosition(){
    return currentPosition;
}

int DoubleTrail::getCurrentDirection(){
    return direction;
}

bool DoubleTrail::shouldDie(){
    return lifeTime == 0;
}

bool DoubleTrail::hasDeathEffect(){
    return deathEffect;
}

// Private Functions

double DoubleTrail::getBrightnessAtPosition(int index){
    // double indexAsDouble = (double)index;
    // double a = (double)trailLength / 2.0;
    // return (-((indexAsDouble - a)*(indexAsDouble - a)) / (a * a)) + 1.0;
    double mean = (trailLength - 1) / 2.0;
    double x = index - mean;
    double exponent = -0.5 * pow(x / deviation, 2);
    double amplitude = 1.0 / (deviation * sqrt(2 * M_PI));
    double brightness = amplitude * exp(exponent);  // apply the Gaussian function
    if (index == 0 || index == trailLength - 1) {
        brightness = 0.0;
    } else {
        brightness /= amplitude;
    }
    return brightness;
}