#include "clouds.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Clouds{
        namespace{ int lastSpawnLocation; }

        void setProfile(){
            Chromance::backgroundColour = backgroundColour;
            Chromance::profile = Profiles::clouds;
            Utils::logCurrentTime();
            lastSpawnLocation = -1;
        }

        void doUpdate(){
            if(Chromance::getNumDoubleTrails() >= numClouds) return;
            if(Utils::getMillisecondsSinceLog() < spawnDelay) return;

            int spawnLocation = Hubs::getRandom().getRandomLEDExcept(lastSpawnLocation);
            Chromance::createDoubleTrail(cloudColour, spawnLocation, cloudLength, cloudSpeed, 140, false, false, false);
            Utils::logCurrentTime();
            lastSpawnLocation = spawnLocation;
        }
    }
}