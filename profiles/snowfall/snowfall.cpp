#include "snowfall.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Snowfall{
        namespace{
            int lastSpawnLocationIndex;

            void spawnFlake(){
                if(Chromance::getNumSlowTrails() >= numFlakes) return;
                if(Utils::getMillisecondsSinceLog() < spawnDelay) return;

                int spawnLocationIndex = Random::getRandomIntExcept(spawnLocations.size(), lastSpawnLocationIndex);
                int spawnLocation = spawnLocations[spawnLocationIndex];

                Chromance::createSlowTrail(Colours::white, spawnLocation, 12, false, 10, false, false);
                Utils::logCurrentTime();
                lastSpawnLocationIndex = spawnLocationIndex;
            }
        }

        void setProfile(){
            Chromance::off();
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::snowfall;
            Utils::logCurrentTime();
            lastSpawnLocationIndex = -1;
        }

        void doUpdate(){
            spawnFlake();
        }
    }
}