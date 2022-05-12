#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2))
        str1++, str2++;
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
    str1 = (char *)str1;
    str2 = (char *)str2;

    while (n--) {
        if (*str1 == *str2) {
            str1++;
            str2++;
        } else {
            return (*str1 - *str2);
        }
    }
    return 0;
}

char *s21_strcpy(char *dest, const char *src) {
    char *temp = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return temp;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
    char *temp = dest;
    int i = 0;
    while ((*dest++ = *src++) && i++ < (int)n) {
    }
    return temp;
}
