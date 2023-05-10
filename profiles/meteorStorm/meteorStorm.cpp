#include "meteorStorm.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace MeteorStorm{
        
        // Private Variables And Functions
        namespace{
            int lastSpawnLocationIndex;
            int lastColourIndex;

            void spawnMeteor(){
                int locationIndex = Random::getRandomIntExcept(spawnLocations.size(), lastSpawnLocationIndex);
                int colourIndex = Random::getRandomIntExcept(colours.size(), lastColourIndex);

                int spawnLocation = spawnLocations[locationIndex];
                Colour colour = colours[colourIndex];

                Chromance::createTrail(colour, spawnLocation, 12, false, 3, 14, false, false);
                lastColourIndex = colourIndex;
                lastSpawnLocationIndex = locationIndex;
            }
        }

        // Public Functions

        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::meteorStorm;
            lastColourIndex = -1;
        }

        void doUpdate(){
            spawnMeteor();
        }
    }
}