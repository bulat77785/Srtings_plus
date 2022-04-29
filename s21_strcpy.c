#include <stdio.h>
#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
    char *ret = dst;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return ret;
}
