#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stddef.h>
#include <stdio.h>

typedef long unsigned int s21_size_t;

#include <float.h>   // Лимиты ДБЛМАКС
#include <limits.h>  // Прочие лимиты
#include <math.h>    // Лимиты инф
#include <stdarg.h>  // Вариадические функции
#include <stdlib.h>  // Маллок и прочие сепульки

#define BUFFSIZE 1024         // Размер буфера
#define s21_NULL ((void *)0)  // Собственный НУЛЛ

#if defined(__APPLE__)
#define UERROR "Unknown error: "
#define MAX_ERROR 106
#define ERRLIST                                                                \
  {                                                                            \
    "Undefined error: 0", "Operation not permitted",                           \
        "No such file or directory", "No such process",                        \
        "Interrupted system call", "Input/output error",                       \
        "Device not configured", "Argument list too long",                     \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource deadlock avoided", "Cannot allocate memory",                 \
        "Permission denied", "Bad address", "Block device required",           \
        "Resource busy", "File exists", "Cross-device link",                   \
        "Operation not supported by device", "Not a directory",                \
        "Is a directory", "Invalid argument", "Too many open files in system", \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain", "Result too large", \
        "Resource temporarily unavailable", "Operation now in progress",       \
        "Operation already in progress", "Socket operation on non-socket",     \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol family",                     \
        "Address already in use", "Can't assign requested address",            \
        "Network is down", "Network is unreachable",                           \
        "Network dropped connection on reset",                                 \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available", "Socket is already connected",            \
        "Socket is not connected", "Can't send after socket shutdown",         \
        "Too many references: can't splice", "Operation timed out",            \
        "Connection refused", "Too many levels of symbolic links",             \
        "File name too long", "Host is down", "No route to host",              \
        "Directory not empty", "Too many processes", "Too many users",         \
        "Disc quota exceeded", "Stale NFS file handle",                        \
        "Too many levels of remote in path", "RPC struct is bad",              \
        "RPC version wrong", "RPC prog. not avail", "Program version wrong",   \
        "Bad procedure for program", "No locks available",                     \
        "Function not implemented", "Inappropriate file type or format",       \
        "Authentication error", "Need authenticator", "Device power is off",   \
        "Device error", "Value too large to be stored in data type",           \
        "Bad executable (or shared library)", "Bad CPU type in executable",    \
        "Shared library version mismatch", "Malformed Mach-o file",            \
        "Operation canceled", "Identifier removed",                            \
        "No message of desired type", "Illegal byte sequence",                 \
        "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",          \
        "No message available on STREAM", "ENOLINK (Reserved)",                \
        "No STREAM resources", "Not a STREAM", "Protocol error",               \
        "STREAM ioctl timeout", "Operation not supported on socket",           \
        "Policy not found", "State not recoverable", "Previous owner died",    \
        "Interface output queue is full"                                       \
  }
#elif defined(__linux__)
#define UERROR "Unknown error "
#define MAX_ERROR 133
#define ERRLIST                                                                \
  {                                                                            \
    "Success", "Operation not permitted", "No such file or directory",         \
        "No such process", "Interrupted system call", "Input/output error",    \
        "No such device or address", "Argument list too long",                 \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource temporarily unavailable", "Cannot allocate memory",          \
        "Permission denied", "Bad address", "Block device required",           \
        "Device or resource busy", "File exists", "Invalid cross-device link", \
        "No such device", "Not a directory", "Is a directory",                 \
        "Invalid argument", "Too many open files in system",                   \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain",                     \
        "Numerical result out of range", "Resource deadlock avoided",          \
        "File name too long", "No locks available",                            \
        "Function not implemented", "Directory not empty",                     \
        "Too many levels of symbolic links", "Unknown error 41",               \
        "No message of desired type", "Identifier removed",                    \
        "Channel number out of range", "Level 2 not synchronized",             \
        "Level 3 halted", "Level 3 reset", "Link number out of range",         \
        "Protocol driver not attached", "No CSI structure available",          \
        "Level 2 halted", "Invalid exchange", "Invalid request descriptor",    \
        "Exchange full", "No anode", "Invalid request code", "Invalid slot",   \
        "Unknown error 58", "Bad font file format", "Device not a stream",     \
        "No data available", "Timer expired", "Out of streams resources",      \
        "Machine is not on the network", "Package not installed",              \
        "Object is remote", "Link has been severed", "Advertise error",        \
        "Srmount error", "Communication error on send", "Protocol error",      \
        "Multihop attempted", "RFS specific error", "Bad message",             \
        "Value too large for defined data type", "Name not unique on network", \
        "File descriptor in bad state", "Remote address changed",              \
        "Can not access a needed shared library",                              \
        "Accessing a corrupted shared library",                                \
        ".lib section in a.out corrupted",                                     \
        "Attempting to link in too many shared libraries",                     \
        "Cannot exec a shared library directly",                               \
        "Invalid or incomplete multibyte or wide character",                   \
        "Interrupted system call should be restarted", "Streams pipe error",   \
        "Too many users", "Socket operation on non-socket",                    \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol", "Address already in use",  \
        "Cannot assign requested address", "Network is down",                  \
        "Network is unreachable", "Network dropped connection on reset",       \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available",                                           \
        "Transport endpoint is already connected",                             \
        "Transport endpoint is not connected",                                 \
        "Cannot send after transport endpoint shutdown",                       \
        "Too many references: cannot splice", "Connection timed out",          \
        "Connection refused", "Host is down", "No route to host",              \
        "Operation already in progress", "Operation now in progress",          \
        "Stale file handle", "Structure needs cleaning",                       \
        "Not a XENIX named type file", "No XENIX semaphores available",        \
        "Is a named type file", "Remote I/O error", "Disk quota exceeded",     \
        "No medium found", "Wrong medium type", "Operation canceled",          \
        "Required key not available", "Key has expired",                       \
        "Key has been revoked", "Key was rejected by service", "Owner died",   \
        "State not recoverable", "Operation not possible due to RF-kill",      \
        "Memory page has hardware error"                                       \
  }

#endif

struct s_format {
  int isInt;
  int flagPlus;
  int flagMinus;
  int flagSpace;
  int width;
  int precision;
  int precisionWillBeSpecified;
  int precisionSetByZero;
  int length_h;
  int length_l;
  int isLongDouble;
  int isAsteriskWidth;
  int isAsteriskFloatWidthDescription;
  int precisionIsNull;
  int widthMustBeWrittenByZero;
  int widthZeroDetected;
  int spec;
};

int s21_sprintf(char *str, const char *format, ...);
void *s21_memchr(const void *arr, int c, s21_size_t n);
void *s21_memmove(void *dst, const void *src, s21_size_t len);
void *s21_memcpy(void *dst, const void *src, s21_size_t n);
int s21_memcmp(const void *s1, const void *s2, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *str, s21_size_t n);
char *s21_strchr(const char *str1, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// sprintf
int s21_isDigit(int character);
char *s21_strdup(const char *s1);
void helper_initStruct(struct s_format *formatParams);
int helper_isSpec(char c, struct s_format *formatParams);
void helper_writeInBuffer(const char **format, char **str,
                          struct s_format *formatParams, va_list vlist,
                          char *buff);
void helper_writeChar(const char **format, char **str,
                      struct s_format *formatParams, char c);
void helper_writePercent(const char **format, char **str);
void helper_bZero(void *s, s21_size_t n);
void *helper_memalloc(s21_size_t size);
char *helper_itoa(long n);
int helper_countNumerals(long double chislo);
char *helper_strNew(s21_size_t size);
char *helper_round(char *str, int accuracy, int precisionSetByZero);
void helper_cutStr(char *str, int pres, int isSetByZero);
void helper_convertInteger(double *fpNumber, char **str, int *i,
                           long int multiplier);
void helper_convertDecimal(char **str, int *i, float fpNumber, int accuracy);
void helper_convertDblInteger(long double *ldblNumber, char **str, int *i,
                              long int multiplier);
void helper_convertDblDecimal(char **str, int *i, long double chislo,
                              int accuracy);
char *helper_floatMaxConversion(char *str);
long long int helper_findMultiplier(long double fpNumber, int *size);
char *helper_ftoa(long double f, struct s_format formatParams);
char *helper_dtoa(long double ldNumber, struct s_format formatParams);
char *helper_utoa(unsigned long long int n);
char *helper_ldtoa(long long int n);

void writeInt(char *buff, struct s_format *formatParams, char *string);
void handleFlags(char *buff, struct s_format *formatParams);
void handlePrec(char *buff, struct s_format *formatParams);

void handleString(struct s_format *formatParams, char *buff, char *str);
void handleWideString(struct s_format *formatParams, char *buff, wchar_t *wstr);

void writeFloat(char *buff, struct s_format *formatParams, char *string);

int parser(const char **inputLine, struct s_format *inputLineParams);

#endif  // SRC_S21_STRING_H_
