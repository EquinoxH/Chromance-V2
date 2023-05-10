#include <exception>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#include "profileManager.h"
#include "chromance.h"
#include "hub.h"
#include "myRandom.h"
#include "colours.h"
#include "debugTools.h"
#include "myNetwork.h"

#include <chrono>

#define wifiMode false

void initialisePico();
void doUSBWarning();
void initialiseChromance();