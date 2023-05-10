#include "slowTrail.h"
#include "hub.h"
#include "chromance.h"
#include "debugTools.h"

// Constructor

SlowTrail::SlowTrail(Colour _colour, int _start, int _lifeTime, int _immortal, int _speed, bool _deathEffect, bool _mergeMode){
    colour = _colour;
    currentPosition = _start;
    targetPosition = -1;
    direction = _start % 2 == 0 ? 1 : -1;
    lifeTime = _lifeTime;
    isAtStartOfSegment = true;
    immortal = _immortal;
    speed = _speed;
    progress = 0;
    deathEffect = _deathEffect;
    mergeMode = _mergeMode;
}

// Public Functions

void SlowTrail::move(){
    if(debugSlowTrails) printf("Current Position: %d\n", currentPosition);

    // Find Next Position
    bool arrivedAtHub = false;
    if(targetPosition == -1){
        if(Hubs::ledIsStartOrEnd(currentPosition) && !isAtStartOfSegment){
            printf("Arrived at hub\n");
            Hub currentHub = Hubs::getConnectedHub(currentPosition);
            targetPosition = currentHub.getRandomLEDExcept(currentPosition);
            arrivedAtHub = true;
            if(debugSlowTrails) printf("Picked New Hub Target: %d\n", targetPosition);
        }
        else{
            targetPosition = currentPosition + direction;
            if(debugSlowTrails) printf("Picked New Target: %d = %d + %d\n", targetPosition, currentPosition, direction);
        }
    }

    progress += speed;
    Chromance::setLEDColour(currentPosition, colour.getColourAtBrightness(1 - (progress / 100.0)));
    Chromance::setLEDColour(targetPosition, colour.getColourAtBrightness(progress / 100.0));

    if(progress == 100){
        isAtStartOfSegment = Hubs::ledIsStartOrEnd(currentPosition) && Hubs::ledIsStartOrEnd(targetPosition);

        currentPosition = targetPosition;
        targetPosition = -1; 
        progress = 0;

        if(isAtStartOfSegment) direction = currentPosition  % 2 == 0 ? 1 : -1;
        if(!immortal) --lifeTime;
    }
}

void SlowTrail::show(){
    if(mergeMode){
        Chromance::addToLEDColour(currentPosition, colour);
    }
    else{
        Chromance::setLEDColour(currentPosition, colour); // check this
    }
}