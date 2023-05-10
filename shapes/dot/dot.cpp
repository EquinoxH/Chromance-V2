#include "dot.h"
#include "chromance.h"

Dot::Dot(Colour _colour, int _location, int _lifeTime){
    colour = _colour;
    location = _location;
    lifeTime = _lifeTime;
    startLifeTime = _lifeTime;
}

void Dot::show(){
    Chromance::setLEDColour(location, colour);
    Chromance::fadeLED(location, 1 - (lifeTime / (double)startLifeTime));
}

void Dot::update(){
    --lifeTime;
    show();
}

bool Dot::shouldDie(){
    return lifeTime == 0;
}