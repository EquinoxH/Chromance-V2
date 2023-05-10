#pragma once

#include "colours.h"

class Dot{
private:
    Colour colour;
    int location;
    int lifeTime;
    int startLifeTime;

    void show();

public:
    Dot(Colour _colour, int _location, int _lifeTime);
    
    void update();
    bool shouldDie();
};