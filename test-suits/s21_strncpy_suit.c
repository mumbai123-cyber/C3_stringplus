#define _POSIX_C_SOURCE 200809L
#include "s21_strncpy_suit.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(s21_strncpy_base) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  const char *src1 = "Hello";

  s21_strncpy(d_st_1, src1, 5);
  strncpy(d_st_2, src1, 5);

  ck_assert_mem_eq(d_st_1, d_st_2, 5);
}
END_TEST

START_TEST(s21_strncpy_base_short) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  const char *src1 = "Hi";

  s21_strncpy(d_st_1, src1, 2);
  strncpy(d_st_2, src1, 2);

  ck_assert_mem_eq(d_st_1, d_st_2, 2);
}
END_TEST

START_TEST(s21_strncpy_base_empt) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  const char *src1 = "";

  s21_strncpy(d_st_1, src1, 1);
  strncpy(d_st_2, src1, 1);

  ck_assert_str_eq(d_st_1, d_st_2);
}
END_TEST

START_TEST(s21_strncpy_standart) {
  char d_st_1[50] = {0};
  char d_st_2[50] = {0};
  const char *src1 = "Hello, world!";

  s21_strncpy(d_st_1, src1, 13);
  strncpy(d_st_2, src1, 13);

  ck_assert_mem_eq(d_st_1, d_st_2, 13);
}
END_TEST

START_TEST(s21_strncpy_standart_full) {
  char d_st_1[50] = {0};
  char d_st_2[50] = {0};
  const char *src1 = "Hello, world!";

  s21_strncpy(d_st_1, src1, 14);
  strncpy(d_st_2, src1, 14);

  ck_assert_str_eq(d_st_1, d_st_2);
}
END_TEST

START_TEST(s21_strncpy_standart_part) {
  char d_st_1[50] = {0};
  char d_st_2[50] = {0};
  const char *src1 = "Hello, world!";

  s21_strncpy(d_st_1, src1, 5);
  strncpy(d_st_2, src1, 5);

  ck_assert_mem_eq(d_st_1, d_st_2, 5);
}
END_TEST

START_TEST(s21_strncpy_standard_space) {
  char d_st_1[50] = {0};
  char d_st_2[50] = {0};
  const char *src1 = "Hello world test";

  s21_strncpy(d_st_1, src1, 15);
  strncpy(d_st_2, src1, 15);

  ck_assert_mem_eq(d_st_1, d_st_2, 15);
}
END_TEST

START_TEST(s21_strncpy_border_1) {
  char d_st_1[20] = {0};
  const char *src1 = "Hello";

  for (int i = 0; i < 10; i++) {
    d_st_1[i] = (char)(0xAA + i);
  }

  char arr[10];

  s21_strncpy(d_st_1, src1, 0);
  memcpy(arr, d_st_1, 10);

  ck_assert_mem_eq(d_st_1, arr, 10);
}
END_TEST
START_TEST(s21_strncpy_border_2) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  const char *src1 = "Hi";

  memset(d_st_1, 0xFF, 10);
  memset(d_st_2, 0xFF, 10);

  s21_strncpy(d_st_1, src1, 5);
  strncpy(d_st_2, src1, 5);

  ck_assert_mem_eq(d_st_1, d_st_2, 5);
}
END_TEST

START_TEST(s21_strncpy_border_3) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  const char *src1 = "Hello";

  s21_strncpy(d_st_1, src1, 5);
  strncpy(d_st_2, src1, 5);

  ck_assert_mem_eq(d_st_1, d_st_2, 5);
}
END_TEST

START_TEST(s21_strncpy_border_4) {
  char d_st_1[10] = "xxxxxxxxx";
  char d_st_2[10] = "xxxxxxxxx";
  const char *src1 = "hi";
  size_t n = 2;

  s21_strncpy(d_st_1, src1, n);
  strncpy(d_st_2, src1, n);

  ck_assert_mem_eq(d_st_1, d_st_2, 10);

  ck_assert_int_eq(d_st_1[2], 'x');
  ck_assert_int_eq(d_st_1[3], 'x');
  ck_assert_int_eq(d_st_1[4], 'x');
}
END_TEST

START_TEST(s21_strncpy_border_maxn) {
  char d_st_1[10] = {0};
  char d_st_2[10] = {0};
  const char *src1 = "hello";
  size_t n = 10;

  s21_strncpy(d_st_1, src1, n);
  strncpy(d_st_2, src1, n);

  ck_assert_mem_eq(d_st_1, d_st_2, n);
}
END_TEST

START_TEST(s21_strncpy_other_null) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  char src1[8] = {'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0'};
  size_t n = 7;

  s21_strncpy(d_st_1, src1, n);
  strncpy(d_st_2, src1, n);

  ck_assert_mem_eq(d_st_1, d_st_2, n);
}
END_TEST

