#include <stdio.h>
#include "s21_string.h"
#include <string.h>

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
    char s10[20] = "Hello world\0";

    printf("%d = %d\n", s21_strcmp(s1, s2), strcmp(s1, s2));
    printf("%d = %d\n", s21_strcmp(s4, s5), strcmp(s4, s5));
    printf("%d = %d\n", s21_strcmp(s5, s7), strcmp(s5, s7));
    printf("%d = %d\n", s21_strcmp(s3, s4), strcmp(s3, s4));
    printf("%d = %d\n", s21_strcmp(s6, s7), strcmp(s6, s7));
    printf("%d = %d\n", s21_strcmp(s8, s9), strcmp(s8, s9));
    printf("%d = %d\n", s21_strcmp(s1, s10), strcmp(s1, s10));

    return 0;
}
