#pragma once

#include "colours.h"
#include <vector>

namespace Profiles{
    namespace Heart{
        const std::vector<int> segments{23, 27, 16, 15, 8, 7, 6, 29, 30, 31, 38, 28, 24};
        const std::vector<Colour> colours{
            Colours::hotPink,
            Colours::lightCoral,
            Colours::deepPink,
            Colours::fuchsia,
            Colours::magenta,
            Colours::violet,
            Colours::magenta,
            Colours::fuchsia,
            Colours::deepPink,
            Colours::lightCoral
        };

        void setProfile();
        void doUpdate();
    }
}