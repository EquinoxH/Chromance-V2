#pragma once

#include "colours.h"

class SlowTrail{
private:
    Colour colour;
    int currentPosition;
    int targetPosition;
    int lifeTime;
    bool isAtStart;
    bool immortal;
    int direction;
    int speed;
    int progress;
    bool deathEffect;
    bool mergeMode;

public:
    SlowTrail(Colour _colour, int _start, int _lifeTime, int _immortal, int _speed, bool _deathEffect, bool _mergeMode);
    void move();
    void show();

    int getCurrentPosition();
    int getCurrentDirection();
    bool shouldDie();
    bool hasDeathEffect();
};