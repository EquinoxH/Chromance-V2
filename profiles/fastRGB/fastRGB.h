#pragma once

namespace Profiles{
    namespace FastRGB{
        const int numTrails = 10;
        const int trailLength = 2;
        const int spawnDelay = 250;
        const int trailSpeed = 2;
        const bool blendColours = false;


        void setProfile();
        void doUpdate();
    }
}