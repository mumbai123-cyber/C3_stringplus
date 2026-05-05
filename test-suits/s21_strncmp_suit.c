#define _POSIX_C_SOURCE 200809L

#include "s21_strncmp_suit.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "test_utils.h"

START_TEST(s21_strncmp_base) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_base_diff) {
  const char *str1 = "Hello";
  const char *str2 = "Hella";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_sign_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_base_short) {
  const char *str1 = "Hi";
  const char *str2 = "Hi";
  size_t n = 2;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_base_empt) {
  const char *str1 = "";
  const char *str2 = "";
  size_t n = 1;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_standart) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hello, world!";
  size_t n = 13;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_standart_full) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hello, world!";
  size_t n = 14;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_standart_part) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hello, world!";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_standart_space) {
  const char *str1 = "Hello world test";
  const char *str2 = "Hello world test";
  size_t n = 15;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_border_N0) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  size_t n = 0;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_border_N0diff) {
  const char *str1 = "Hello";
  const char *str2 = "olleH";
  size_t n = 0;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_border_overN) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  size_t n = 10;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_border_Ncmp) {
  const char *str1 = "Hello";
  const char *str2 = "Hel";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_sign_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_border_Ncmp2) {
  const char *str1 = "Hel";
  const char *str2 = "Hello";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_sign_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_null) {
  char str1[8] = {'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0'};
  char str2[8] = {'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0'};
  size_t n = 7;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_byts) {
  char str1[256];
  char str2[256];

  for (int i = 0; i < 256; i++) {
    str1[i] = (char)i;
    str2[i] = (char)i;
  }

  size_t n = 256;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_sb) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hello, world!";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_empt_src) {
  const char *str1 = "";
  const char *str2 = "Hello";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_sign_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_empt_strs) {
  const char *str1 = "";
  const char *str2 = "";
  size_t n = 10;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_lower_uper) {
  const char *str1 = "Hello";
  const char *str2 = "HELLO";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_sign_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_num) {
  const char *str1 = "12345";
  const char *str2 = "12345";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_num_diff) {
  const char *str1 = "12345";
  const char *str2 = "12344";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_SC) {
  const char *str1 = "\t\n\r\v\f";
  const char *str2 = "\t\n\r\v\f";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_SC_diff) {
  const char *str1 = "\t\n\r\v\f";
  const char *str2 = "\t\n\r\v ";
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_sign_eq(get, expt);
}
END_TEST

START_TEST(s21_strncmp_other_ptr) {
  char buf1[30] = "Hello, world!";
  char buf2[30] = "Hello, world!";

  const char *str1 = buf1 + 2;
  const char *str2 = buf2 + 2;
  size_t n = 5;

  int get = s21_strncmp(str1, str2, n);
  int expt = strncmp(str1, str2, n);

  ck_assert_int_eq(get, expt);
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strncmp_base);
  tcase_add_test(tc_core, s21_strncmp_base_diff);
  tcase_add_test(tc_core, s21_strncmp_base_short);
  tcase_add_test(tc_core, s21_strncmp_base_empt);

  tcase_add_test(tc_core, s21_strncmp_standart);
  tcase_add_test(tc_core, s21_strncmp_standart_full);
  tcase_add_test(tc_core, s21_strncmp_standart_part);
  tcase_add_test(tc_core, s21_strncmp_standart_space);

  tcase_add_test(tc_core, s21_strncmp_border_N0);
  tcase_add_test(tc_core, s21_strncmp_border_N0diff);
  tcase_add_test(tc_core, s21_strncmp_border_overN);
  tcase_add_test(tc_core, s21_strncmp_border_Ncmp);
  tcase_add_test(tc_core, s21_strncmp_border_Ncmp2);

  tcase_add_test(tc_core, s21_strncmp_other_null);
  tcase_add_test(tc_core, s21_strncmp_other_byts);
  tcase_add_test(tc_core, s21_strncmp_other_sb);
  tcase_add_test(tc_core, s21_strncmp_other_empt_src);
  tcase_add_test(tc_core, s21_strncmp_other_empt_strs);
  tcase_add_test(tc_core, s21_strncmp_other_lower_uper);
  tcase_add_test(tc_core, s21_strncmp_other_num);
  tcase_add_test(tc_core, s21_strncmp_other_num_diff);
  tcase_add_test(tc_core, s21_strncmp_other_SC);
  tcase_add_test(tc_core, s21_strncmp_other_SC_diff);
  tcase_add_test(tc_core, s21_strncmp_other_ptr);

  suite_add_tcase(s, tc_core);

  return s;
}