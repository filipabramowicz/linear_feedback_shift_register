#include <stdio.h>
#include "lfsr.h"

int main()
{
    initialize(0xffff);
    step();
    return 0;
}