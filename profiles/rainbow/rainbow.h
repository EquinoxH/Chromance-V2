#pragma once
#include "colours.h"
#include <vector>

namespace Profiles{
    namespace Rainbow{
        const std::vector<int> innerSegments{
            5, 15, 16,
            23, 24, 27,
            28, 38, 39,
            13, 14, 34,
            22, 36, 37,
        };
        const std::vector<int> outerSegments{
            26,  1,  2,  3,  4,  8,  7,  6,
            25, 20, 19, 18, 17, 31, 30, 29,
             0,  9, 10,
            21, 32, 33,
            11, 12, 35
        };
        const std::vector<Colour> colours{
            Colours::red, Colours::orange, Colours::yellow, 
            Colours::lime, Colours::blue, Colours::purple
        };

        void setProfile();
        void doUpdate();
    }
}
