#pragma once

#define debugMode false

#define debugBlendMode false
#define debugCurrent false
#define debugGeneral false
#define debugProfileManager false
#define debugProfileUpdates false
#define debugUpdateTime false
#define debugUtils false

#define debugDeadTrails false
#define debugDoubleTrails false
#define debugSlowTrails false
#define debugSegments false

namespace DebugTools{
    void blink();
    void blinkNumTimes(int num);
}