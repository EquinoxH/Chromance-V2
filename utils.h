#pragma once

#include <chrono>
#include <functional>
#include <map>
#include <string>

namespace Utils{
    void logCurrentTime();
    double getMillisecondsSinceLog();

    bool isKeyInMap(std::string key, std::map<std::string, std::function<void(int)>>& map);
}