#pragma once

#include <map>
#include <string>
#include <functional>

namespace ProfileManager{
    extern std::map<std::string, std::function<void()>> setProfileFunctions;
    extern std::map<std::string, std::function<void()>> doUpdateFunctions;
    extern std::map<std::string, std::function<void(int)>> onDeathFunctions;

    void initialise();
    std::string getRandom();
    std::string getRandomExcept(std::string lastProfile);
    
    void setProfile(std::string profile);
    void doUpdate(std::string profile);
    void onDeath(std::string profile, int deathLocation);
}

namespace Profiles{
    const std::string aurora = "aurora";
    const std::string blossom = "blossom";
    const std::string clouds = "clouds";
    const std::string embers = "embers";
    const std::string fastRGB = "fastRGB";
    const std::string fireflies = "fireflies";
    const std::string fireworks = "fireworks";
    const std::string flower = "flower";
    const std::string heart = "heart";
    const std::string meteor = "meteor";
    const std::string meteorStorm = "meteorStorm";
    const std::string pulse = "pulse";
    const std::string purpleRain = "purpleRain";
    const std::string rainbow = "rainbow";
    const std::string rainfall = "rainfall";
    const std::string rgb = "rgb";
    const std::string snowfall = "snowfall";
    
    const std::string shapeTest = "shapeTest";

    const std::vector<std::string> profiles{
        aurora,
        blossom,
        clouds,
        embers,
        fastRGB,
        fireflies,
        fireworks,
        meteor,
        meteorStorm,
        pulse,
        purpleRain,
        rainbow,
        rainfall,
        rgb,
        snowfall
    };
}