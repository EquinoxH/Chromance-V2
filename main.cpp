#include "main.h"

std::string firstProfile = "clouds";

int main() {
    initialisePico();
    doUSBWarning();
    initialiseChromance();

    // Chromance::displayMode = Chromance::blend;
    // for(int i = 0; i < 100; i++){
    //     Chromance::addToLEDColour(i, Colours::red);
    //     Chromance::addToLEDColour(i, Colours::blue);
    // }

    // Chromance::writeUpdates();
    // return 0;

    // Chromance::createDoubleTrail(Colours::blue, 0, 40, 1, 140, true, false, true);
    // Chromance::createDoubleTrail(Colours::red, 0, 40, 1, 140, true, false, true);
    // while(true){
    //     Chromance::doUpdate();
    // }

    std::string lastProfile;
    auto profileStartTime = std::chrono::high_resolution_clock::now();
    while(!server->complete){
        Chromance::doUpdate();
        
        auto currentTime = std::chrono::high_resolution_clock::now();
        double elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - profileStartTime).count();

        if(elapsed >= 60){
            std::string nextProfile = ProfileManager::getRandomExcept(lastProfile);
            ProfileManager::setProfile(nextProfile);
            profileStartTime = std::chrono::high_resolution_clock::now();
        }
    }
    
    printf("Code End Reached\n");
    return 0;
}

void initialisePico(){
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
    }
}

void doUSBWarning(){
    DebugTools::blinkNumTimes(2);
    sleep_ms(5000);
    printf("Printing Working\n");
}

void initialiseChromance(){
    if(debugGeneral) printf("Intialising\n");
    Hubs::initialiseHubs();
    Random::initialise();
    ProfileManager::initialise();
    ProfileManager::setProfile(firstProfile);
    if(debugGeneral) printf("Intialised\n");

    if(wifiMode){
        connectToWifi();
        startTCPServer();
    }
}