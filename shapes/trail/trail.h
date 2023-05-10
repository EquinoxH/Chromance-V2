#pragma once

#include "colours.h"
#include <vector>

class Trail{
protected:
    Colour colour;
    int length;
    int lifeTime;
    
    int currentPosition;
    std::vector<int> positionHistory;
    int direction;
    double speed;
    
    double fadeProgress;
    bool isAtStartOfSegment;
    bool immortal;
    bool deathEffect;
    bool mergeMode;

public:
    virtual void move();
    virtual void show();
    virtual void fade();

    int getCurrentPosition();
    int getCurrentDirection();

    bool shouldDie();
    bool hasDeathEffect();
};