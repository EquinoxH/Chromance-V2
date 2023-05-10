#pragma once

#include <vector>

namespace Profiles{
    namespace Fireworks{
        const std::vector<int> spawnLocations{210, 0, 322, 307, 532, 112, 182, 167, 504, 434};

        void setProfile();
        void doUpdate();
        void onDeath(int deathLocation);
    }
}