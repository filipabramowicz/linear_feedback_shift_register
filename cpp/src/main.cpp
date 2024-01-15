#include <stdio.h>
#include <assert.h>
#include "lfsr.h"

int main()
{
    uint32_t seed = 0xffff0f0f;

    Lfsr(seed, 16, 14);

    //step();

    return 0;
}