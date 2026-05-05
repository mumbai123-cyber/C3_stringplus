#include "s21_insert_suit.h"

#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(s21_insert_base_beginning) {
  char src[] = "world";
  char str[] = "Hello ";
  s21_size start_index = 0;

  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello world";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_base_middle) {
  char src[] = "Hello world";
  char str[] = "beautiful ";
  s21_size start_index = 6;

  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello beautiful world";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_base_end) {
  char src[] = "Hello";
  char str[] = " world";
  s21_size start_index = 5;

  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello world";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_empty_src) {
  char src[] = "";
  char str[] = "Hello";
  s21_size start_index = 0;

  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, str);
  free(result);
}
END_TEST

START_TEST(s21_insert_empty_str) {
  char src[] = "Hello";
  char str[] = "";
  s21_size start_index = 3;

  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, src);
  free(result);
}
END_TEST

START_TEST(s21_insert_both_empty) {
  char src[] = "";
  char str[] = "";
  s21_size start_index = 0;

  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_insert_boundary_zero) {
  char src[] = "Hello";
  char str[] = "Hi";
  s21_size start_index = 0;

  char *result = s21_insert(src, str, start_index);
  char expected[] = "HiHello";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_boundary_length) {
  char src[] = "Hello";
  char str[] = "World";
  s21_size start_index = 5;

  char *result = s21_insert(src, str, start_index);
  char expected[] = "HelloWorld";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_null_src) {
  char *result = s21_insert(NULL, "str", 0);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(s21_insert_null_str) {
  char *result = s21_insert("src", NULL, 0);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(s21_insert_both_null) {
  char *result = s21_insert(NULL, NULL, 0);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(s21_insert_index_out_of_range) {
  char src[] = "Hello";
  char str[] = "World";
  s21_size start_index = 10;

  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(s21_insert_index_eq_length_plus_one) {
  char src[] = "Hello";
  char str[] = "World";
  s21_size start_index = 6;

  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(s21_insert_special_chars) {
  char src[] = "Hello\nWorld";
  char str[] = "\tTab\t";
  s21_size start_index = 5;

  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello\tTab\t\nWorld";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_spaces) {
  char src[] = "HelloWorld";
  char str[] = " ";
  s21_size start_index = 5;

  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_long_src) {
  char src[] =
      "This is a very long source string that will be used for testing";
  char str[] = "INSERTED ";
  s21_size start_index = 20;

  char *result = s21_insert(src, str, start_index);
  char expected[200];

  strncpy(expected, src, start_index);
  expected[start_index] = '\0';
  strcat(expected, str);
  strcat(expected, src + start_index);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_long_str) {
  char src[] = "Hello";
  char str[] =
      " this is a very long string that will be inserted into the source";
  s21_size start_index = 5;

  char *result = s21_insert(src, str, start_index);
  char expected[200];

  strcpy(expected, src);
  strcat(expected, str);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_repeated) {
  char src[] = "aaaaa";
  char str[] = "bbb";
  s21_size start_index = 2;

  char *result = s21_insert(src, str, start_index);
  char expected[] = "aabbbaaa";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_mixed) {
  char src[] = "123456";
  char str[] = "abc";
  s21_size start_index = 3;

  char *result = s21_insert(src, str, start_index);
  char expected[] = "123abc456";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_insert_multiple_calls) {
  char *results[10];

  for (int i = 0; i < 10; i++) {
    results[i] = s21_insert("Hello", " World", 5);
    ck_assert_ptr_nonnull(results[i]);
  }

  for (int i = 0; i < 10; i++) {
    ck_assert_str_eq(results[i], "Hello World");
    free(results[i]);
  }
}
END_TEST

START_TEST(s21_insert_null_terminator) {
  char src[] = "Hello";
  char str[] = " World";
  s21_size start_index = 5;

  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_nonnull(result);
  ck_assert_int_eq(result[11], '\0');
  free(result);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_insert");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_insert_base_beginning);
  tcase_add_test(tc_core, s21_insert_base_middle);
  tcase_add_test(tc_core, s21_insert_base_end);

  tcase_add_test(tc_core, s21_insert_empty_src);
  tcase_add_test(tc_core, s21_insert_empty_str);
  tcase_add_test(tc_core, s21_insert_both_empty);

  tcase_add_test(tc_core, s21_insert_boundary_zero);
  tcase_add_test(tc_core, s21_insert_boundary_length);

  tcase_add_test(tc_core, s21_insert_null_src);
  tcase_add_test(tc_core, s21_insert_null_str);
  tcase_add_test(tc_core, s21_insert_both_null);

  tcase_add_test(tc_core, s21_insert_index_out_of_range);
  tcase_add_test(tc_core, s21_insert_index_eq_length_plus_one);

  tcase_add_test(tc_core, s21_insert_special_chars);
  tcase_add_test(tc_core, s21_insert_spaces);

  tcase_add_test(tc_core, s21_insert_long_src);
  tcase_add_test(tc_core, s21_insert_long_str);

  tcase_add_test(tc_core, s21_insert_repeated);
  tcase_add_test(tc_core, s21_insert_mixed);
  tcase_add_test(tc_core, s21_insert_multiple_calls);
  tcase_add_test(tc_core, s21_insert_null_terminator);

  suite_add_tcase(s, tc_core);

  return s;
}
