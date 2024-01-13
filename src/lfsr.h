#include <stdint.h>

// Return codes for initialize function
#define RC_OK 0
#define RC_NOK_SIZE_INT_BITS_GREATER_THAN_32 -1
#define RC_NOK_TAP_POSITION_GREATER_THAN_LFSR_SIZE -2

typedef struct lfsr
{
    uint32_t state;
    uint32_t sizeInBits;
    uint32_t tapPosition;

} lfsr;

int initialize(uint32_t seed,
               uint32_t sizeInBits,
               uint32_t tapPosition);

void print_bits(size_t const size, void const * const ptr);

int step();