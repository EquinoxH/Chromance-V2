#include "trail.h"

void Trail::move(){}
void Trail::show(){}
void Trail::fade(){}

int Trail::getCurrentPosition(){
    return currentPosition;
}

int Trail::getCurrentDirection(){
    return direction;
}

bool Trail::shouldDie(){
    return lifeTime == 0;
}

bool Trail::hasDeathEffect(){
    return deathEffect;
}