#include "s21_string.h"

void *s21_memchr(const void *arr, int c, s21_size_t n) {
  s21_size_t i;
  unsigned char *str;
  unsigned char character;

  str = (unsigned char *)arr;
  character = (unsigned char)c;
  i = 0;
  while (i < n) {
    if (*str == character) return (str);
    str++;
    i++;
  }
  return (s21_NULL);
}

int s21_memcmp(const void *s1, const void *s2, s21_size_t n) {
  char *str1;
  char *str2;

  str1 = (char *)s1;
  str2 = (char *)s2;
  while (n--) {
    unsigned char c1;
    unsigned char c2;
    c1 = (unsigned char)*str1++;
    c2 = (unsigned char)*str2++;
    if (c1 != c2) return (c1 - c2);
  }
  return (0);
}

void *s21_memcpy(void *dst, const void *src, s21_size_t n) {
  if (dst != src) {
    s21_size_t i;
    i = 0;
    while (i < n) {
      ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
      i++;
    }
  }
  return (dst);
}

void *s21_memmove(void *dst, const void *src, s21_size_t len) {
  if (dst != src) {
    char *dst1;
    char *src1;
    src1 = (char *)src;
    dst1 = (char *)dst;
    if (src1 < dst1) {
      while (len-- > 0) *(dst1 + len) = *(src1 + len);
    } else {
      int i;
      i = -1;
      while (++i < (int)len) *(dst1 + i) = *(src1 + i);
    }
  }
  return (dst);
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *str1 = (char *)str;
  while (n--) {
    *str1 = (char)c;
    str1++;
  }
  return str;
}

char *s21_strcat(char *dest, const char *str) {
  char *start = dest;
  while (*dest != '\0') {
    dest++;
  }
  while (*str != '\0') {
    *dest = *str;
    dest++;
    str++;
  }
  *dest = '\0';
  return (start);
}

char *s21_strncat(char *dest, const char *str, s21_size_t n) {
  char *start = dest;
  while (*dest != '\0') {
    dest++;
  }
  while (n != 0) {
    *dest = *str;
    dest++;
    str++;
    n--;
  }
  return (start);
}

char *s21_strchr(const char *str1, int c) {
  while (*str1 != '\0' && *str1 != c) {
    str1++;
  }
  if (*str1 == c) {
    return (char *)str1;
  }
  return s21_NULL;
}

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) str1++, str2++;
  return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

int s21_strncmp(const char *str, const char *str2, s21_size_t n) {
  s21_size_t i;

  i = 0;
  if (n == 0) return (0);
  while (str[i] == str2[i] && str[i] != '\0' && i < n - 1) i++;
  return (((unsigned char *)str)[i] - ((unsigned char *)str2)[i]);
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

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  i = 0;
  while (src[i] != '\0' && (i < n)) {
    dest[i] = src[i];
    i++;
  }
  while (i < n) {
    dest[i] = '\0';
    i++;
  }
  return (dest);
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    s21_size_t i1 = 0;
    s21_size_t i2 = 0;
    for (; str1[i1] != str2[i2]; i2++) {
      if (str2[i2] == '\0') {
        len = len + 1;
        i1 = i1 + 1;
        i2 = 0;
      }
    }
  }
  return len;
}

char *s21_strerror(int errnum) {
  const char *array[] = ERRLIST;
  static char *err = {'\0'};

  err = (char *)array[errnum];

  static char buffer[1024];
  for (int i = 0; i < 1024; i++) buffer[i] = '\0';
#if defined(__APPLE__)
  s21_sprintf(buffer, "%s%d", UERROR, (int)errnum);
#elif defined(__linux__)
  s21_sprintf(buffer, "%s%d", UERROR, (int)errnum);
#endif
  if (err == s21_NULL || errnum > MAX_ERROR || errnum < 0) {
    err = buffer;
  }
  return err;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t i;

  i = 0;
  while (str[i] != 0) {
    i++;
  }
  return (i);
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *returnable = s21_NULL;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    s21_size_t i1 = 0, i2 = 0;
    for (; str1[i1] && str1[i1] != str2[i2]; i2++) {
      if (str2[i2] == '\0') {
        i1++;
        i2 = -1;
      }
    }
    if (str1[i1] != '\0') {
      returnable = (char *)&str1[i1];
    }
  }
  return returnable;
}

