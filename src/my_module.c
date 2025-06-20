#include <stdio.h>
#include "my_module.h"

int add(int a, int b) {
    printf("add called with %d and %d\n", a, b);
    return a + b;
}