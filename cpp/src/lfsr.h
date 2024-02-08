
#include <stdint.h>

// Return codes for initialize function
#define RC_OK 0
#define RC_NOK_SIZE_INT_BITS_GREATER_THAN_32 -1
#define RC_NOK_TAP_POSITION_GREATER_THAN_LFSR_SIZE -2

using namespace std;

class Lfsr {

    private:
        uint32_t registerState;
        uint32_t initializationState;
        uint32_t sizeInBits;
        uint32_t tapPosition;

    public:
        Lfsr(uint32_t seed);

        int step();

        uint32_t getState() {
            return registerState;
        }

        void setSizeInBits(uint32_t sizeInBits) {
            sizeInBits = sizeInBits;
        }

        void setTapPosition(uint32_t tapPosition) {
            tapPosition = tapPosition;
        }

        uint32_t initialize(uint32_t sizeInBits, uint32_t tapPosition);

        uint32_t getLfsrInitializationState() {
            return initializationState;
        }
};