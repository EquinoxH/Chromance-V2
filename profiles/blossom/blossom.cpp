#include "blossom.h"
#include "profileIncludes.h"

#include <math.h>

namespace Profiles {
    namespace Blossom{
        namespace{
            
            int spawnDelay = 50;
            int lastSpawnIndex = -1;
            std::chrono::_V2::system_clock::time_point startTime;

            double getTimeSinceStart(){
                auto currentTime = std::chrono::high_resolution_clock::now();
                return std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
            }

            bool shouldSpawnPetal(){
                if(Chromance::getNumTrails() >= numPetals) return false;
                return Utils::getMillisecondsSinceLog() >= spawnDelay;
            }

            void spawnPetal(){
                int spawnLocation = spawnLocations[Random::getRandomIntExcept(spawnLocations.size(), lastSpawnIndex)];
                int red = 255;
                double ratio = ((std::sin(getTimeSinceStart() / 1000) + 1) / 2);
                int greenBlue = (int)(ratio * 64);
                Colour colour(red, greenBlue, greenBlue);

                Chromance::createSlowTrail(colour, spawnLocation, 12, false, speed, false, false);
                Utils::logCurrentTime();
                spawnDelay = Random::getRandomInt(50, 100);
            }
        }

        // Public Functions

        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::blossom;
            Utils::logCurrentTime();
            startTime = std::chrono::high_resolution_clock::now();
        }

        void doUpdate(){
            if(shouldSpawnPetal()){
                spawnPetal();
            }
        }
    }
}
