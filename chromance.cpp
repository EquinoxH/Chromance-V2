#include "chromance.h"

namespace Chromance{
    const double currentLimit = 9600;
    double speed = 0.001;
    bool trackCurrent = false;
    std::string profile = "rgb";

    NeoPixel strip0(0, 84);
    NeoPixel strip1(2, 154);
    NeoPixel strip2(4, 168);
    NeoPixel strip3(6, 154);

    // Create Shape Functions

    void createTrail(Colour colour = Colours::red, int start = 0, int lifeTime = 140, double speed = 1, bool hasDeathEffect = false){

    }

    void createSegment(Colour colour = Colours::red, int start = 0){

    }

    void createDot(Colour colour = Colours::red, int start = 0, int lifeTime = 140){

    }

    void createDrawing(Colour colour = Colours::red, std::vector<int> segments = std::vector<int>()){

    }

    void createCircle(Colour colour = Colours::red, int hubID = 0, int lifeTime = 10){

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

    void test2(){
        strip0.test2();
        strip1.test2();
        strip2.test2();
        strip3.test2();
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

    void fadeAll(){
        strip0.fadeAll();
        strip1.fadeAll();
        strip2.fadeAll();
        strip3.fadeAll();
    }

    void superFadeAll(){
        strip0.superFadeAll();
        strip1.superFadeAll();
        strip2.superFadeAll();
        strip3.superFadeAll();
    }

    void doUpdate(){
        // ToDo: Call Update Functions
        setBrightness();
        writeUpdates();
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

    NeoPixel getStrip(int stripID){
        switch(stripID){
            case 0: return strip0;
            case 1: return strip1;
            case 2: return strip2;
            case 3: return strip3;
            default: return NeoPixel(0, 5);
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
}