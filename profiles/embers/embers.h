#pragma once

#include <vector>

namespace Profiles{
    namespace Embers{
        const int numEmbers = 20;
        const int speed = 5;
        const int spawnDelay = 250;
        const std::vector<int> spawnLocations{ 55, 0, 307, 252, 210, 322, 532, 112, 167, 434, 182, 504 };

        void setProfile();
        void doUpdate();
    }
}