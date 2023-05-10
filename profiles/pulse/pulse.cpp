#include "pulse.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Pulse{
        namespace{

            int lastHub;
            int lastLife;
            
            void spawnPulse(){
                if(Chromance::getNumTrails() > 1) return;

                Colour colour = Colours::getRandomColour();
                Hub hub = Hubs::getRandomExcept(lastHub);

                if(bigMode) {
                    while(hub.getLEDs().size() < 4){
                        hub = Hubs::getRandomExcept(lastHub);
                    }
                }

                std::vector<int> leds = hub.getLEDs();

                for(int i = 0; i < leds.size(); i++){
                    int lifeTime = Random::getRandomIntExcept(14, 43, lastLife);
                    int led = leds[i];

                    Chromance::createTrail(colour, led, lifeTime, false, 1, 14, false, false);
                    lastHub = hub.getID();
                    lastLife = lifeTime;
                }
            }

            void spawnFirstPulse(){
                std::vector<int> leds = Hubs::getHub(15).getLEDs();
                for(int i = 0; i < leds.size(); i++){
                    int lifeTime = Random::getRandomIntExcept(14, 43, lastLife);
                    int led = leds[i];

                    Chromance::createTrail(Colours::blue, led, lifeTime, false, 1, 14, false, false);
                    lastHub = 15;
                    lastLife = lifeTime;
                }
            }
        }

        // Public Functions

        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::pulse;
            Chromance::speed = 10;
            lastLife = 0;
            lastHub = 0;
            spawnFirstPulse();
        }

        void doUpdate(){
            spawnPulse();
        }
    }
}