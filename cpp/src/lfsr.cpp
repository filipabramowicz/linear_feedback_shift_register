#include "lfsr.h"

Lfsr::Lfsr(uint32_t seed)
    : registerState(seed) {}

uint32_t Lfsr::initialize(uint32_t sizeInBits, uint32_t tapPosition) {

    if (sizeInBits > 32) {
        return RC_NOK_SIZE_INT_BITS_GREATER_THAN_32;
    }

    if (tapPosition > sizeInBits ) {
        return RC_NOK_TAP_POSITION_GREATER_THAN_LFSR_SIZE;
    }

    this->setSizeInBits(sizeInBits);
    this->setTapPosition(tapPosition);

    return RC_OK;
};

int Lfsr::step() {
    return 0;
};