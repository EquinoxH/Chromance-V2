#include "myRandom.h"
#include <stdlib.h>

namespace Random{
    void initialise(){
        srand(0);
    }

    int getRandomInt(int max){
        return rand() % max;
    }

    int getRandomInt(int min, int max){
        int difference = max - min;
        int random = rand() % difference;
        return min + random;
    }

    int getRandomIntExcept(int max, int exclusion){
        int random = getRandomInt(max);
        while(random == exclusion){
            random = getRandomInt(max);
        }

        return random;
    }

    int getRandomIntExcept(int min, int max, int exclusion){
        int random = getRandomInt(min, max);
        while(random == exclusion){
            random = getRandomInt(min, max);
        }

        return random;
    }

    double getRandomDouble(double max){
        double ratio = rand() / RAND_MAX;
        return ratio * max;
    }

    double getRandomDouble(double min, double max){
        double ratio = rand() / RAND_MAX;
        return min + ratio * (max - min);
    }

    double getRandomDoubleExcept(double max, double exclusion){
        double random = getRandomDouble(max);
        while(random == exclusion){
            random = getRandomDouble(max);
        }

        return random;
    }

    double getRandomDoubleExcept(double min, double max, double exclusion){
        double random = getRandomDouble(min, max);
        while(random == exclusion){
            random = getRandomDouble(min, max);
        }

        return random;
    }
}