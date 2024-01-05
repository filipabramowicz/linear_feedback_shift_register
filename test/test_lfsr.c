#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "lfsr.h"

extern lfsr global_lfsr;

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void test_initialize_seed() {
    unsigned int seed = 45;
    initialize(seed);

    assert_int_equal(global_lfsr.state, seed);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_initialize_seed),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
