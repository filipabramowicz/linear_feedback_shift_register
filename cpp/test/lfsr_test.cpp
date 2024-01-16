#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(Group) {};

TEST(Group, Test) {};

int main(int argc, char ** argv)
{
    RUN_ALL_TESTS(argc, argv);
}