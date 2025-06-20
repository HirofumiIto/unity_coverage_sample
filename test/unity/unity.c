#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"

static int tests_run = 0;
static int tests_failed = 0;

void UNITY_BEGIN(void) {
    tests_run = 0;
    tests_failed = 0;
    printf("UNITY BEGIN\n");
}

void UNITY_END(void) {
    printf("UNITY END: %d tests, %d failed\n", tests_run, tests_failed);
}

void RUN_TEST(void (*test)(void)) {
    tests_run++;
    test();
}

void TEST_ASSERT_EQUAL_INT(int expected, int actual) {
    if (expected != actual) {
        printf("FAIL: Expected %d but got %d\n", expected, actual);
        tests_failed++;
    }
}

void TEST_ASSERT_EQUAL_STRING(const char* expected, const char* actual) {
    if (strcmp(expected, actual) != 0) {
        printf("FAIL: Expected '%s' but got '%s'\n", expected, actual);
        tests_failed++;
    }
}

void TEST_ASSERT_NOT_NULL(void* ptr) {
    if (ptr == NULL) {
        printf("FAIL: Pointer is NULL\n");
        tests_failed++;
    }
}