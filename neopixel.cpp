#include "neopixel.h"
#include "colours.h"
#include "chromance.h"
#include "debugTools.h"

// Constructor

NeoPixel::NeoPixel(int gpioPin, int leds){
    pin = gpioPin;
    numLEDs = leds;
    stripBrightness = 1;

    for(int i = 0; i < numLEDs; i++){
        trueColours.push_back(Colours::off);
        pixelBrightnessValues.push_back(1);
        coloursToSum.push_back(std::vector<Colour>());
    }

    initialisePin();
    writeUpdates();
}

// Public Functions

double NeoPixel::getCurrent(){
    double totalCurrent = 0;
    for(Colour pixel: trueColours){
        totalCurrent += pixel.calculateCurrent();
    }

    return totalCurrent;
}

double NeoPixel::getActualCurrent(){
    double totalCurrent = 0;
    for(int i = 0; i < numLEDs; i++){
        totalCurrent += trueColours[i].calculateCurrent() * pixelBrightnessValues[i] * stripBrightness;
    }

    return totalCurrent;
}

Colour NeoPixel::getPixelColour(int index){
    switch(Chromance::displayMode){
        case Chromance::absolute: return trueColours[index];
        case Chromance::blend: return Colours::sumColours(coloursToSum[index]);
    }
}

double NeoPixel::getPixelBrightness(int index){
    return pixelBrightnessValues[index];
}

void NeoPixel::setPixelColour(int index, Colour colour){
    trueColours[index] = colour;
    pixelBrightnessValues[index] = 1;
}

void NeoPixel::setPixelBrightness(int index, double brightness){
    pixelBrightnessValues[index] = brightness;
}

void NeoPixel::setStripBrightness(double brightness){
    stripBrightness = brightness;
}

void NeoPixel::addToPixelColour(int index, Colour colour){
    coloursToSum[index].push_back(colour);
}

void NeoPixel::off(){
    fill(Colours::off);
}

void NeoPixel::test(){
    fill(Colours::test);
}

void NeoPixel::writeUpdates(){
    setActivePin();
    sleep_ms(1);
    for(int i = 0; i < numLEDs; i++){
        double pixelBrightness = getPixelBrightness(i);
        Colour colour = getPixelColour(i).getColourAtBrightness(pixelBrightness * stripBrightness);
        putPixel(urgbToU32(colour));
    }

    if(debugBlendMode && pin == 0){
        printf("coloursToSum:\n");
        printf("[\n");
        for (size_t i = 0; i < coloursToSum.size(); i++) {
            printf("  [\n");
            for (size_t j = 0; j < coloursToSum[i].size(); j++) {
                const auto& colour = coloursToSum[i][j];
                printf("    {\"r\": %d, \"g\": %d, \"b\": %d}", colour.r, colour.g, colour.b);
                if (j < coloursToSum[i].size() - 1) {
                    printf(",");
                }
                printf("\n");
            }
            printf("  ]");
            if (i < coloursToSum.size() - 1) {
                printf(",");
            }
            printf("\n");
        }
        printf("]\n");
    }

    for(std::vector<Colour> colours: coloursToSum){
        colours.clear();
    }
}

void NeoPixel::fill(Colour colour){
    for (int i = 0; i < numLEDs; i++){
        setPixelColour(i, colour);
    }
}

void NeoPixel::fadePixel(int index, double amount){
    double brightness = getPixelBrightness(index);
    if(brightness <= 0) return;

    brightness -= amount;
    if(brightness > 0){
        setPixelBrightness(index, brightness);
    }
    else{
        setPixelColour(index, Colours::off);
    }
}

void NeoPixel::minorFadeAll(){
    for(int i = 0; i < numLEDs; i++){
        fadePixel(i, 0.02);
    }
}

void NeoPixel::fadeAll(){
    for(int i = 0; i < numLEDs; i++){
        fadePixel(i, 0.1);
    }
}

void NeoPixel::superFadeAll(){
    for(int i = 0; i < numLEDs; i++){
        fadePixel(i, 0.5);
    }
}

// Private Functions

void NeoPixel::initialisePin(){
    PIO pio = pio0;
    int sm = 0;
    storedOffset = pio_add_program(pio, &ws2812_program);
    uint offset = storedOffset;
    ws2812_program_init(pio, sm, offset, pin, 800000, false);
}

void NeoPixel::setActivePin(){
    ws2812_program_init(pio0, 0, storedOffset, pin, 800000, false);
}

void NeoPixel::putPixel(uint32_t pixelRGB){
    pio_sm_put_blocking(pio0, 0, pixelRGB << 8u);
}

uint32_t NeoPixel::urgbToU32(uint8_t r, uint8_t g, uint8_t b){
    return ((uint32_t)(r) <<  8) |
           ((uint32_t)(g) << 16) |
            (uint32_t)(b);
}

uint32_t NeoPixel::urgbToU32(Colour colour){
    return ((uint32_t)(colour.r) <<  8) |
           ((uint32_t)(colour.g) << 16) |
            (uint32_t)(colour.b);
}