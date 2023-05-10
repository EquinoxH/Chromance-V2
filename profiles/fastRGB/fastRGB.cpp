#include "fastRGB.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace FastRGB{
        
        namespace{
            
            int lastSpawnLocation;
            void spawnTrails(){
                if(Chromance::getNumTrails() >= numTrails) return;
                if(Utils::getMillisecondsSinceLog() < spawnDelay) return;

                int spawnLocation = Hubs::getRandom().getRandomLEDExcept(lastSpawnLocation);
                Chromance::createTrail(Colours::getRandomColour(), spawnLocation, 70, false, trailSpeed, trailLength, false, blendColours);
                Utils::logCurrentTime();
                lastSpawnLocation = spawnLocation;
            }
        }

        // Public Functions

        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::fastRGB;
            Utils::logCurrentTime();
        }

        void doUpdate(){
            spawnTrails();
        }
    }
}