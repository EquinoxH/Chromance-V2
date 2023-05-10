#pragma once

#include "colours.h"
#include <vector>

namespace Profiles{
    namespace Aurora{
        const int numTrailsPerColour = 5;
        const int trailLength = 40;
        const int spawnDelay = 100;
        const int trailSpeed = 1;
        const bool blendColours = false;

        const std::vector<Colour> colours{Colours::blue, Colours::springGreen};

        void setProfile();
        void doUpdate();
    }
}