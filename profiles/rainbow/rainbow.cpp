#include "rainbow.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace Rainbow{
        void setProfile(){
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::rainbow;
        }

        void doUpdate(){
            if(Chromance::getNumSegments() == 0){
                for(int segment: outerSegments){
                    Chromance::createSegment(segment, colours, 0);
                }
                for(int segment: innerSegments){
                    Chromance::createSegment(segment, colours, 3);
                }
            }
        }
    }
}
