#include "hub.h"
#include "myRandom.h"

#include <algorithm>

// Constructor
Hub::Hub(int _id, int _numSlots, std::vector<int> _ledIDs, std::vector<int> _segmentIDs){
    id = _id;
    numSlots = _numSlots;
    ledIDs = _ledIDs;
    segmentIDs = _segmentIDs;
}

// Public Functions

int Hub::getID(){
    return id;
}

std::vector<int>& Hub::getLEDs(){
    return ledIDs;
}

int Hub::getRandomLED(){
    return ledIDs[Random::getRandomInt(ledIDs.size())];
}

int Hub::getRandomLEDExcept(int led){
    int random = led;
    while(random == led){
        random = ledIDs[Random::getRandomInt(ledIDs.size())];
    }

    return random;
}

namespace Hubs{
    std::vector<Hub> hubs;
    std::vector<int> slotMap;
    std::vector<std::vector<int>> ledMap;
    std::vector<std::vector<int>> segmentMap;

    void initialiseSlotMap(){
        slotMap = std::vector<int>{
            2,2,2,
            3,5,5,3,
            3,3,3,
            2,3,3,2,
            5,6,5,
            3,3,
            2,3,2,
            4,4,
            2
        };
    }

    void initialiseLEDMap(){
        ledMap.push_back(std::vector<int>{27, 28});
        ledMap.push_back(std::vector<int>{363, 364});
        ledMap.push_back(std::vector<int>{279, 280});
        ledMap.push_back(std::vector<int>{41, 83, 42});
        ledMap.push_back(std::vector<int>{14, 237, 13, 378, 377});

        ledMap.push_back(std::vector<int>{350, 349, 294, 392, 293});
        ledMap.push_back(std::vector<int>{266, 559, 265});
        ledMap.push_back(std::vector<int>{70, 223, 224});
        ledMap.push_back(std::vector<int>{391, 335, 336});
        ledMap.push_back(std::vector<int>{405, 545, 546});

        ledMap.push_back(std::vector<int>{55, 56});
        ledMap.push_back(std::vector<int>{139, 140, 0});
        ledMap.push_back(std::vector<int>{307, 461, 462});
        ledMap.push_back(std::vector<int>{251, 252});
        ledMap.push_back(std::vector<int>{69, 125, 126, 209, 210});

        ledMap.push_back(std::vector<int>{321, 322, 475, 476, 153, 154});
        ledMap.push_back(std::vector<int>{238, 531, 532, 447, 448});
        ledMap.push_back(std::vector<int>{489, 195, 196});
        ledMap.push_back(std::vector<int>{308, 517, 518});
        ledMap.push_back(std::vector<int>{111, 112});
       
        ledMap.push_back(std::vector<int>{490, 167, 168});
        ledMap.push_back(std::vector<int>{433, 434});
        ledMap.push_back(std::vector<int>{97, 98, 181, 182});
        ledMap.push_back(std::vector<int>{419, 420, 503, 504});
        ledMap.push_back(std::vector<int>{84, 406});
    }

    void initialiseSegmentMap(){
        segmentMap.push_back(std::vector<int>{1, 2});
        segmentMap.push_back(std::vector<int>{25, 26});
        segmentMap.push_back(std::vector<int>{19, 20});
        segmentMap.push_back(std::vector<int>{2, 3, 5});
        segmentMap.push_back(std::vector<int>{0, 1, 16, 26, 27});

        segmentMap.push_back(std::vector<int>{20, 21, 24, 25, 28});
        segmentMap.push_back(std::vector<int>{18, 19, 39});
        segmentMap.push_back(std::vector<int>{5, 15, 16});
        segmentMap.push_back(std::vector<int>{23, 24, 27});
        segmentMap.push_back(std::vector<int>{28, 38, 39});

        segmentMap.push_back(std::vector<int>{3, 4});
        segmentMap.push_back(std::vector<int>{0, 9, 10});
        segmentMap.push_back(std::vector<int>{21, 32, 33});
        segmentMap.push_back(std::vector<int>{17, 18});
        segmentMap.push_back(std::vector<int>{4, 8, 9, 14, 15});

        segmentMap.push_back(std::vector<int>{10, 11, 22, 23, 33, 34});
        segmentMap.push_back(std::vector<int>{17, 31, 32, 37, 38});
        segmentMap.push_back(std::vector<int>{13, 14, 34});
        segmentMap.push_back(std::vector<int>{22, 36, 37});
        segmentMap.push_back(std::vector<int>{7, 8});

        segmentMap.push_back(std::vector<int>{11, 12, 15});
        segmentMap.push_back(std::vector<int>{30, 31});
        segmentMap.push_back(std::vector<int>{6, 7, 12, 13});
        segmentMap.push_back(std::vector<int>{29, 30, 35, 36});
        segmentMap.push_back(std::vector<int>{6, 29});
    }

    void initialiseHubs(){
        initialiseSlotMap();
        initialiseLEDMap();
        initialiseSegmentMap();

        for(int i = 0; i < 25; i++){
            Hub hub(i, slotMap[i], ledMap[i], segmentMap[i]);
            hubs.push_back(hub);
        }
    }

    Hub getHub(int id){
        return hubs[id];
    }

    Hub getRandom(){
        return hubs[Random::getRandomInt(hubs.size())];
    }

    Hub getRandomExcept(int id){
        return hubs[Random::getRandomIntExcept(hubs.size(), id)];
    }

    Hub getConnectedHub(int led){
        for(Hub hub: hubs){
            if(std::count(hub.getLEDs().begin(), hub.getLEDs().end(), led)){
                return hub;
            }
        }

        return hubs[0];
    }

    bool ledIsStartOrEnd(int led){
        return (led % 14 == 0 || (led + 1) % 14 == 0);
    }
}