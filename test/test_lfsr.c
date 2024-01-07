#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "lfsr.h"

extern lfsr global_lfsr;

static void test_initialize_seed() {

    unsigned int seed = 45;
    initialize(seed);

    assert_int_equal(global_lfsr.state, seed);
}

static void test_step_1() {

    unsigned int seed           = 0b1111111111111111;
    unsigned int expected_state = 0b1111111111111110;
    initialize(seed);

    step();
    assert_int_equal(global_lfsr.state, expected_state);
}

static void test_step_2() {

    unsigned int seed           = 0b1111111111111110;
    unsigned int expected_state = 0b1111111111111100;
    initialize(seed);

    step();
    assert_int_equal(global_lfsr.state, expected_state);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_initialize_seed),
        cmocka_unit_test(test_step_1),
        cmocka_unit_test(test_step_2),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}