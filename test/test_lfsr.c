#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "lfsr.h"

#include <stdio.h>

extern lfsr global_lfsr;

static void test_lfsr_initialize_seed() {

    unsigned int seed = 45;
    initialize(seed, 16, 13);

    assert_int_equal(global_lfsr.state, seed);
}

static void test_lfsr_16bit_step_1() {

    unsigned int seed           = 0b1111111111111111;
    unsigned int expected_state = 0b1111111111111110;
    initialize(seed, 16, 13);

    step();
    assert_int_equal(global_lfsr.state, expected_state);
}

static void test_lfsr_16bit_step_2() {

    unsigned int seed           = 0b1111111111111110;
    unsigned int expected_state = 0b1111111111111100;
    initialize(seed, 16, 13);

    step();
    assert_int_equal(global_lfsr.state, expected_state);
}

static void test_lfsr_16bit_step_3() {

    unsigned int seed           = 0b1111111111111100;
    unsigned int expected_state = 0b1111111111111000;
    initialize(seed, 16, 13);

    step();
    assert_int_equal(global_lfsr.state, expected_state);
}

static void test_lfsr_16bit_step_4() {

    unsigned int seed           = 0b1111111111111111;
    unsigned int expected_state = 0b1100000000000000;
    initialize(seed, 16, 13);
    for (int i=0; i<14; i++){
        step();
    }

    assert_int_equal(global_lfsr.state, expected_state);
}

static void test_lfsr_4bit_step_1() {

    unsigned int seed = 0b1111;
    initialize(seed, 4, 2);

    step();
    assert_int_equal(global_lfsr.state, 0b1110);

    step();
    assert_int_equal(global_lfsr.state, 0b1100);

    step();
    assert_int_equal(global_lfsr.state, 0b1000);

    step();
    assert_int_equal(global_lfsr.state, 0b0001);

    step();
    assert_int_equal(global_lfsr.state, 0b0010);

    step();
    assert_int_equal(global_lfsr.state, 0b0100);

    step();
    assert_int_equal(global_lfsr.state, 0b1001);

    step();
    assert_int_equal(global_lfsr.state, 0b0011);

    step();
    assert_int_equal(global_lfsr.state, 0b0110);

    step();
    assert_int_equal(global_lfsr.state, 0b1101);

    step();
    assert_int_equal(global_lfsr.state, 0b1010);

    step();
    assert_int_equal(global_lfsr.state, 0b0101);

    step();
    assert_int_equal(global_lfsr.state, 0b1011);

    step();
    assert_int_equal(global_lfsr.state, 0b0111);

    step();
    assert_int_equal(global_lfsr.state, seed);
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