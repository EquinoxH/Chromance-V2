#include "profileManager.h"
#include "chromance.h"
#include "debugTools.h"
#include "utils.h"

#include <algorithm>
#include <string>
#include <chrono>

namespace Chromance{
    const double currentLimit = debugMode ? 500.0 : 9600.0;
    int speed = 10;
    int fps = 60;
    bool trackCurrent = false;
    std::string profile = "rgb";
    DisplayMode displayMode = absolute;
    Colour backgroundColour = Colours::off;

    NeoPixel strip0(0, 84);
    NeoPixel strip1(2, 154);
    NeoPixel strip2(4, 168);
    NeoPixel strip3(6, 154);

    std::vector<SingleTrail*> trails;
    std::vector<SlowTrail> slowTrails;
    std::vector<DoubleTrail*> doubleTrails;
    std::vector<Segment> segments;
    std::vector<Dot> dots;

    std::vector<SingleTrail*> deadTrails;
    std::map<SingleTrail*, int> trailFadesRemainingMap;

    std::vector<DoubleTrail*> deadDoubleTrails;
    std::map<DoubleTrail*, int> doubleTrailFadesRemainingMap;

    // Create Shape Functions

    void createTrail(Colour colour = Colours::red, int start = 0, int lifeTime = 140, bool isImmortal = false, double speed = 1, int length = 14, bool hasDeathEffect = false, bool mergeColours = true){
        trails.push_back(new SingleTrail(colour, start, lifeTime, isImmortal, speed, length, hasDeathEffect, mergeColours));
    }

    void createSlowTrail(Colour colour = Colours::red, int start = 0, int lifeTime = 140, bool isImmortal = false, int speed = 10, bool hasDeathEffect = false, bool mergeColours = true){
        slowTrails.push_back(SlowTrail(colour, start, lifeTime, isImmortal, speed, hasDeathEffect, mergeColours));
    }

    void createDoubleTrail(Colour colour = Colours::red, int start = 0, int trailLength = 20, int speed = 1, int lifeTime = 140, bool immortal = false, bool deathEffect = false, bool mergeColours = false){
        doubleTrails.push_back(new DoubleTrail(colour, start, trailLength, speed, lifeTime, immortal, deathEffect, mergeColours));
    }

    void createSegment(int segmentID = 0, std::vector<Colour> colours = std::vector<Colour>{Colours::red}, int startIndex = 0){
        segments.push_back(Segment(segmentID, colours, startIndex));
    }

    void createDot(Colour colour = Colours::red, int start = 0, int lifeTime = 140){
        dots.push_back(Dot(colour, start, lifeTime));
    }

    void createDrawing(Colour colour = Colours::red, std::vector<int> segments = std::vector<int>()){

    }

    void createCircle(Colour colour = Colours::red, int hubID = 0, int lifeTime = 10){

    }

    // Shape Functions

    int getNumTrails(){
        return trails.size();
    }

    int getNumSlowTrails(){
        return slowTrails.size();
    }

    int getNumDoubleTrails(){
        return doubleTrails.size();
    }

    int getNumSegments(){
        return segments.size();
    }

    int getNumDots(){
        return dots.size();
    }

    void clearSegments(){
        if(segments.size() > 0){
            off();
            segments = std::vector<Segment>();
        }
    }

    // Strip Functions

    void off(){
        strip0.off();
        strip1.off();
        strip2.off();
        strip3.off();
    }   

    void test(){
        strip0.test();
        strip1.test();
        strip2.test();
        strip3.test();
    }   

    void fill(Colour colour){
        strip0.fill(colour);
        strip1.fill(colour);
        strip2.fill(colour);
        strip3.fill(colour);
    }

    void writeUpdates(){
        sleep_ms(1);
        strip0.writeUpdates();
        sleep_ms(1);
        strip1.writeUpdates();
        sleep_ms(1);
        strip2.writeUpdates();
        sleep_ms(1);
        strip3.writeUpdates();
    }

