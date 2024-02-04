
#include <stdint.h>

using namespace std;

class Lfsr {
    private:
        uint32_t state;
        uint32_t sizeInBits;
        uint32_t tapPosition;
    public:
        Lfsr(uint32_t seed, uint32_t sizeInBits, uint32_t tapPosition);
        int step();
        uint32_t getState() {
            return state;
        }
};