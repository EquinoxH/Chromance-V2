#include "embers.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Embers{
        namespace{
            int lastSpawnLocationIndex;
            
            void spawnEmber(){
                if(Chromance::getNumSlowTrails() >= numEmbers) return;
                if(Utils::getMillisecondsSinceLog() < spawnDelay) return;

                int spawnLocationIndex = Random::getRandomIntExcept(spawnLocations.size(), lastSpawnLocationIndex);
                int spawnLocation = spawnLocations[spawnLocationIndex];

                Chromance::createSlowTrail(Colours::orangeRed, spawnLocation, 12, false, speed, false, false);
                Utils::logCurrentTime();
                lastSpawnLocationIndex = spawnLocationIndex;
            }
        }
        
        void setProfile(){
            Chromance::off();
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::embers;
            Utils::logCurrentTime();
            lastSpawnLocationIndex = -1;
        }

        void doUpdate(){
            spawnEmber();
        }
    }
}