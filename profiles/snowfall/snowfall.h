#pragma once

#include <vector>

namespace Profiles{
    namespace Snowfall{
        const int numFlakes = 20;
        const int speed = 5;
        const int spawnDelay = 250;
        const std::vector<int> spawnLocations{ 42, 13, 294, 265, 223, 335, 545, 125, 154, 447, 195, 517 };

        void setProfile();
        void doUpdate();
    }
}