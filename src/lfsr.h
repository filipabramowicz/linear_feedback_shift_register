#include <stdint.h>

typedef struct lfsr
{
    uint32_t state;
    uint32_t sizeInBits;
    uint32_t tapPosition;

} lfsr;

void initialize(uint32_t seed,
                uint32_t sizeInBits,
                uint32_t tapPosition);

void print_bits(size_t const size, void const * const ptr);

int step();