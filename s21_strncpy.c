#include <stdio.h>
#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
    char *temp = dest;
    int i = 0;
    while ((*dest++ = *src++) && i++ < (int)n) {
    }
    return temp;
}
