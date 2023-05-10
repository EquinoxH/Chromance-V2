#include "meteor.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Meteor{
        
        // Private Variables And Functions
        namespace{
            int spawnDelay;
            int lastSpawnLocationIndex;
            int lastColourIndex;

            void spawnMeteor(){
                if(Utils::getMillisecondsSinceLog() <= spawnDelay) return;
                
                int locationIndex = Random::getRandomIntExcept(spawnLocations.size(), lastSpawnLocationIndex);
                int colourIndex = Random::getRandomIntExcept(colours.size(), lastColourIndex);

                int spawnLocation = spawnLocations[locationIndex];
                Colour colour = colours[colourIndex];

                Chromance::createTrail(colour, spawnLocation, 12, false, 3, 14, false, false);
                Utils::logCurrentTime();
                lastColourIndex = colourIndex;
                lastSpawnLocationIndex = locationIndex;
                spawnDelay = Random::getRandomInt(500, 1000);
            }
        }

        // Public Functions

        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::meteor;
            Utils::logCurrentTime();
            lastColourIndex = -1;
            spawnDelay = 0;
        }

        void doUpdate(){
            spawnMeteor();
        }
        
    }
}