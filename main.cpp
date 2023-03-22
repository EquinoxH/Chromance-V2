#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

#include "chromance.h"
#include "neopixel.h"
#include "colours.h"

void blink(){
    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(250);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(250);
    }
}

int main() {
    //set_sys_clock_48();
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }
    
    bool isBlue = false;
    int updateCount = 0;
    while(true){
        if(isBlue){
            Chromance::test();
            isBlue = false;
        }
        else {
            Chromance::test2();
            isBlue = true;
        }

        Chromance::writeUpdates();
        ++updateCount;
        if(updateCount == 2) blink();
        sleep_ms(100);
    }
}