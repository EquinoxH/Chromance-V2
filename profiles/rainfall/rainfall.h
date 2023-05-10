#pragma once

#include "colours.h"
#include <vector>

namespace Profiles{
    namespace Rainfall{
        const int numRaindrops = 10;
        const int spawnDelay = 50;
        const int trailSpeed = 1;

        const std::vector<int> spawnLocations{
            42, 13, 294, 265, 223, 335, 545, 125, 154, 447, 195, 517
        };
        const std::vector<Colour> colours{
            Colours::aqua,
            Colours::cornflowerBlue,
            Colours::cyan,
            Colours::darkBlue,
            Colours::darkTurquoise,
            Colours::deepSkyBlue,
            Colours::dodgerBlue,
            Colours::lightBlue,
            Colours::lightCyan,
            Colours::lightSkyBlue,
            Colours::lightSteelBlue,
            Colours::mediumBlue,
            Colours::midnightBlue,
            Colours::navy,
            Colours::royalBlue,
            Colours::skyBlue
        };
        
        void setProfile();
        void doUpdate();
    }
}