#include <stdio.h>
#include "s21_string.h"

char *strncpy(char *dest, const char *src, size_t len) {
	assert(dest != NULL);       
 assert(src != NULL);       
 char *ret = dest;       
 int offset = 0;    
 // длина src меньше len 
 if (strlen(src) < len) {             
  offset = len - strlen(src);              
  len = strlen(src);       
 }       
 while (len--){              
  *dest++ = *src++;       
 }       
 while (offset--){              
  *dest++ = '\0';       
 }       
 return ret;
}