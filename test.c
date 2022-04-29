#include <stdio.h>  // Для printf
#include <string.h> // Для strcpy

char *strcpy(char *dest, const char *src);

int main (void) {
   // Массив источник данных
   char src[1024] = "first string\0 second string";
 
   // Массив приемник данных
   char dst[1024] = "";

   // Копируем строку из массива src в массив dst. Обратите внимание,
   //что скопируется только строка «первая строка\0».
   strcpy (dst, src);

   // Вывод массива src на консоль
   printf("src: %s %s\n", src, &src[14]);

   // Вывод массива dst на консоль
   printf("dst: %s %s\n", dst, &dst[14]);
    
    printf("%d", char *strcpy(char *dest, const char *src));

   return 0;
}

char *strcpy(char *dest, const char *src) {
    char *ret =dst;
      assert(dst!=NULL);
      assert(src!=NULL);

    while (*dest++ = *src++);
    return ret;
}
