#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int  main() {
    char s1[20] = "Hello world\0";
    char s2[15] = "Hello world\n\0";
    char s3[20] = "a\n\0";
    char s4[20] = " \n\0";
    char s5[6] = " \0";
    char s6[4] = "\n\0";
    char s7[2] = "\0";
    char s8[4] = "aaa";
    char s9[2] = "";

    printf("%d = %d\n", s21_strncmp(s1, s2, 11), strncmp(s1, s2, 11));
    printf("%d = %d\n", s21_strncmp(s1, s2, 12), strncmp(s1, s2, 12));
    printf("%d = %d\n", s21_strncmp(s4, s5, 1), strncmp(s4, s5, 1));
    printf("%d = %d\n", s21_strncmp(s4, s5, 2), strncmp(s4, s5, 2));
    printf("%d = %d\n", s21_strncmp(s5, s7, 1), strncmp(s5, s7, 1));
    printf("%d = %d\n", s21_strncmp(s5, s7, 2), strncmp(s5, s7, 2));
    printf("%d = %d\n", s21_strncmp(s3, s4, 2), strncmp(s3, s4, 2));
    printf("%d = %d\n", s21_strncmp(s3, s4, 3), strncmp(s3, s4, 3));
    printf("%d = %d\n", s21_strncmp(s6, s7, 1), strncmp(s6, s7, 1));
    printf("%d = %d\n", s21_strncmp(s6, s7, 2), strncmp(s6, s7, 2));
    printf("%d = %d\n", s21_strncmp(s8, s9, 3), strncmp(s8, s9, 3));

    return 0;
}
