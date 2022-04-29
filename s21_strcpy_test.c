#include <stdio.h>
#include <assert.h>
#include "s21_string.h"

int main() {
    char src[20] = "hello world";
    char dst[20] = "";

    printf("%s\n", s21_strcpy(dst, src));
    return 0;
}
