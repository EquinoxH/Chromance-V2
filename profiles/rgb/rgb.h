#pragma once

namespace Profiles{
    namespace RGB{
        const int numTrails = 20;
        const int trailLength = 14;
        const int spawnDelay = 50;
        const int trailSpeed = 1;
        const bool blendColours = false;

        void setProfile();
        void doUpdate();
    }
}