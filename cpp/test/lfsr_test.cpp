#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "lfsr.h"

TEST_GROUP(LfsrTests) {};

TEST(LfsrTests, Test) {
    uint32_t seed = 0xffff0f0f;
    Lfsr(seed, 16, 14);
};

int main(int argc, char ** argv)
{
    RUN_ALL_TESTS(argc, argv);
}