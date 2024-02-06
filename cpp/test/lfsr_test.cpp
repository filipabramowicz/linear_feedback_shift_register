#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "lfsr.h"

TEST_GROUP(LfsrTests) {};

TEST(LfsrTests, TestLfsrInitializeSeed) {
    uint32_t seed = 45;
    Lfsr myLfsr(seed, 16, 13);

    CHECK_EQUAL(seed, myLfsr.getState());
};

int main(int argc, char ** argv)
{
    RUN_ALL_TESTS(argc, argv);
}