#include "neopixel.h"
#include "colours.h"
#include "chromance.h"

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

// #include <stdio.h>
// #include <stdlib.h>

// #include "pico/stdlib.h"
// #include "hardware/pio.h"
// #include "hardware/clocks.h"
// #include "ws2812.pio.h"

// void blink(int num){
//     for(int i = 0; i < num; i++) {
//         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
//         sleep_ms(250);
//         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
//         sleep_ms(250);
//     }
// }

// Constructor

NeoPixel::NeoPixel(int gpioPin, int leds){
    pin = gpioPin;
    numLEDs = leds;
    stripBrightness = 1;

    for(int i = 0; i < numLEDs; i++){
        trueColours.push_back(Colours::off);
        pixelBrightnessValues.push_back(1);
    }

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
    return trueColours[index];
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

void NeoPixel::off(){
    fill(Colours::off);
}

void NeoPixel::test(){
    fill(Colours::test1);
}

void NeoPixel::test2(){
    fill(Colours::test2);
}

void NeoPixel::writeUpdates(){
    initialisePin();
    sleep_ms(1);
    for(int i = 0; i < numLEDs; i++){
        double pixelBrightness = getPixelBrightness(i);
        Colour colour = getPixelColour(i).getColourAtBrightness(pixelBrightness * stripBrightness);
        putPixel(urgbToU32(colour));
    }
}

void NeoPixel::fill(Colour colour){
    for (int i = 0; i < numLEDs; i++){
        setPixelColour(i, colour);
    }
}

void NeoPixel::fadePixel(int index, double amount){
    double brightness = getPixelBrightness(index);
    if(brightness < amount) return;

    brightness -= amount;
    setPixelBrightness(index, brightness);
}

void NeoPixel::fadeAll(){
    for(int i = 0; i < numLEDs; i++){
        fadePixel(i, 0.1);
    }
}

void NeoPixel::superFadeAll(){
    for(int i = 0; i < numLEDs; i++){
        fadePixel(i, 0.9);
    }
}

// Private Functions

void NeoPixel::initialisePin(){
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, pin, 800000, false);
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