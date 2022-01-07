#include <stdlib.h>
#include <check.h>
#include "../src/main.h"
#include "./check_utils.h"
#include "./call_by_string.h"

DEFINE_TEST(test_strlen_1) {
    ck_assert_int_eq(4, 4);
} END_TEST

int main(int argc, char *argv[]) {
    call_by_string(argv[1]);

    exit(-1);
}
