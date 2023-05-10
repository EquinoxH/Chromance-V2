#include "fireworks.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Fireworks{

        // Private Variables And Functions
        namespace{
            int spawnDelay;
            int lastSpawnLocationIndex;
            Colour nextColour;

            void spawnFirework(){
                if(Utils::getMillisecondsSinceLog() < spawnDelay) return;

                nextColour = Colours::getRandomColour();
                int spawnIndex = Random::getRandomIntExcept(spawnLocations.size(), lastSpawnLocationIndex);
                int spawnLocation = spawnLocations[spawnIndex];

                Chromance::createTrail(Colours::red, spawnLocation, 12, false, 1, 14, true, false);
                lastSpawnLocationIndex = spawnIndex;
                Utils::logCurrentTime();
            }

            void spawnPulse(int deathLocation){
                Hub hub = Hubs::getConnectedHub(deathLocation);
                std::vector<int> leds = hub.getLEDs();
                for(int i = 0; i < leds.size(); i++){
                    Chromance::createTrail(nextColour, leds[i], 13, false, 1, 14, false, false);
                }
            }
        }

        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::fireworks;
            Utils::logCurrentTime();
            lastSpawnLocationIndex = -1;
            spawnDelay = 400;
        }

        void doUpdate(){
            spawnFirework();
        }

        void onDeath(int deathLocation){
            spawnPulse(deathLocation);
        }
    }
}