#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "lfsr.h"

#include <stdio.h>

extern lfsr global_lfsr;

static void test_lfsr_initialize_seed() {

    unsigned int seed = 45;
    initialize(seed, 16, 15);

    assert_int_equal(global_lfsr.state, seed);
}

static void test_lfsr_16bit_step_1() {

    unsigned int seed           = 0b1111111111111111;
    unsigned int expected_state = 0b1111111111111110;
    initialize(seed, 16, 15);

    step();
    assert_int_equal(global_lfsr.state, expected_state);
}

static void test_lfsr_16bit_step_2() {

    unsigned int seed           = 0b1111111111111110;
    unsigned int expected_state = 0b1111111111111100;
    initialize(seed, 16, 15);

    step();
    assert_int_equal(global_lfsr.state, expected_state);
}

static void test_lfsr_16bit_step_3() {

    unsigned int seed           = 0b1111111111111100;
    unsigned int expected_state = 0b1111111111111000;
    initialize(seed, 16, 15);

    step();
    assert_int_equal(global_lfsr.state, expected_state);
}

static void test_lfsr_16bit_step_4() {

    unsigned int seed           = 0b1111111111111111;
    unsigned int expected_state = 0b1100000000000001;
    initialize(seed, 16, 15);
    for (int i=0; i<14; i++){
        step();
    }

    assert_int_equal(global_lfsr.state, expected_state);
}

static void test_lfsr_4bit_step_1() {

    unsigned int seed = 0b1111;
    initialize(seed, 4, 3);

    step();
    assert_int_equal(global_lfsr.state, 0b1110);

    step();
    assert_int_equal(global_lfsr.state, 0b1100);

}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_lfsr_initialize_seed),
        cmocka_unit_test(test_lfsr_16bit_step_1),
        cmocka_unit_test(test_lfsr_16bit_step_2),
        cmocka_unit_test(test_lfsr_16bit_step_3),
        cmocka_unit_test(test_lfsr_16bit_step_4),
        cmocka_unit_test(test_lfsr_4bit_step_1),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}