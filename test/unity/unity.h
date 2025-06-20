#ifndef UNITY_H
#define UNITY_H

void UNITY_BEGIN(void);
void UNITY_END(void);
void RUN_TEST(void (*test)(void));
void TEST_ASSERT_EQUAL_INT(int expected, int actual);
void TEST_ASSERT_EQUAL_STRING(const char* expected, const char* actual);
void TEST_ASSERT_NOT_NULL(void* ptr);

#endif