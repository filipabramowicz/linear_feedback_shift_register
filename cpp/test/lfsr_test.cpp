#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "lfsr.h"

TEST_GROUP(LfsrTests) {};

TEST(LfsrTests, TestLfsrInitializeSeed) {
    uint32_t seed = 45;
    Lfsr myLfsr(seed);
    myLfsr.initialize(16, 13);

    CHECK_EQUAL(seed, myLfsr.getState());
};

TEST(LfsrTests, TestLfsrInitializeNokSizeGreaterThanMax) {
    uint32_t seed = 45;
    Lfsr myLfsr(seed);

    CHECK_EQUAL(seed, myLfsr.getState());

    uint32_t rc = myLfsr.initialize(55, 13);

    CHECK_EQUAL(rc, RC_NOK_SIZE_INT_BITS_GREATER_THAN_32);
};

int main(int argc, char ** argv)
{
    RUN_ALL_TESTS(argc, argv);
}