START_TEST(s21_strncpy_other_bytes) {
  char d_st_1[256];
  char d_st_2[256];
  char src1[256];

  for (int i = 0; i < 256; i++) {
    src1[i] = (char)i;
  }

  size_t n = 256;

  s21_strncpy(d_st_1, src1, n);
  strncpy(d_st_2, src1, n);

  ck_assert_mem_eq(d_st_1, d_st_2, n);
}
END_TEST

START_TEST(s21_strncpy_other_sb) {
  char d_st_1[5] = {0};
  char d_st_2[5] = {0};
  const char *src1 = "Hello, world!";

  s21_strncpy(d_st_1, src1, 5);
  strncpy(d_st_2, src1, 5);

  ck_assert_mem_eq(d_st_1, d_st_2, 5);
}
END_TEST

START_TEST(s21_strncpy_other_empt_src) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  const char *src1 = "";

  memset(d_st_1, 0xFF, 10);
  memset(d_st_2, 0xFF, 10);

  s21_strncpy(d_st_1, src1, 10);
  strncpy(d_st_2, src1, 10);

  ck_assert_mem_eq(d_st_1, d_st_2, 10);
}
END_TEST

START_TEST(s21_strncpy_other_ptr_af) {
  char buffer_s21[30] = "Hello, world!";
  char buffer_std[30] = "Hello, world!";
  char dest_s21[30] = {0};
  char dest_std[30] = {0};

  char *src_s21 = buffer_s21 + 2;
  char *src_std = buffer_std + 2;

  s21_strncpy(dest_s21, src_s21, 5);
  strncpy(dest_std, src_std, 5);

  ck_assert_mem_eq(dest_s21, dest_std, 5);
}
END_TEST

START_TEST(s21_strncpy_other_ptr_bf) {
  char src_s21[30] = "Hello, world!";
  char src_std[30] = "Hello, world!";
  char dest_s21[30] = {0};
  char dest_std[30] = {0};

  s21_strncpy(dest_s21, src_s21 + 5, 5);
  strncpy(dest_std, src_std + 5, 5);

  ck_assert_mem_eq(dest_s21, dest_std, 5);
}
END_TEST

START_TEST(s21_strncpy_other_ptr) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  const char *src1 = "Hello";

  char *res_my = s21_strncpy(d_st_1, src1, 5);
  char *res_base = strncpy(d_st_2, src1, 5);

  ck_assert_ptr_eq(res_my, d_st_1);
  ck_assert_ptr_eq(res_base, d_st_2);

  ck_assert_mem_eq(res_my, res_base, 5);
}
END_TEST

START_TEST(s21_strncpy_other_num) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  const char *src1 = "12345 67890";

  s21_strncpy(d_st_1, src1, 11);
  strncpy(d_st_2, src1, 11);

  ck_assert_mem_eq(d_st_1, d_st_2, 11);
}
END_TEST

START_TEST(s21_strncpy_other_SC) {
  char d_st_1[20] = {0};
  char d_st_2[20] = {0};
  const char *src1 = "\t\n\r\v\f";

  s21_strncpy(d_st_1, src1, 5);
  strncpy(d_st_2, src1, 5);

  ck_assert_mem_eq(d_st_1, d_st_2, 5);
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strncpy_base);
  tcase_add_test(tc_core, s21_strncpy_base_short);
  tcase_add_test(tc_core, s21_strncpy_base_empt);

  tcase_add_test(tc_core, s21_strncpy_standart);
  tcase_add_test(tc_core, s21_strncpy_standart_full);
  tcase_add_test(tc_core, s21_strncpy_standart_part);
  tcase_add_test(tc_core, s21_strncpy_standard_space);

  tcase_add_test(tc_core, s21_strncpy_border_1);
  tcase_add_test(tc_core, s21_strncpy_border_2);
  tcase_add_test(tc_core, s21_strncpy_border_3);
  tcase_add_test(tc_core, s21_strncpy_border_4);
  tcase_add_test(tc_core, s21_strncpy_border_maxn);

  tcase_add_test(tc_core, s21_strncpy_other_null);
  tcase_add_test(tc_core, s21_strncpy_other_bytes);
  tcase_add_test(tc_core, s21_strncpy_other_sb);
  tcase_add_test(tc_core, s21_strncpy_other_empt_src);
  tcase_add_test(tc_core, s21_strncpy_other_ptr_af);
  tcase_add_test(tc_core, s21_strncpy_other_ptr_bf);
  tcase_add_test(tc_core, s21_strncpy_other_ptr);
  tcase_add_test(tc_core, s21_strncpy_other_num);
  tcase_add_test(tc_core, s21_strncpy_other_SC);

  suite_add_tcase(s, tc_core);

  return s;
}
