#ifndef SRC_FUNCTION_S21_STRING_H_
#define SRC_FUNCTION_S21_STRING_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define s21_NULL ((void *)0)
typedef long unsigned s21_size_t;

char *s21_strcat(char *dest, const char *src);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str1, int c);
char *s21_strncat(char *dest, const char *str, s21_size_t n);

char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);

#endif  // SRC_FUNCTION_S21_STRING_H_
