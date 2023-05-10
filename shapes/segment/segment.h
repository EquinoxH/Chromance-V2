#pragma once

#include "colours.h"
#include <vector>

class Segment{
private:
    std::vector<Colour> colours;
    int currentColour;
    int segmentID;
    int start;
    int progress;
    double gradientDuration;
    void fillSegment(Colour colour);

public:
    Segment(int _segmentID, std::vector<Colour> _colours, int _startIndex);
    void update();
};