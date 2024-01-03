#include <stdio.h>
#include "lfsr.h"

lfsr global_lfsr;

void initialize(unsigned int seed)
{
    global_lfsr.state = seed;
}

void print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char *)ptr;
    unsigned char byte;
    int i,j;

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
    printf("State before the change: %u\n", global_lfsr.state);
    print_bits(sizeof(global_lfsr.state), &global_lfsr.state);

    int positionOfFirstBitForSumator = 15;
    int positionOfSecondBitForSumator = 13;

    unsigned int valueOfFirstBitForSumator = 1 & (global_lfsr.state >> positionOfFirstBitForSumator);
    unsigned int valueOfSecondBitForSumator = 1 & (global_lfsr.state >> positionOfSecondBitForSumator);

    unsigned int sum = valueOfFirstBitForSumator ^ valueOfSecondBitForSumator;

    printf("valueOfFirstBitForSumator:\n");
    print_bits(sizeof(valueOfFirstBitForSumator), &valueOfFirstBitForSumator);

    printf("valueOfSecondBitForSumator:\n");
    print_bits(sizeof(valueOfSecondBitForSumator), &valueOfSecondBitForSumator);
    // Prepare reversed mask
    int mask = ~1;

    printf("sum:\n");
    print_bits(sizeof(sum), &sum);

    // Clear the less significant bit

    global_lfsr.state = (global_lfsr.state & mask) ^ sum;

    printf("State after the change: %u\n", global_lfsr.state);
    print_bits(sizeof(global_lfsr.state), &global_lfsr.state);
    return 0;
};