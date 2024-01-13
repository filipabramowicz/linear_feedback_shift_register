#include <stdio.h>
#include "lfsr.h"

lfsr global_lfsr;

void initialize(uint32_t seed,
                uint32_t sizeInBits,
                uint32_t tapPosition)
{
    global_lfsr.state = seed;
    global_lfsr.sizeInBits = sizeInBits;
    global_lfsr.tapPosition = tapPosition;
}

void print_bits(size_t const size, void const * const ptr)
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

int step()
{
    //printf("      State before the change: %u\n", global_lfsr.state);
    print_bits(sizeof(global_lfsr.state), &global_lfsr.state);

    // First bit for the adder should always be the most significant bit
    uint32_t positionOfFirstBitForAdder = global_lfsr.sizeInBits - 1;
    // Second bit for the adder shoule be defined by tapPosition
    uint32_t positionOfSecondBitForAdder = global_lfsr.tapPosition;

    uint32_t valueOfFirstBitForAdder = 1 & (global_lfsr.state >> positionOfFirstBitForAdder);
    uint32_t valueOfSecondBitForAdder = 1 & (global_lfsr.state >> positionOfSecondBitForAdder);

    uint32_t sum = valueOfFirstBitForAdder ^ valueOfSecondBitForAdder;

    // Shift the state
    global_lfsr.state = global_lfsr.state << 1;

    // Prepare the mask depending on the size of LFSR
    uint32_t sizeDependentMask = 0;

    // The bitmap fields is 32 bits long. According to C standard attempting
    // to shift more positions than there is a room in the left operand invoked
    // undefined behavior. That's why for 32bit LFSR we cannot calculated the
    // bitmap by shifting left by 32. Instead 32bit mask can be calculated by
    // invoking bitwsise NOT on 0.
    if (global_lfsr.sizeInBits < 32) {
        sizeDependentMask = (1 << global_lfsr.sizeInBits) - 1;
    }
    else {
        sizeDependentMask = ~0;
    }

    // Apply mask
    global_lfsr.state = sizeDependentMask & global_lfsr.state;

    //printf("      valueOfFirstBitForAdder:\n");
    //print_bits(sizeof(valueOfFirstBitForAdder), &valueOfFirstBitForAdder);

    //printf("      valueOfSecondBitForAdder:\n");
    //print_bits(sizeof(valueOfSecondBitForAdder), &valueOfSecondBitForAdder);
    // Prepare reversed mask
    uint32_t mask = ~1;

    //printf("      sum:\n");
    //print_bits(sizeof(sum), &sum);

    // Clear the less significant bit

    global_lfsr.state = (global_lfsr.state & mask) ^ sum;

    //printf("      State after the change: %u\n", global_lfsr.state);
    print_bits(sizeof(global_lfsr.state), &global_lfsr.state);
    return 0;
};