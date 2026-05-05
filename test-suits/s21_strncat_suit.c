#define _POSIX_C_SOURCE 200809L
#include "s21_strncat_suit.h"

#include "../s21_string.h"

START_TEST(test_strncat_basic) {
  char dest1[50] = "Hello, ";
  char dest2[50] = "Hello, ";
  const char *src = "World!";
  size_t n = 6;

  char *result1 = strncat(dest1, src, n);
  char *result2 = s21_strncat(dest2, src, n);

  ck_assert_str_eq(result1, result2);
  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
}
END_TEST

START_TEST(test_strncat_empty_dest) {
  char dest1[50] = "";
  char dest2[50] = "";
  const char *src = "Hello";
  size_t n = 5;

  char *result1 = strncat(dest1, src, n);
  char *result2 = s21_strncat(dest2, src, n);

  ck_assert_str_eq(result1, result2);
  ck_assert_str_eq(dest2, "Hello");
}
END_TEST

START_TEST(test_strncat_empty_src) {
  char dest1[50] = "Hello";
  char dest2[50] = "Hello";
  const char *src = "";
  size_t n = 5;

  char *result1 = strncat(dest1, src, n);
  char *result2 = s21_strncat(dest2, src, n);

  ck_assert_str_eq(result1, result2);
  ck_assert_str_eq(dest2, "Hello");
}
END_TEST

START_TEST(test_strncat_less_than_n) {
  char dest1[50] = "Hello, ";
  char dest2[50] = "Hello, ";
  const char *src = "World";
  size_t n = 10;

  char *result1 = strncat(dest1, src, n);
  char *result2 = s21_strncat(dest2, src, n);

  ck_assert_str_eq(result1, result2);
  ck_assert_str_eq(dest2, "Hello, World");
}
END_TEST

START_TEST(test_strncat_zero_n) {
  char dest1[50] = "Hello";
  char dest2[50] = "Hello";
  const char *src = "World";
  size_t n = 0;

  char *result1 = strncat(dest1, src, n);
  char *result2 = s21_strncat(dest2, src, n);

  ck_assert_str_eq(result1, result2);
  ck_assert_str_eq(dest2, "Hello");
}
END_TEST

START_TEST(test_strncat_partial_n) {
  char dest1[50] = "Hello, ";
  char dest2[50] = "Hello, ";
  const char *src = "World!";
  size_t n = 3;

  char *result1 = strncat(dest1, src, n);
  char *result2 = s21_strncat(dest2, src, n);

  ck_assert_str_eq(result1, result2);
  ck_assert_str_eq(dest2, "Hello, Wor");
}
END_TEST

START_TEST(test_strncat_dest_with_null_inside) {
  char dest1[50] = "Hello\0World";
  char dest2[50] = "Hello\0World";
  const char *src = "!";
  size_t n = 1;

  char *result1 = strncat(dest1, src, n);
  char *result2 = s21_strncat(dest2, src, n);

  ck_assert_str_eq(result1, result2);
  ck_assert_str_eq(dest2, "Hello!");
}
END_TEST

START_TEST(test_strncat_large_n) {
  char dest1[100] = "Start";
  char dest2[100] = "Start";
  const char *src = " and end";
  size_t n = 20;

  char *result1 = strncat(dest1, src, n);
  char *result2 = s21_strncat(dest2, src, n);

  ck_assert_str_eq(result1, result2);
  ck_assert_str_eq(dest2, "Start and end");
}
END_TEST

START_TEST(test_strncat_special_chars) {
  char dest1[50] = "Test";
  char dest2[50] = "Test";
  const char *src = "\t\n\r\0hidden";
  size_t n = 3;

  char *result1 = strncat(dest1, src, n);
  char *result2 = s21_strncat(dest2, src, n);

  ck_assert_mem_eq(result1, result2, strlen(dest1) + 1);
}
END_TEST

START_TEST(test_strncat_multiple_concats) {
  char dest1[50] = "";
  char dest2[50] = "";
  const char *parts[] = {"Hello", ", ", "World", "!"};
  size_t n = 10;

  for (int i = 0; i < 4; i++) {
    strncat(dest1, parts[i], n);
    s21_strncat(dest2, parts[i], n);
  }

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest2, "Hello, World!");
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *suite = suite_create("s21_strncat");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strncat_basic);
  tcase_add_test(tc_core, test_strncat_empty_dest);
  tcase_add_test(tc_core, test_strncat_empty_src);
  tcase_add_test(tc_core, test_strncat_less_than_n);
  tcase_add_test(tc_core, test_strncat_zero_n);
  tcase_add_test(tc_core, test_strncat_partial_n);
  tcase_add_test(tc_core, test_strncat_dest_with_null_inside);
  tcase_add_test(tc_core, test_strncat_large_n);
  tcase_add_test(tc_core, test_strncat_special_chars);
  tcase_add_test(tc_core, test_strncat_multiple_concats);

  suite_add_tcase(suite, tc_core);

  return suite;
}
