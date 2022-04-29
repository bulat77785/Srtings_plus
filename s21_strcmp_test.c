#include <stdio.h>
#include "s21_string.h"

int  main() {
    char s1[20] = "abcdefg";
    char s2[10] = "abcdefg1";
    s21_strcmp(s1, s2);
    printf("%s\n", s1);
    return 0;
}