    // void minorFadeAll(){
    //     strip0.minorFadeAll();
    //     strip1.minorFadeAll();
    //     strip2.minorFadeAll();
    //     strip3.minorFadeAll();
    // }

    // void fadeAll(){
    //     strip0.fadeAll();
    //     strip1.fadeAll();
    //     strip2.fadeAll();
    //     strip3.fadeAll();
    // }

    // void superFadeAll(){
    //     strip0.superFadeAll();
    //     strip1.superFadeAll();
    //     strip2.superFadeAll();
    //     strip3.superFadeAll();
    // }

    // Update Shape Functions
    namespace{
        void updateTrails(){
            for(int i = 0; i < trails.size(); i++){
                SingleTrail* trail = trails[i];
                trail->moveWithSpeed();
                if(trail->shouldDie()){
                    if(trail->hasDeathEffect()){
                        int position = trail->getCurrentPosition() + trail->getCurrentDirection();
                        ProfileManager::onDeath(profile, position);
                    }

                    deadTrails.push_back(trail);
                    trailFadesRemainingMap[trail] = 10;
                    if(debugDeadTrails) printf("Adding trail %p to dead trails\n", trail);
                    trails.erase(trails.begin() + i);
                }
            }
        }

        void updateSlowTrails(){
            for(int i = 0; i < slowTrails.size(); i++){
                slowTrails[i].move();
                if(slowTrails[i].shouldDie()){
                    if(slowTrails[i].hasDeathEffect()){
                        int position = slowTrails[i].getCurrentPosition() + slowTrails[i].getCurrentDirection();
                        ProfileManager::onDeath(profile, position);
                    }
                    Chromance::setLEDColour(slowTrails[i].getCurrentPosition(), Colours::off);
                    slowTrails.erase(slowTrails.begin() + i);
                }
            }
        }

        void updateDoubleTrails(){
            for(int i = 0; i < doubleTrails.size(); i++){
                DoubleTrail* trail = doubleTrails[i];
                trail->moveWithSpeed();
                if(trail->shouldDie()){
                    if(trail->hasDeathEffect()){
                        int position = trail->getCurrentPosition() + trail->getCurrentDirection();
                        ProfileManager::onDeath(profile, position);
                    }

                    deadDoubleTrails.push_back(trail);
                    doubleTrailFadesRemainingMap[trail] = 10;
                    doubleTrails.erase(doubleTrails.begin() + i);
                }
            }
        }

        void updateSegments(){
            for(int i = 0; i < segments.size(); i++){
                segments[i].update();
            }
        }

        void updateDots(){
            for(int i = 0; i < dots.size(); i++){
                dots[i].update();
                if(dots[i].shouldDie()){
                    dots.erase(dots.begin() + i);
                }
            }
        }
    
        void fadeDeadTrails(){
            if(debugDeadTrails) printf("Fading %d dead trails\n", deadTrails.size());
            for(int i =  0; i < deadTrails.size(); i++){
                SingleTrail* trail = deadTrails[i];

                trail->fade();
                --trailFadesRemainingMap[trail];

                //if(i == 0 && debugDeadTrails) printf("Trail %p has %d fades remaining\n", trail, fadesRemaining);

                if(trailFadesRemainingMap[trail] <= 0){
                    trailFadesRemainingMap.erase(trail);
                    deadTrails.erase(deadTrails.begin() + i);
                    delete trail;
                }
            }
        }

        void fadeDeadDoubleTrails(){
            for(int i = 0; i < deadDoubleTrails.size(); i++){
                DoubleTrail* trail = deadDoubleTrails[i];
                trail->fade();
                --doubleTrailFadesRemainingMap[trail];

                if(doubleTrailFadesRemainingMap[trail] <= 0){
                    doubleTrailFadesRemainingMap.erase(trail);
                    deadDoubleTrails.erase(deadDoubleTrails.begin() + i);
                    delete trail;
                }
            }
        }
    }

