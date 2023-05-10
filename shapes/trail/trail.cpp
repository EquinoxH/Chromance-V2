#include "trail.h"
#include "hub.h"
#include "chromance.h"
#include "debugTools.h"

// Constructor

Trail::Trail(Colour _colour, int _start, int _lifeTime, bool _immortal, int _speed, int _length, bool _deathEffect, bool _mergeMode){
    colour = _colour;
    currentPosition = _start;
    direction = _start % 2 == 0 ? 1 : -1;
    length = _length;
    lifeTime = _lifeTime;
    fadeProgress = 0;
    isAtStart = true;
    immortal = _immortal;
    speed = _speed;
    deathEffect = _deathEffect;
    mergeMode = _mergeMode;

    positionHistory.push_back(_start);
}

// Public Functions

void Trail::moveWithSpeed(){
    for(int i = 0; i < speed; i++){
        move();
    }
}

void Trail::move(){
    if(!immortal) --lifeTime;

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
    if(positionHistory.size() >= length){
        positionHistory.erase(positionHistory.begin());
    }
    
    show();
}

void Trail::show(){
    for(int i = 0; i < positionHistory.size(); i++){
        double brightness = i / (double)length;
        if(mergeMode){
           Chromance::addToLEDColour(positionHistory[i], colour.getColourAtBrightness(brightness));
        }
        else{
            Chromance::setLEDColour(positionHistory[i], colour.getColourAtBrightness(brightness));
        }
    }
}

void Trail::fade(){
    fadeProgress += 0.1;
    for(int i = 0; i < positionHistory.size(); i++){
        double brightness = i / (double)length;
        brightness *= (1 - fadeProgress);
        if(mergeMode){
           Chromance::addToLEDColour(positionHistory[i], colour.getColourAtBrightness(brightness));
        }
        else{
            Chromance::setLEDColour(positionHistory[i], colour.getColourAtBrightness(brightness));
        }
    }
}

int Trail::getCurrentPosition(){
    return currentPosition;
}

int Trail::getCurrentDirection(){
    return direction;
}

bool Trail::shouldDie(){
    return lifeTime == 0;
}

bool Trail::hasDeathEffect(){
    return deathEffect;
}