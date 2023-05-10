#pragma once

#include "colours.h"
#include "shapes/trail/trail.h"

class SlowTrail : public Trail{
private:
    int targetPosition;
    int progress;

public:
    SlowTrail(Colour _colour, int _start, int _lifeTime, int _immortal, int _speed, bool _deathEffect, bool _mergeMode);
    void move() override;
    void show() override;
};