char *s21_strrchr(const char *str, int c) {
  s21_size_t i;

  i = 0;
  while (str[i]) i++;
  if (c == 0) return ((char *)str + i);
  while (i > 0) {
    i--;
    if (str[i] == c) return ((char *)str + i);
  }
  return (s21_NULL);
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t len = 0;

  const char *temp_str1;
  const char *temp_str2;

  int flag = 0;

  for (temp_str1 = str1; *temp_str1 != '\0' && flag == 0; ++temp_str1) {
    for (temp_str2 = str2; *temp_str2 + 1; ++temp_str2) {
      if (*temp_str1 == *temp_str2) {
        len++;
        break;
      }
      if (*temp_str2 == '\0') {
        flag = 1;
        break;
      }
    }
  }
  return len;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int i = 0;
  int j;

  int flag = 0;
  char *result = s21_NULL;

  if (haystack == s21_NULL) {
    flag = 1;
  }

  if (needle == s21_NULL || *needle == '\0') {
    result = (char *)haystack;
    flag = 1;
  }

  while (haystack[i] && flag == 0) {
    if (haystack[i] == needle[0]) {
      j = 1;
      while (needle[j] && haystack[i + j] == needle[j]) {
        j++;
      }
      if (needle[j] == '\0') {
        result = (char *)&haystack[i];
        flag = 1;
      }
    }
    i++;
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *result = s21_NULL;

  if (str) {
    result = str;
    while (*result && s21_strchr(delim, *result)) *result++ = '\0';
  }

  if (result != s21_NULL) {
    if (*result != '\0') {
      str = result;
      while (*result && !s21_strchr(delim, *result)) ++result;
      while (*result && s21_strchr(delim, *result)) *result++ = '\0';
    } else {
      str = s21_NULL;
    }
  } else {
    str = s21_NULL;
  }
  return str;
}

void *s21_to_upper(const char *str) {
  char *new_line = (char *)str;
  s21_size_t len = s21_strlen(str);

  new_line = malloc((len + 1) * sizeof(char));

  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      new_line[i] = str[i] - 32;
    } else {
      new_line[i] = str[i];
    }
  }
  new_line[len] = '\0';
  return new_line;
}

void *s21_to_lower(const char *str) {
  char *new_line = (char *)str;
  s21_size_t len = s21_strlen(str);

  new_line = malloc((len + 1) * sizeof(char));

  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      new_line[i] = str[i] + 32;
    } else {
      new_line[i] = str[i];
    }
  }
  new_line[len] = '\0';
  return new_line;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_line = (char *)src;

  if (src == s21_NULL || str == s21_NULL) {
    new_line = s21_NULL;
  } else {
    s21_size_t len1 = s21_strlen(src);
    s21_size_t len2 = s21_strlen(str);

    if (len1 < start_index) {
      new_line = s21_NULL;

    } else {
      new_line = malloc((len1 + len2 + 1) * sizeof(char));

      s21_size_t i = 0;
      s21_size_t j = 0;

      for (; i < start_index; i++) {
        new_line[i] = src[i];
      }
      for (; j < len2; i++, j++) {
        new_line[i] = str[j];
      }
      for (; i < len1 + len2; i++) {
        new_line[i] = src[i - j];
      }
      new_line[len1 + len2] = '\0';
    }
  }
  return new_line;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_line = (char *)src;

  if (src == s21_NULL || trim_chars == s21_NULL) {
    new_line = s21_NULL;
  } else {
    s21_size_t len1 = s21_strlen(src);
    s21_size_t len2 = s21_strlen(trim_chars);

    s21_size_t first_number = 0;
    s21_size_t last_number;

    if (len1 <= 0)
      last_number = 0;
    else
      last_number = len1 - 1;

    for (s21_size_t i = 0; i < len1 - 1 && i == first_number; i++) {
      s21_size_t j = 0;
      for (; j < len2; j++) {
        if (src[i] == trim_chars[j]) {
          first_number = i + 1;
          break;
        }
      }
    }

    for (s21_size_t i = len1 - 1;
         i > 0 && i == last_number && last_number != first_number; i--) {
      s21_size_t j = 0;
      for (; j < len2; j++) {
        if (src[i] == trim_chars[j]) {
          last_number = i - 1;
          break;
        }
      }
    }

    if (first_number == last_number) {
      new_line = malloc((last_number - first_number + 1) * sizeof(char));
      new_line[0] = '\0';

    } else {
      new_line = malloc((last_number - first_number + 2) * sizeof(char));
      for (s21_size_t i = 0; i < (last_number - first_number + 1); i++) {
        new_line[i] = src[i + first_number];
      }
      new_line[last_number - first_number + 1] = '\0';
    }
  }
  return new_line;
}
