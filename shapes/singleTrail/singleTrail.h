#pragma once

#include "colours.h"
#include "shapes/trail/trail.h"
#include <vector>

class SingleTrail : public Trail{
public:
    SingleTrail(Colour _colour, int _start, int _lifeTime, bool _immortal, int _speed, int _length, bool _deathEffect, bool _mergeMode);
    void moveWithSpeed();
    void move() override;
    void show() override;
    void fade() override;
};