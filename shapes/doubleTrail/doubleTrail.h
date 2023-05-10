#pragma once

#include "colours.h"
#include <vector>

class DoubleTrail{
private:
    Colour colour;
    int currentPosition;
    std::vector<int> positionHistory;
    int trailLength;
    double deviation;
    double fadeProgress;
    int speed;
    int direction;
    int lifeTime;
    bool isAtStart;
    bool immortal;
    bool deathEffect;
    bool mergeMode;

    double getBrightnessAtPosition(int index);

public:
    DoubleTrail(Colour _colour, int _start, int _trailLength, int _speed, int _lifeTime, bool _immortal, bool _deathEffect, bool _mergeMode);
    void moveWithSpeed();
    void move();
    void show();
    void fade();

    int getCurrentPosition();
    int getCurrentDirection();
    bool shouldDie();
    bool hasDeathEffect();
};