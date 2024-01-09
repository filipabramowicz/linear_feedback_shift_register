typedef struct lfsr
{
    unsigned int state;
    unsigned int sizeInBits;

} lfsr;

void initialize(unsigned int seed,
                unsigned int sizeInBits);

void print_bits(size_t const size, void const * const ptr);

int step();