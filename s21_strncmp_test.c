#include <stdio.h>
//#include "s21_string.h"
#include <string.h>

int s21_strncmp(const char *s1, const char *s2, size_t n);
void strncmp_unit_test(const char* s1, const char* s2, size_t n);

int main (void) {
    //char str1[16]="1234567890";
    //char str2[16]="1234507890";
    
    strncmp_unit_test("aaa", "", 3);
    strncmp_unit_test("aaa", "afa", 3);
    strncmp_unit_test("aza", "aca", 3);
    strncmp_unit_test("abc", "abz", 3);
    strncmp_unit_test("abc", "abz", 2);
    strncmp_unit_test("abc", "abz", 1);
    strncmp_unit_test("abc", "abc", 10000);
    strncmp_unit_test("abc", "a", 50);
    strncmp_unit_test("a", "abc", 50);
    strncmp_unit_test("a", "abc", 1);
    
   /*// Сравниваемые строки
   
    if (s21_strncmp(str1, str2, 6) == 0) {
        printf("%4s == %4s, %5d == %d\n", str1, str2, strncmp(str1, str2, 6), strncmp(str1, str2, 6));
        return 0;
    } else if (s21_strncmp(str1, str2, 6) > 0) {
    printf("%4s == %4s, %5d == %d\n", str1, str2, strncmp(str1, str2, 6), strncmp(str1, str2, 6));
        return 1;
    } else if (s21_strncmp(str1, str2, 6) < 0) {
    printf("%4s == %4s, %5d == %d\n", str1, str2, strncmp(str1, str2, 6), strncmp(str1, str2, 6));
        return -1;
    }
    
   // Сравниваем первые пять символов двух строк
   if (strncmp (str1, str2, 6)==0)
      puts ("Первые 6 символов строк идентичны");
   else
      puts ("Первые 6 символов строк отличаются");
    //printf("%d", strncmp(str1, str2, 6));*/
   return 0;
}

int s21_strncmp(const char *s1, const char *s2, size_t n) {
    s1 = (char *)s1;
    s2 = (char *)s2;

    while (n--) {
        if (*s1 == *s2) {
            s1++;
            s2++;
        } else {
            if (*s1 < *s2)
                return -1;
            else
                return 1;
        }
    }
    return 0;
}

void strncmp_unit_test(const char* s1, const char* s2, size_t n) {
    printf("%4s == %4s, %5d == %d\n", s1, s2, s21_strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
