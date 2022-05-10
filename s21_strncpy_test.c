#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main() {
    char s1[20] = "Hello world\0";
    char s2[15] = "Hello world\n\0";
    char s3[20] = "a\n\0";
    char s4[20] = " \n\0";
    char s5[6] = " \0";
    char s6[4] = "\n\0";
    char s7[2] = "\0";
    char s8[4] = "aaa";
    char s9[2] = "D";
    char s10[20] = "Hello world\0";
    char s11[20] = "helljhgjhghjgo\0world";
    char s12[8] = "Q";

    /*printf("%s\n", s21_strcpy(s12, s11));
    printf("%s\n", strcpy(s12, s11));*/
    printf("%s\n", s21_strncpy(s11, s12, 2));
    printf("%s\n", strncpy(s11, s12, 2));
    printf("%s\n", s21_strncpy(s3, s4, 1));
    printf("%s\n", strncpy(s3, s4, 1));
    printf("%s\n", s21_strncpy(s1, s2, 3));
    printf("%s\n", strncpy(s1, s2, 3));
    printf("%s\n", s21_strncpy(s10, s8, 2));
    printf("%s\n", strncpy(s10, s8, 2));
    printf("%s\n", s21_strncpy(s5, s6, 1));
    printf("%s\n", strncpy(s5, s6, 1));
    printf("%s\n", s21_strncpy(s1, s9, 7));
    printf("%s\n", strncpy(s1, s9, 7));
    printf("%s\n", s21_strncpy(s5, s7, 1));
    printf("%s\n", strncpy(s5, s7, 1));
    printf("%s\n", s21_strncpy(s8, s9, 2));
    printf("%s\n", strncpy(s8, s9, 2));
    printf("%s\n", s21_strncpy(s6, s7, 1));
    printf("%s\n", strncpy(s6, s7, 1));
    
    return 0;
}
