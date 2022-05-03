#include <stdio.h>
#include "s21_string.h"

int s21_strncmp(const char *s1, const char *s2, size_t n) {
    s1 = (char *)s1;
    s2 = (char *)s2;

    while (n--) {
        if (*s1 == *s2) {
            s1++;
            s2++;
        } else {
            return (*s1 - *s2);
        }
    }
    return 0;
}
