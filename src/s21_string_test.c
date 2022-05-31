#include "s21_string.h"

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

START_TEST(sprintf1) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "This is a simple value %d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%.5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%5d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%-5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%+12d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%012i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%0*d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                     sprintf(str2, format, 5, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%0.*i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                     sprintf(str2, format, 5, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf9) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char format[] = "%0.*i %d %4.*i %013d %d";
    int val = 69;
    ck_assert_int_eq(
        s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
        sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf10) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%+5.31li";
    long int val = 698518581899;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf11) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%.0d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf12) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "% d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf13) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf14) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%15u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf15) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%-16u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf16) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf17) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "% 5.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf18) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%u";
    ck_assert_int_eq(s21_sprintf(str1, format, 0),
                     sprintf(str2, format, (unsigned)0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf19) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%c";
    char val = 'X';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf20) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%.5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf21) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "% -5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf22) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%15c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf23) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                     sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf24) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%-5.3c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf25) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf26) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%.15s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf27) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%15s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf100) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%-15.9s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf28) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf29) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%s%s%s%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                     sprintf(str2, format, val, s1, s2, s3));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf30) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%s%s%s%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                     sprintf(str2, format, val, s1, s2, s3));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf31) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%s%s%s%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                     sprintf(str2, format, val, s1, s2, s3));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf32) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char *val = "kjafdiuhfjahfjdahf";
    char *format = "%120s";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf34) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char *format = "% f";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf35) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf36) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf37) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf38) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                     sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf39) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                     sprintf(str2, "%s", "Drop Sega PLS"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf40) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
        sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));
}
END_TEST

