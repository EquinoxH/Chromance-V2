#pragma once

#include "colours.h"
#include <vector>

namespace Profiles{
    namespace PurpleRain{
        const int numRaindrops = 10;
        const int spawnDelay = 50;
        const int trailSpeed = 1;

        const std::vector<int> spawnLocations{
            42, 13, 294, 265, 223, 335, 545, 125, 154, 447, 195, 517
        };
        const std::vector<Colour> colours{
            Colours::blueViolet,
            Colours::darkMagenta,
            Colours::darkSlateBlue,
            Colours::darkViolet,
            Colours::deepPink,
            Colours::fuchsia,
            Colours::hotPink,
            Colours::lavender,
            Colours::lavenderBlush,
            Colours::magenta,
            Colours::mediumOrchid,
            Colours::mediumPurple,
            Colours::mediumVioletRed,
            Colours::orchid,
            Colours::plum,
            Colours::purple,
            Colours::slateBlue,
            Colours::thistle
        };
        
        void setProfile();
        void doUpdate();
    }
}