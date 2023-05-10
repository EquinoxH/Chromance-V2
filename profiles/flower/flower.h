#pragma once

#include "colours.h"
#include <vector>

namespace Profiles{
    namespace Flower{
        const std::vector<int> innerSegments{23, 33, 22, 11, 34, 10};
        const std::vector<int> outerSegments{24, 21, 32, 37, 36, 35, 12, 13, 14, 9, 0, 27};
        const std::vector<Colour> innerColours{Colours::violet, Colours::magenta, Colours::deepPink, Colours::magenta};
        const std::vector<Colour> outerColours{Colours::springGreen, Colours::lawnGreen, Colours::lime, Colours::lawnGreen};

        void setProfile();
        void doUpdate();
    }
}