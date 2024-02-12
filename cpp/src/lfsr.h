#include <stdint.h>
#include <stdio.h>

// Return codes for initialize function
#define RC_OK 0
#define RC_NOK_SIZE_INT_BITS_GREATER_THAN_32 -1
#define RC_NOK_TAP_POSITION_GREATER_THAN_LFSR_SIZE -2

// Initialization states
#define LFSR_NOT_INITIALIZED 0
#define LFSR_ACTIVE 1

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

        void getInitializationState(uint32_t initializationState) {
            initializationState = initializationState;
        }

        uint32_t initialize(uint32_t sizeInBits, uint32_t tapPosition);

        uint32_t getInitializationState() {
            return initializationState;
        }

        void printBits(size_t const size, void const * const ptr)
        {
            unsigned char *b = (unsigned char *)ptr;
            unsigned char byte;
            int i,j;

            printf("      ");
            for (i = size-1; i >= 0; i--)
            {
                for (j=7; j >= 0; j--)
                {
                    byte = (b[i] >> j) & 1;
                    printf("%u", byte);
                }
            }
            puts("");
        }
};