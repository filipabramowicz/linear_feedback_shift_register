#include <stdio.h>
#include <assert.h>
#include "lfsr.h"

int main()
{
    uint32_t seed = 0xffff0f0f;

    int rc = initialize(seed, 16, 14);
    assert(rc == 0);

    step();

    return 0;
}