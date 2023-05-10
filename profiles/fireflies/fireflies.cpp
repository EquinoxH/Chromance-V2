#include "fireflies.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Fireflies{
        
        namespace{

            int lastSpawnLocation;
            void spawnFirefly(){
                if(Chromance::getNumDots() >= numFireflies) return;
                if(Utils::getMillisecondsSinceLog() <= spawnDelay) return;

                int spawnLocation = Random::getRandomIntExcept(560, lastSpawnLocation);
                Chromance::createDot(Colours::yellowGreen, spawnLocation, 1);
                lastSpawnLocation = spawnLocation;
                Utils::logCurrentTime();
            }
        }

        // Public Functions

        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::fireflies;
            Utils::logCurrentTime();
            lastSpawnLocation = -1;
        }

        void doUpdate(){
            spawnFirefly();
        }
    }
}