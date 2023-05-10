#include <vector>

class Hub{
private:

    int id;
    int numSlots;
    std::vector<int> ledIDs;
    std::vector<int> segmentIDs;

public:

    // Constructor

    Hub(int _id, int _numSlots, std::vector<int> _ledIDs, std::vector<int> _segmentIDs);

    // Public Functions

    int getID();
    std::vector<int>& getLEDs();
    int getRandomLED();
    int getRandomLEDExcept(int led);
};

namespace Hubs{
    extern std::vector<Hub> hubs;
    extern std::vector<int> slotMap;
    extern std::vector<std::vector<int>> ledMap;
    extern std::vector<std::vector<int>> segmentMap;

    void initialiseHubs();
    Hub getHub(int id);
    Hub getRandom();
    Hub getRandomExcept(int id);
    Hub getConnectedHub(int led);
    bool ledIsStartOrEnd(int led);
}