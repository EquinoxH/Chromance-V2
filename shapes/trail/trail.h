#pragma once

#include "colours.h"
#include <vector>

class Trail{
private:
    Colour colour;
    int currentPosition;
    int direction;
    int lifeTime;
    double fadeProgress;
    double speed;
    int length;
    bool isAtStart;
    bool immortal;
    bool deathEffect;
    bool mergeMode;
    std::vector<int> positionHistory;

public:
    Trail(Colour _colour, int _start, int _lifeTime, bool _immortal, int _speed, int _length, bool _deathEffect, bool _mergeMode);
    void moveWithSpeed();
    void move();
    void show();
    void fade();

    int getCurrentPosition();
    int getCurrentDirection();
    
    bool shouldDie();
    bool hasDeathEffect();
};