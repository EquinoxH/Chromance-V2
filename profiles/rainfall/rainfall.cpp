#include "rainfall.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Rainfall{
        namespace {
            int lastSpawnLocationIndex;
            int lastColourIndex;

            void spawnRaindrop(){
                if(Chromance::getNumTrails() >= numRaindrops) return;
                if(Utils::getMillisecondsSinceLog() < spawnDelay) return;

                int spawnLocationIndex = Random::getRandomIntExcept(spawnLocations.size(), lastSpawnLocationIndex);
                int spawnLocation = spawnLocations[spawnLocationIndex];

                int colourIndex = Random::getRandomIntExcept(colours.size(), lastColourIndex);
                Colour colour = colours[colourIndex];

                Chromance::createTrail(colour, spawnLocation, 12, false, 1, 14, false, false);
                Utils::logCurrentTime();

                lastSpawnLocationIndex = spawnLocationIndex;
                lastColourIndex = colourIndex;
            }
        }

        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::rainfall;
            Utils::logCurrentTime();
            lastSpawnLocationIndex = -1;
            lastColourIndex = -1;
        }
        
        void doUpdate(){
            spawnRaindrop();
        }
    }
}