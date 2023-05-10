#include "aurora.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Aurora{
        namespace{

            int lastSpawnLocation;
            int colourIndex;

            void spawnTrail(){
                if(Chromance::getNumDoubleTrails() >= 3 * numTrailsPerColour) return;
                if(Utils::getMillisecondsSinceLog() < spawnDelay) return;

                int spawnLocation = Hubs::getRandom().getRandomLEDExcept(lastSpawnLocation);
                Colour colour = colours[colourIndex];
                
                Chromance::createDoubleTrail(colour, spawnLocation, trailLength, trailSpeed, 140, false, false, blendColours);
                Utils::logCurrentTime();
                
                lastSpawnLocation = spawnLocation;
                ++colourIndex;
                if(colourIndex == colours.size()){
                    colourIndex = 0;
                }
            }
        }

        void setProfile(){
            Chromance::backgroundColour = Colours::darkOrchid;
            Chromance::profile = Profiles::aurora;
            Utils::logCurrentTime();
            lastSpawnLocation = -1;
            colourIndex = 0;
        }

        void doUpdate(){
            spawnTrail();
        }
    }
}