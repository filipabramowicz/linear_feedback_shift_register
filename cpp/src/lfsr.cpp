#include "lfsr.h"

Lfsr::Lfsr(uint32_t seed, uint32_t sizeInBits, uint32_t tapPosition)
    : state(seed)
    , sizeInBits(sizeInBits)
    , tapPosition(tapPosition) {}

int Lfsr::step() {
    return 0;
};