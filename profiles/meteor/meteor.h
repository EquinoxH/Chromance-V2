#pragma once

#include "colours.h"
#include <vector>

namespace Profiles{
    namespace Meteor{
        const std::vector<int> spawnLocations{27, 363, 279, 83, 378, 392, 56, 140, 461, 209, 321, 111, 490, 97};
        const std::vector<Colour> colours{
            Colours::orange,
            Colours::orangeRed,
            Colours::springGreen,
            Colours::crimson,
            Colours::white,
            Colours::yellow
        };

        void setProfile();
        void doUpdate();
    }
}