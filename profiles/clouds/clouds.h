#pragma once

#include "colours.h"

namespace Profiles{
    namespace Clouds{
        const int numClouds = 6;
        const int cloudLength = 80;
        const int spawnDelay = 500;
        const int cloudSpeed = 1;

        const Colour cloudColour = Colours::white;
        const Colour backgroundColour = Colours::deepSkyBlue;

        void setProfile();
        void doUpdate();
    }
}