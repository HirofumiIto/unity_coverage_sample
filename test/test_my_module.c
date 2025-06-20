#include "unity.h"
#include "my_module.h"
#include <stdio.h>
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_add_function(void) {
    TEST_ASSERT_EQUAL_INT(7, add(3, 4));
}

void test_add_logs_output(void) {
    FILE *fp = freopen("log_output.txt", "w+", stdout);
    TEST_ASSERT_NOT_NULL(fp);

    add(3, 4);

    fflush(stdout);
    fseek(fp, 0, SEEK_SET);

    char buffer[128] = {0};
    fgets(buffer, sizeof(buffer), fp);

    fclose(fp);

    TEST_ASSERT_EQUAL_STRING("add called with 3 and 4\n", buffer);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_function);
    RUN_TEST(test_add_logs_output);
    return UNITY_END();
}