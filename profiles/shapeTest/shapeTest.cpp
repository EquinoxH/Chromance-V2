#include "shapeTest.h"
#include "profileIncludes.h"

namespace Profiles{
    namespace ShapeTest{
        void doUpdate(){}
        void setProfile(){ 
            Chromance::backgroundColour = Colours::off;
            Chromance::profile = Profiles::shapeTest; 
        }
    }
}