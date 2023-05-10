#include "debugTools.h"

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

namespace DebugTools{
    void blink(){
        while (true) {
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(250);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            sleep_ms(250);
        }
    }

    void blinkNumTimes(int num){
        for(int i = 0; i < num; i++){
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(250);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            sleep_ms(250);
        }
    }
}