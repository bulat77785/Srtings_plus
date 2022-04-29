#include <stdio.h>
#include "s21_string.h"

int s21_strcmp(const char *s1, const char *s2) {
    int res = 0;

    s1 = (char *)s1;
    s2 = (char *)s2;
    if (s1 == s2) {
        res = 0;
    } else if ((unsigned char *)s1 > (unsigned char *)s2) {
        res = 1;
    } else if ((unsigned char *)s1 < (unsigned char *)s2) {
        res = -1;
    }
    return res;
}
