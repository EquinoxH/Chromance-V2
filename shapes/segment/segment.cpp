#include "segment.h"
#include "chromance.h"
#include "debugTools.h"

Segment::Segment(int _segmentID, std::vector<Colour> _colours, int _startIndex){
    colours = _colours;
    currentColour = _startIndex;
    segmentID = _segmentID;
    start = 14 * segmentID;
    progress = 0;
    gradientDuration = 50.0;
}

void Segment::update(){
    if(colours.size() == 1){
        fillSegment(colours[0]);
        return;
    }

    int nextIndex = 0;
    if(currentColour != colours.size() - 1){
        nextIndex = currentColour + 1;
    }

    Colour startColour = colours[currentColour];
    Colour endColour = colours[nextIndex];

    int rDiff = endColour.r - startColour.r;
    int gDiff = endColour.g - startColour.g;
    int bDiff = endColour.b - startColour.b;

    int r = (int)(startColour.r + ((progress / gradientDuration) * rDiff));
    int g = (int)(startColour.g + ((progress / gradientDuration) * gDiff));
    int b = (int)(startColour.b + ((progress / gradientDuration) * bDiff));

    fillSegment(Colour(r, g, b));
    if(segmentID == 0 && debugSegments){
        printf("rDiff: %d = %d - %d\n", rDiff, endColour.r, startColour.r);
        printf("gDiff: %d = %d - %d\n", gDiff, endColour.g, startColour.g);
        printf("bDiff: %d = %d - %d\n", bDiff, endColour.b, startColour.b);
        printf("\n");
        printf("r: %d = (int)(%d + ((%d / %d) * %d))\n", r, startColour.r, progress, gradientDuration, rDiff);
        printf("g: %d = (int)(%d + ((%d / %d) * %d))\n", g, startColour.g, progress, gradientDuration, gDiff);
        printf("b: %d = (int)(%d + ((%d / %d) * %d))\n", b, startColour.b, progress, gradientDuration, bDiff);
        printf("\n");
        printf("Setting Colour: (%d,%d,%d)\n", r, g, b);
    }

    ++progress;
    if(progress > gradientDuration){
        progress = 0;
        currentColour = nextIndex;
    }
}

void Segment::fillSegment(Colour colour){
    for(int i = 0; i < 13; i++){
        int led = start + i;
        Chromance::setLEDColour(led, colour);
    }
}