    void doUpdate(){
        auto start = std::chrono::high_resolution_clock::now();

        fill(backgroundColour);

        updateTrails();
        updateSlowTrails();
        updateDoubleTrails();
        updateSegments();
        updateDots();

        fadeDeadTrails();
        fadeDeadDoubleTrails();

        ProfileManager::doUpdate(profile);
        setBrightness();
        writeUpdates();

        auto end = std::chrono::high_resolution_clock::now();
        double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        double frameDelay = 1000 / (double)fps;

        if(elapsed < frameDelay){
            sleep_ms(frameDelay - elapsed);
        }

        if(debugUpdateTime){
            printf("Updated time: %fms\n", elapsed);
        }

        if(debugCurrent){
            printf("Current: %f\n", getActualCurrent());
        }
    }

    double getCurrent(){
        double current = 0;
        current += strip0.getCurrent();
        current += strip1.getCurrent();
        current += strip2.getCurrent();
        current += strip3.getCurrent();
        return current;
    }

    double getActualCurrent(){
        double current = 0;
        current += strip0.getActualCurrent();
        current += strip1.getActualCurrent();
        current += strip2.getActualCurrent();
        current += strip3.getActualCurrent();
        return current;
    }

    double calculateBrightnessLimit(){
        double current = getCurrent();
        return current < currentLimit ? 1 : currentLimit / current;
    }

    void setBrightness(){
        double brightness = calculateBrightnessLimit();
        strip0.setStripBrightness(brightness);
        strip1.setStripBrightness(brightness);
        strip2.setStripBrightness(brightness);
        strip3.setStripBrightness(brightness);
    }

    NeoPixel& getStrip(int stripID){
        switch(stripID){
            case 0: return strip0;
            case 1: return strip1;
            case 2: return strip2;
            case 3: return strip3;
            default: return strip0;
        }
    }

    Colour getLED(int stripID, int index){
        return getStrip(stripID).getPixelColour(index);
    }

    Colour getLED(int ledNumber){
        int stripID = 0;
        int index = 0;

        if(ledNumber < 84){
            index = ledNumber;
        }
        else if(ledNumber < 238){
            stripID = 1;
            index = ledNumber - 84;
        }
        else if (ledNumber < 406){
            stripID = 2;
            index = ledNumber - 238;
        }
        else{
            stripID = 3;
            index = ledNumber - 406;
        }

        return getLED(stripID, index);
    }

    void fadeLED(int stripID, int index, double amount){
        getStrip(stripID).fadePixel(index, amount);
    }

    void fadeLED(int ledNumber, double amount){
        int stripID = 0;
        int index = 0;

        if(ledNumber < 84){
            index = ledNumber;
        }
        else if(ledNumber < 238){
            stripID = 1;
            index = ledNumber - 84;
        }
        else if (ledNumber < 406){
            stripID = 2;
            index = ledNumber - 238;
        }
        else{
            stripID = 3;
            index = ledNumber - 406;
        }

        fadeLED(stripID, index, amount);
    }

    void setLEDColour(int stripID, int index, Colour colour){
        getStrip(stripID).setPixelColour(index, colour);
    }

    void setLEDColour(int ledNumber, Colour colour){
        int stripID = 0;
        int index = 0;

        if(ledNumber < 84){
            index = ledNumber;
        }
        else if(ledNumber < 238){
            stripID = 1;
            index = ledNumber - 84;
        }
        else if (ledNumber < 406){
            stripID = 2;
            index = ledNumber - 238;
        }
        else{
            stripID = 3;
            index = ledNumber - 406;
        }

        setLEDColour(stripID, index, colour);
    }

    void addToLEDColour(int stripID, int index, Colour colour){
        getStrip(stripID).addToPixelColour(index, colour);
    }

    void addToLEDColour(int ledNumber, Colour colour){
        int stripID = 0;
        int index = 0;

        if(ledNumber < 84){
            index = ledNumber;
        }
        else if(ledNumber < 238){
            stripID = 1;
            index = ledNumber - 84;
        }
        else if (ledNumber < 406){
            stripID = 2;
            index = ledNumber - 238;
        }
        else{
            stripID = 3;
            index = ledNumber - 406;
        }

        addToLEDColour(stripID, index, colour);
    }
}