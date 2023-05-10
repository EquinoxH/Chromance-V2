#include "flower.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Flower{

        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::flower;
        }

        void doUpdate(){
            if(Chromance::getNumSegments() == 0){
                for(int segment: outerSegments){
                    Chromance::createSegment(segment, outerColours, 0);
                }
                for(int segment: innerSegments){
                    Chromance::createSegment(segment, innerColours, 0);
                }
            }
        }
    }
}