#pragma once

#include "colours.h"
#include "shapes/trail/trail.h"
#include <vector>

class DoubleTrail : public Trail{
private:
    double deviation;
    double getBrightnessAtPosition(int index);

public:
    DoubleTrail(Colour _colour, int _start, int _length, int _speed, int _lifeTime, bool _immortal, bool _deathEffect, bool _mergeMode);
    void moveWithSpeed();
    void move() override;
    void show() override;
    void fade() override;
};