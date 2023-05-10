#include "heart.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Heart{
        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::heart;
        }

        void doUpdate(){
            if(Chromance::getNumSegments() == 0){
                for(int segment: segments){
                    Chromance::createSegment(segment, colours, 0);
                }
            }
        }
    }
}