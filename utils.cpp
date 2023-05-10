#include "utils.h"
#include "debugTools.h"

namespace Utils{
    namespace{
        std::chrono::_V2::system_clock::time_point loggedTime;
    }
    

    void logCurrentTime(){
        loggedTime = std::chrono::high_resolution_clock::now();
        if(debugUtils) printf("Logged Time\n");
    }

    double getMillisecondsSinceLog(){
        auto currentTime = std::chrono::high_resolution_clock::now();
        double result = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - loggedTime).count();
        if(debugUtils) printf("Elapsed Time: %fms\n", result);
        return result;
    }

    bool isKeyInMap(std::string key, std::map<std::string, std::function<void(int)>>& map){
        return map.find(key) != map.end();
    }
}