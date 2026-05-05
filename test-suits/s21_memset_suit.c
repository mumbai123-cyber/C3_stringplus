#define _POSIX_C_SOURCE 200809L
#include "s21_memset_suit.h"

#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_memset_basic) {
  char str1[100] = "Hello World";
  char str2[100] = "Hello World";
  int c = 'X';
  size_t n = 5;

  char *result1 = s21_memset(str1, c, n);
  char *result2 = memset(str2, c, n);

  ck_assert_ptr_nonnull(result1);
  ck_assert_ptr_nonnull(result2);

  ck_assert_ptr_eq(result1, str1);
  ck_assert_ptr_eq(result2, str2);

  ck_assert_mem_eq(str1, str2, sizeof(str1));
}
END_TEST

START_TEST(test_s21_memset_full_string) {
  char str1[100] = "Hello World";
  char str2[100] = "Hello World";
  int c = 'A';
  size_t n = strlen(str1) + 1;

  s21_memset(str1, c, n);
  memset(str2, c, n);

  ck_assert_mem_eq(str1, str2, n);
}
END_TEST

START_TEST(test_s21_memset_zero_bytes) {
  char str1[100] = "Hello World";
  char str2[100] = "Hello World";
  int c = 'Z';
  size_t n = 0;

  char *original_str1 = strdup(str1);

  s21_memset(str1, c, n);
  memset(str2, c, n);

  ck_assert_str_eq(str1, original_str1);
  ck_assert_str_eq(str2, original_str1);

  free(original_str1);
}
END_TEST

START_TEST(test_s21_memset_partial) {
  char str1[100] = "Hello World";
  char str2[100] = "Hello World";
  int c = 'B';
  size_t n = 5;

  s21_memset(str1, c, n);
  memset(str2, c, n);

  ck_assert_mem_eq(str1, str2, n);

  ck_assert_mem_eq(str1 + n, str2 + n, strlen(str1) - n);
}
END_TEST

START_TEST(test_s21_memset_with_null_character) {
  char str1[100] = "Hello World";
  char str2[100] = "Hello World";
  int c = '\0';
  size_t n = 5;

  s21_memset(str1, c, n);
  memset(str2, c, n);

  ck_assert_mem_eq(str1, str2, n);

  ck_assert_int_eq(str1[0], '\0');
}
END_TEST

START_TEST(test_s21_memset_large_buffer) {
  size_t size = 1024;
  char *str1 = malloc(size);
  char *str2 = malloc(size);
  int c = -1;

  if (!str1 || !str2) {
    free(str1);
    free(str2);
    ck_abort_msg("Not enough memory to allocate %llu bytes for test",
                 (unsigned long long)size);
  }

  memset(str1, 170, size);
  memset(str2, 170, size);

  s21_memset(str1, c, size);
  memset(str2, c, size);

  ck_assert_mem_eq(str1, str2, size);

  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_s21_memset_edge_cases) {
  char str1[10];
  char str2[10];

  s21_memset(str1, 18, sizeof(str1));
  memset(str2, 18, sizeof(str1));
  ck_assert_mem_eq(str1, str2, sizeof(str1));

  char small_buf1[5] = {0};
  char small_buf2[5] = {0};

  s21_memset(small_buf1, 52, 3);
  memset(small_buf2, 52, 3);
  ck_assert_mem_eq(small_buf1, small_buf2, 3);
  ck_assert_int_eq(small_buf1[3], 0);
  ck_assert_int_eq(small_buf1[4], 0);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *suite = suite_create("s21_memset");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memset_basic);
  tcase_add_test(tc_core, test_s21_memset_full_string);
  tcase_add_test(tc_core, test_s21_memset_zero_bytes);
  tcase_add_test(tc_core, test_s21_memset_partial);
  tcase_add_test(tc_core, test_s21_memset_with_null_character);
  tcase_add_test(tc_core, test_s21_memset_large_buffer);
  tcase_add_test(tc_core, test_s21_memset_edge_cases);

  suite_add_tcase(suite, tc_core);
  return suite;
}
