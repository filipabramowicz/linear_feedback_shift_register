typedef struct lfsr
{
    unsigned int state;

} lfsr;

void initialize(unsigned int seed);

void print_bits(size_t const size, void const * const ptr);

int step();