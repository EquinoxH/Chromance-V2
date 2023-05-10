#pragma once

#include <vector>

namespace Profiles {
    namespace Blossom{
        const int numPetals = 20;
        const int speed = 10;
        const std::vector<int> spawnLocations{
            27, 363, 279,  83, 378, 392,  56, 140, 461, 209, 321, 111, 490, 97
        };

        void setProfile();
        void doUpdate();
    }
}