START_TEST(sprintf41) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf42) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf43) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                     sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf44) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf45) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                     sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf46) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                     sprintf(str2, "%f", 0.0001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf48) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'),
                     sprintf(str2, "%8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf49) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'),
                     sprintf(str2, "%8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf50) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                     sprintf(str2, "%-8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf51) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
        sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf53) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%1.1f";

    ck_assert_int_eq(s21_sprintf(str1, format, 1.1),
                     sprintf(str2, format, 1.1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf54) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%8.3c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
                     sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf55) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%+5.5d aboba";

    int val = 10000;
    int a = s21_sprintf(str1, format, val);
    int b = sprintf(str2, format, val);
    ck_assert_int_eq(a, b);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf56) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%7.7f";

    ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                     sprintf(str2, format, 11.123456));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf57) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%7.4s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                     sprintf(str2, format, "aboba floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf58) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "% c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
                     sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf59) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "% s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                     sprintf(str2, format, "aboba likes floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf60) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "% s% c";

    ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                     sprintf(str2, format, "", 'f'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf61) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%210s";

    ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                     sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf62) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%-115s";

    ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                     sprintf(str2, format, "Nick her"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf63) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%1.1f";

    ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                     sprintf(str2, format, 121.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf64) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%%";

    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf65) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%+5li";
    long int val = 698518581899;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf66) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%-16hi";
    short int val = 6958;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf67) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%0.*ld";
    long val = 8581385185;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                     sprintf(str2, format, 5, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf68) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%hu";
    unsigned short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf69) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%lu";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf70) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%lu, %u, %hu, %.5u, %5.u";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(
        s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
        sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
                (unsigned)14414, (unsigned)9681));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf80) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];

    char *format = "%hd";
    short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf73) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char *format = "%10Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf74) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char *format = "%Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf75) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char *format = "%f %f %Lf %f %Lf";
    double val1 = 1.2;
    double val2 = 1.3;
    long double val3 = 1.1;
    double val4 = 1.1;
    long double val5 = 1.61535;
    ck_assert_int_eq(s21_sprintf(str1, format, val1, val2, val3, val4, val5),
                     sprintf(str2, format, val1, val2, val3, val4, val5));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf76) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%li%ld%lu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                     sprintf(str2, format, 666666666666, 777, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf77) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%hi%hd%hu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                     sprintf(str2, format, 666, -777, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf78) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%+li%+lu%+d%+lf";

    ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                     sprintf(str2, format, -123, 321, -5555, -1213.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf79) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
    long double k = 333.33213;

    ck_assert_int_eq(
        s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
        sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf81) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%0.0li\n%0.0lu\n%0.0ld\n%f";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
        sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf82) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%0.0hi%0.0hu%0.0hd%f";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
        sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf83) {
    char str1[BUFFSIZE];
    char str2[BUFFSIZE];
    char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                    "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
        sprintf(str2, format, 'f', 21, 42, 666.666,
                "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memchr_test) {
    char str24[100] = "", str25[100] = "string", str26[100] = "Atring",
         str27[100] = "StringA", str28[100] = "Str55333222ingA",
         str29[100] = "00000000";
    ck_assert_ptr_eq(s21_memchr(str24, '\0', 0), memchr(str24, '\0', 0));
    ck_assert_ptr_eq(s21_memchr(str25, '\0', 7), memchr(str25, '\0', 7));
    ck_assert_ptr_eq(s21_memchr(str26, 'A', 6), memchr(str26, 'A', 6));
    ck_assert_ptr_eq(s21_memchr(str27, 'A', 7), memchr(str27, 'A', 7));
    ck_assert_ptr_eq(s21_memchr(str28, '3', 15), memchr(str28, '3', 15));
    ck_assert_ptr_eq(s21_memchr(str29, '-', 9), memchr(str29, '-', 9));
}
END_TEST

START_TEST(memcmp_test) {
    char str31[100] = "aboba", str32[100] = "aboba", str33[100] = "Aboba",
         str34[100] = "1", str35[100] = "1", str36[100] = "1234",
         str37[100] = "13",
         str38[100] =
             "111111111111111111112312312312312312434524563567adsfe 4rafa "
             "ewfseASDASD",
         str39[100] =
             "111111111111111111112312312312312312434524563567adsfe 4rafa "
             "ewfseASDASd";
    ck_assert_int_eq(s21_memcmp(str31, str32, 0), memcmp(str31, str32, 0));
    ck_assert_int_eq(s21_memcmp(str31, str32, 3), memcmp(str31, str32, 3));
    ck_assert_int_eq(s21_memcmp(str31, str33, 1), memcmp(str31, str33, 1));
    ck_assert_int_eq(s21_memcmp(str34, str35, 0), memcmp(str34, str35, 0));
    ck_assert_int_eq(s21_memcmp(str34, str36, 1), memcmp(str34, str36, 1));
    ck_assert_int_eq(s21_memcmp(str36, str37, 2), memcmp(str36, str37, 2));
    ck_assert_int_eq(s21_memcmp(str37, str38, 71), memcmp(str37, str38, 71));
    ck_assert_int_eq(s21_memcmp(str38, str39, 71), memcmp(str38, str39, 71));
}
END_TEST

START_TEST(memcpy_test) {
    char str40[100] = "i hate memcmp", str41[100] = "aboba", str42[100] = "",
         str43[100] = "I hate memcmp", str44[100] = "123",
         str45[100] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
    char dest[100] = {0};
    ck_assert_str_eq(s21_memcpy(str40, dest, 12), memcpy(str40, dest, 12));
    ck_assert_str_eq(s21_memcpy(str41, dest, 0), memcpy(str41, dest, 0));
    ck_assert_str_eq(s21_memcpy(str42, dest, 0), memcpy(str42, dest, 0));
    ck_assert_str_eq(s21_memcpy(str43, dest, 1), memcpy(str43, dest, 1));
    ck_assert_str_eq(s21_memcpy(str44, dest, 3), memcpy(str44, dest, 2));
    ck_assert_str_eq(s21_memcpy(str45, dest, 28), memcpy(str45, dest, 28));
}
END_TEST

START_TEST(memmove1) {
    char str46[100] = "i love memcmp", str47[100] = "aboba", str48[100] = "",
         str49[100] = "I love memcmp", str50[100] = "123",
         str51[100] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
    char dest[100] = "0000000000000000";
    ck_assert_str_eq(s21_memmove(str46, dest, 12), memmove(str46, dest, 12));
    ck_assert_str_eq(s21_memmove(str47, dest, 0), memmove(str47, dest, 0));
    ck_assert_str_eq(s21_memmove(str48, dest, 0), memmove(str48, dest, 0));
    ck_assert_str_eq(s21_memmove(str49, dest, 1), memmove(str49, dest, 1));
    ck_assert_str_eq(s21_memmove(str50, dest, 3), memmove(str50, dest, 2));
    ck_assert_str_eq(s21_memmove(str51, dest, 28), memmove(str51, dest, 28));
}
END_TEST

START_TEST(memset_test) {
    char str1[100] = "123456789";
    char str2[100] = "Nice";
    char str3[100] = "000000";
    char str4[100] = "-1-2-3-4-5";
    char str5[100] = " ";
    int c = '1';
    ck_assert_str_eq(s21_memset(str1, c, 5), memset(str1, c, 5));
    ck_assert_str_eq(s21_memset(str2, c, 2), memset(str2, c, 2));
    ck_assert_str_eq(s21_memset(str3, c, 10), memset(str3, c, 10));
    ck_assert_str_eq(s21_memset(str4, c, 2), memset(str4, c, 2));
    ck_assert_str_eq(s21_memset(str5, c, 1), memset(str5, c, 1));
}
END_TEST

START_TEST(strcat_test) {
    char str6[100] = "12345", str7[100] = "6789", str8[100] = "-12345%s",
         str9[100] = "", str10[100] = "000/000";
    char str12[100] = "45rtvb", str13[100] = "0000\n";
    ck_assert_str_eq(s21_strcat(str6, str12), strcat(str6, str12));
    ck_assert_str_eq(s21_strcat(str7, str12), strcat(str7, str12));
    ck_assert_str_eq(s21_strcat(str8, str13), strcat(str8, str13));
    ck_assert_str_eq(s21_strcat(str9, str13), strcat(str9, str13));
    ck_assert_str_eq(s21_strcat(str10, str12), strcat(str10, str12));
}
END_TEST

START_TEST(strncat_test) {
    char str11[100] = "12345", str12[100] = "6789", str13[100] = "-12345%s",
         str14[100] = "", str15[100] = "000/0";
    char str16[100] = "", str17[100] = "45rtvb", str18[100] = "0000\n";
    ck_assert_str_eq(s21_strncat(str11, str16, 2), strncat(str11, str16, 2));
    ck_assert_str_eq(s21_strncat(str12, str17, 0), strncat(str12, str17, 0));
    ck_assert_str_eq(s21_strncat(str13, str18, 10), strncat(str13, str18, 10));
    ck_assert_str_eq(s21_strncat(str14, str16, 5), strncat(str14, str16, 5));
    ck_assert_str_eq(s21_strncat(str15, str17, 1), strncat(str15, str17, 1));
}
END_TEST

START_TEST(strchr_test) {
    char str19[100] = "12345", str20[100] = "ghjtfdW", str21[100] = "-12345%s",
         str22[100] = "", str23[100] = "000/0";
    ck_assert_ptr_eq(s21_strchr(str19, '3'), strchr(str19, '3'));
    ck_assert_ptr_eq(s21_strchr(str20, 'j'), strchr(str20, 'j'));
    ck_assert_ptr_eq(s21_strchr(str21, '%'), strchr(str21, '%'));
    ck_assert_ptr_eq(s21_strchr(str22, 'G'), strchr(str22, 'G'));
    ck_assert_ptr_eq(s21_strchr(str23, '0'), strchr(str23, '0'));
}
END_TEST

START_TEST(s21_strcmp_test) {
    char s1[20] = "Hello world\0";
    char s3[20] = "a\n\0";
    char s4[20] = " \n\0";
    char s5[6] = " \0";
    char s6[4] = "\n\0";
    char s7[2] = "\0";
    char s8[4] = "aaa";
    char s9[2] = "";
    char s10[20] = "Hello world\0";

    ck_assert_int_eq(s21_strcmp(s4, s5), strcmp(s4, s5));
    ck_assert_int_eq(s21_strcmp(s5, s7), strcmp(s5, s7));
    ck_assert_int_eq(s21_strcmp(s3, s4), strcmp(s3, s4));
    ck_assert_int_eq(s21_strcmp(s6, s7), strcmp(s6, s7));
    ck_assert_int_eq(s21_strcmp(s8, s9), strcmp(s8, s9));
    ck_assert_int_eq(s21_strcmp(s1, s10), strcmp(s1, s10));
}
END_TEST

START_TEST(s21_strncmp_test) {
    // char s1[20] = "Hello world\0";
    // char s2[15] = "Hello world\n\0";
    char s3[20] = "a\n\0";
    char s4[20] = " \n\0";
    char s5[6] = " \0";
    char s6[4] = "\n\0";
    char s7[2] = "\0";
    char s8[4] = "aaa";
    char s9[2] = "";

    ck_assert_int_eq(s21_strncmp(s4, s5, 2), strncmp(s4, s5, 2));
    ck_assert_int_eq(s21_strncmp(s5, s7, 1), strncmp(s5, s7, 1));
    ck_assert_int_eq(s21_strncmp(s5, s7, 2), strncmp(s5, s7, 2));
    ck_assert_int_eq(s21_strncmp(s3, s4, 2), strncmp(s3, s4, 2));
    ck_assert_int_eq(s21_strncmp(s3, s4, 3), strncmp(s3, s4, 3));
    ck_assert_int_eq(s21_strncmp(s6, s7, 1), strncmp(s6, s7, 1));
    ck_assert_int_eq(s21_strncmp(s6, s7, 2), strncmp(s6, s7, 2));
    ck_assert_int_eq(s21_strncmp(s8, s9, 1), strncmp(s8, s9, 1));
}
END_TEST

START_TEST(s21_strcpy_test) {
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
    char s11[20] = "hello world";
    char s12[8] = "Q";

    ck_assert_str_eq(s21_strcpy(s11, s12), strcpy(s11, s12));
    ck_assert_str_eq(s21_strcpy(s3, s4), strcpy(s3, s4));
    ck_assert_str_eq(s21_strcpy(s1, s2), strcpy(s1, s2));
    ck_assert_str_eq(s21_strcpy(s10, s8), strcpy(s10, s8));
    ck_assert_str_eq(s21_strcpy(s5, s6), strcpy(s5, s6));
    ck_assert_str_eq(s21_strcpy(s1, s10), strcpy(s1, s10));
    ck_assert_str_eq(s21_strcpy(s5, s7), strcpy(s5, s7));
    ck_assert_str_eq(s21_strcpy(s8, s9), strcpy(s8, s9));
    ck_assert_str_eq(s21_strcpy(s6, s7), strcpy(s6, s7));
}
END_TEST

START_TEST(s21_strncpy_test) {
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
    char s11[20] = "hello world";
    char s12[8] = "Q";

    ck_assert_str_eq(s21_strncpy(s11, s12, 2), strncpy(s11, s12, 2));
    ck_assert_str_eq(s21_strncpy(s3, s4, 1), strncpy(s3, s4, 1));
    ck_assert_str_eq(s21_strncpy(s1, s2, 3), strncpy(s1, s2, 3));
    ck_assert_str_eq(s21_strncpy(s10, s8, 2), strncpy(s10, s8, 2));
    ck_assert_str_eq(s21_strncpy(s5, s6, 1), strncpy(s5, s6, 1));
    ck_assert_str_eq(s21_strncpy(s1, s9, 7), strncpy(s1, s9, 7));
    ck_assert_str_eq(s21_strncpy(s5, s7, 1), strncpy(s5, s7, 1));
    ck_assert_str_eq(s21_strncpy(s8, s9, 2), strncpy(s8, s9, 2));
    ck_assert_str_eq(s21_strncpy(s6, s7, 1), strncpy(s6, s7, 1));
}
END_TEST

START_TEST(s21_strcspn_test) {
    char *test = "string for testing 123";
    char *test2 = "231";
    char *testNULL = s21_NULL;

    ck_assert_int_eq(s21_strcspn(test, test2), strcspn(test, test2));
    ck_assert_int_eq(s21_strcspn("123456789", "987"),
                     strcspn("123456789", "987"));
    ck_assert_int_eq(s21_strcspn("123456789", " "), strcspn("123456789", " "));
    ck_assert_int_eq(s21_strcspn(" ", " "), strcspn(" ", " "));
    ck_assert_int_eq(s21_strcspn("123456789", "\n"),
                     strcspn("123456789", "\n"));
    ck_assert_int_eq(s21_strcspn("123456789", testNULL), 0);
}
END_TEST

START_TEST(s21_strerror_test) {
    for (int i = 1; i <= MAX_ERROR; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

START_TEST(s21_strlen_test) {
    char *str = "Test string";
    ck_assert_int_eq(s21_strlen(str), strlen(str));
    ck_assert_int_eq(s21_strlen("55"), strlen("55"));
    ck_assert_int_eq(s21_strlen(""), strlen(""));
    ck_assert_int_eq(s21_strlen(" "), strlen(" "));
    ck_assert_int_eq(s21_strlen("\n"), strlen("\n"));
    ck_assert_int_eq(s21_strlen("How is\0this is a string"),
                     strlen("How is\0this is a string"));
}
END_TEST

START_TEST(s21_strpbrk_test) {
    char *test = "string for testing 123";
    char *test2 = "orf";
    char *testNULL = s21_NULL;

    ck_assert_str_eq(s21_strpbrk(test, test2), strpbrk(test, test2));
    ck_assert_str_eq(s21_strpbrk("123456789", "9"), strpbrk("123456789", "9"));
    ck_assert_msg(s21_strpbrk("123456789", "0") == s21_NULL,
                  "s21_NULL should be returned s21_strbrk");
    ck_assert_msg(s21_strpbrk("12345678", "09") == s21_NULL,
                  "s21_NULL should be returned strbrk");
    ck_assert_msg(s21_strpbrk(testNULL, "09") == s21_NULL,
                  "s21_NULL should be returned strbrk");
}
END_TEST

START_TEST(s21_strrchr_test) {
    const char m1[] = "aetsghtaeghl";
    int m2 = 'a';
    ck_assert_ptr_eq(s21_strrchr(m1, m2), strrchr(m1, m2));

    const char m3[] = "aetsghtaeghl";
    int m4 = '2';
    ck_assert_pstr_eq(s21_strrchr(m3, m4), strrchr(m3, m4));

    const char m5[] = "";
    int m6 = 'a';
    ck_assert_pstr_eq(s21_strrchr(m5, m6), strrchr(m5, m6));
}
END_TEST

START_TEST(s21_strspn_test) {
    const char m7[] = "Hello world";
    const char m8[] = "Hel";
    ck_assert_int_eq(s21_strspn(m7, m8), strspn(m7, m8));
    const char m9[] = "";
    const char m10[] = "Hel";
    ck_assert_int_eq(s21_strspn(m9, m10), strspn(m9, m10));
    const char m11[] = "He\nllo world";
    const char m12[] = "Hel";
    ck_assert_int_eq(s21_strspn(m11, m12), strspn(m11, m12));
    const char m13[] = "Hello world";
    const char m14[] = "";
    ck_assert_int_eq(s21_strspn(m13, m14), strspn(m13, m14));
}
END_TEST

START_TEST(s21_strstr_test) {
    const char m15[] = "abcdefcdw";
    const char m16[] = "cd";
    ck_assert_str_eq(s21_strstr(m15, m16), strstr(m15, m16));
    const char m17[] = "abcefcdw";
    const char m18[] = "cd";
    ck_assert_pstr_eq(s21_strstr(m17, m18), strstr(m17, m18));
    const char m19[] = "abcdefcdw";
    const char m20[] = "kd";
    ck_assert_pstr_eq(s21_strstr(m19, m20), strstr(m19, m20));
    const char m21[] = "";
    const char m22[] = "kd";
    ck_assert_pstr_eq(s21_strstr(m21, m22), strstr(m21, m22));
    const char m23[] = "abcde";
    const char m24[] = "";
    ck_assert_str_eq(s21_strstr(m23, m24), strstr(m23, m24));
}
END_TEST

START_TEST(s21_strtok_test) {
    char m25[] = "123_45,6";
    const char m26[] = "_,";
    ck_assert_ptr_eq(s21_strtok(m25, m26), strtok(m25, m26));
    char m29[] = "";
    const char m30[] = "_";
    ck_assert_ptr_eq(s21_strtok(m29, m30), strtok(m29, m30));
    char m31[] = "123_45";
    const char m32[] = ",";
    ck_assert_ptr_eq(s21_strtok(m31, m32), strtok(m31, m32));
    char m33[] = "_123_45";
    char m34[] = "_123_45";
    const char m35[] = "_";
    ck_assert_str_eq(s21_strtok(m33, m35), strtok(m34, m35));
}
END_TEST

START_TEST(s21_to_upper_test) {
    char *s1 = s21_to_upper("abcdef");
    char *s2 = "ABCDEF";
    char *s3 = s21_to_upper("aBcDeF");
    char *s4 = "ABCDEF";
    char *s5 = s21_to_upper("aBcDeF 123");
    char *s6 = "ABCDEF 123";
    char *s7 = s21_to_upper("");
    char *s8 = "";
    ck_assert_str_eq(s1, s2);
    free(s1);
    ck_assert_str_eq(s3, s4);
    free(s3);
    ck_assert_str_eq(s5, s6);
    free(s5);
    ck_assert_str_eq(s7, s8);
    free(s7);
}
END_TEST

START_TEST(s21_to_lower_test) {
    char *s9 = s21_to_lower("ABCDEF");
    char *s10 = "abcdef";
    char *s11 = s21_to_lower("aBcDeF");
    char *s12 = "abcdef";
    char *s13 = s21_to_lower("aBcDeF 123");
    char *s14 = "abcdef 123";
    char *s15 = s21_to_lower("");
    char *s16 = "";
    ck_assert_str_eq(s9, s10);
    free(s9);
    ck_assert_str_eq(s11, s12);
    free(s11);
    ck_assert_str_eq(s13, s14);
    free(s13);
    ck_assert_str_eq(s15, s16);
    free(s15);
}
END_TEST

START_TEST(s21_insert_test) {
    char *s17 = s21_insert("abcdef", "234", 5);
    char *s18 = "abcde234f";
    char *s19 = s21_insert("abcdef", "234", 0);
    char *s20 = "234abcdef";
    char *s21 = s21_insert("abcdef", "234", 6);
    char *s22 = "abcdef234";
    char *s23 = s21_insert("abcdef", "234", 28);
    char *s24 = NULL;
    char *s25 = s21_insert("abcdef", "", 3);
    char *s26 = "abcdef";
    char *s27 = s21_insert("", "234", 0);
    char *s28 = "234";
    ck_assert_str_eq(s17, s18);
    free(s17);
    ck_assert_str_eq(s19, s20);
    free(s19);
    ck_assert_str_eq(s21, s22);
    free(s21);
    ck_assert_pstr_eq(s23, s24);
    free(s24);
    ck_assert_str_eq(s25, s26);
    free(s25);
    ck_assert_str_eq(s27, s28);
    free(s27);
}
END_TEST

START_TEST(s21_trim_test) {
    char *s29 = s21_trim("1211311abcdef11", "12");
    char *s30 = "311abcdef";
    char *s31 = s21_trim("812abcdef11", "12");
    char *s32 = "812abcdef";
    char *s33 = s21_trim("12abcdef11 ", "12");
    char *s34 = "abcdef11 ";
    char *s35 = s21_trim("", "12");
    char *s36 = "";
    char *s37 = s21_trim("abcdef", "");
    char *s38 = "abcdef";
    ck_assert_str_eq(s29, s30);
    free(s29);
    ck_assert_str_eq(s31, s32);
    free(s31);
    ck_assert_str_eq(s33, s34);
    free(s33);
    ck_assert_str_eq(s35, s36);
    free(s35);
    ck_assert_str_eq(s37, s38);
    free(s37);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, sprintf1);
    tcase_add_test(tc1_1, sprintf2);
    tcase_add_test(tc1_1, sprintf3);
    tcase_add_test(tc1_1, sprintf4);
    tcase_add_test(tc1_1, sprintf5);
    tcase_add_test(tc1_1, sprintf6);
    tcase_add_test(tc1_1, sprintf7);
    tcase_add_test(tc1_1, sprintf8);
    tcase_add_test(tc1_1, sprintf9);
    tcase_add_test(tc1_1, sprintf10);
    tcase_add_test(tc1_1, sprintf11);
    tcase_add_test(tc1_1, sprintf12);
    tcase_add_test(tc1_1, sprintf13);
    tcase_add_test(tc1_1, sprintf14);
    tcase_add_test(tc1_1, sprintf15);
    tcase_add_test(tc1_1, sprintf16);
    tcase_add_test(tc1_1, sprintf17);
    tcase_add_test(tc1_1, sprintf18);
    tcase_add_test(tc1_1, sprintf19);
    tcase_add_test(tc1_1, sprintf20);
    tcase_add_test(tc1_1, sprintf21);
    tcase_add_test(tc1_1, sprintf22);
    tcase_add_test(tc1_1, sprintf23);
    tcase_add_test(tc1_1, sprintf24);
    tcase_add_test(tc1_1, sprintf25);
    tcase_add_test(tc1_1, sprintf26);
    tcase_add_test(tc1_1, sprintf27);
    tcase_add_test(tc1_1, sprintf100);
    tcase_add_test(tc1_1, sprintf28);
    tcase_add_test(tc1_1, sprintf29);
    tcase_add_test(tc1_1, sprintf30);
    tcase_add_test(tc1_1, sprintf31);
    tcase_add_test(tc1_1, sprintf32);
    tcase_add_test(tc1_1, sprintf34);
    tcase_add_test(tc1_1, sprintf35);
    tcase_add_test(tc1_1, sprintf36);
    tcase_add_test(tc1_1, sprintf37);
    tcase_add_test(tc1_1, sprintf38);
    tcase_add_test(tc1_1, sprintf39);
    tcase_add_test(tc1_1, sprintf40);
    tcase_add_test(tc1_1, sprintf41);
    tcase_add_test(tc1_1, sprintf42);
    tcase_add_test(tc1_1, sprintf43);
    tcase_add_test(tc1_1, sprintf44);
    tcase_add_test(tc1_1, sprintf45);
    tcase_add_test(tc1_1, sprintf46);
    tcase_add_test(tc1_1, sprintf48);
    tcase_add_test(tc1_1, sprintf49);
    tcase_add_test(tc1_1, sprintf50);
    tcase_add_test(tc1_1, sprintf51);
    tcase_add_test(tc1_1, sprintf53);
    tcase_add_test(tc1_1, sprintf54);
    tcase_add_test(tc1_1, sprintf55);
    tcase_add_test(tc1_1, sprintf56);
    tcase_add_test(tc1_1, sprintf57);
    tcase_add_test(tc1_1, sprintf58);
    tcase_add_test(tc1_1, sprintf59);
    tcase_add_test(tc1_1, sprintf60);
    tcase_add_test(tc1_1, sprintf61);
    tcase_add_test(tc1_1, sprintf62);
    tcase_add_test(tc1_1, sprintf63);
    tcase_add_test(tc1_1, sprintf64);
    tcase_add_test(tc1_1, sprintf65);
    tcase_add_test(tc1_1, sprintf66);
    tcase_add_test(tc1_1, sprintf67);
    tcase_add_test(tc1_1, sprintf68);
    tcase_add_test(tc1_1, sprintf69);
    tcase_add_test(tc1_1, sprintf70);
    tcase_add_test(tc1_1, sprintf80);
    tcase_add_test(tc1_1, sprintf73);
    tcase_add_test(tc1_1, sprintf74);
    tcase_add_test(tc1_1, sprintf75);
    tcase_add_test(tc1_1, sprintf76);
    tcase_add_test(tc1_1, sprintf77);
    tcase_add_test(tc1_1, sprintf78);
    tcase_add_test(tc1_1, sprintf79);
    tcase_add_test(tc1_1, sprintf81);
    tcase_add_test(tc1_1, sprintf82);
    tcase_add_test(tc1_1, sprintf83);
    tcase_add_test(tc1_1, memchr_test);
    tcase_add_test(tc1_1, memcmp_test);
    tcase_add_test(tc1_1, memcpy_test);
    tcase_add_test(tc1_1, memmove1);
    tcase_add_test(tc1_1, memset_test);
    tcase_add_test(tc1_1, strcat_test);
    tcase_add_test(tc1_1, strncat_test);
    tcase_add_test(tc1_1, strchr_test);
    tcase_add_test(tc1_1, s21_strcmp_test);
    tcase_add_test(tc1_1, s21_strncmp_test);
    tcase_add_test(tc1_1, s21_strcpy_test);
    tcase_add_test(tc1_1, s21_strncpy_test);
    tcase_add_test(tc1_1, s21_strcspn_test);
    tcase_add_test(tc1_1, s21_strerror_test);
    tcase_add_test(tc1_1, s21_strlen_test);
    tcase_add_test(tc1_1, s21_strpbrk_test);
    tcase_add_test(tc1_1, s21_strrchr_test);
    tcase_add_test(tc1_1, s21_strspn_test);
    tcase_add_test(tc1_1, s21_strstr_test);
    tcase_add_test(tc1_1, s21_strtok_test);
    tcase_add_test(tc1_1, s21_to_upper_test);
    tcase_add_test(tc1_1, s21_to_lower_test);
    tcase_add_test(tc1_1, s21_insert_test);
    tcase_add_test(tc1_1, s21_trim_test);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}

