#define _POSIX_C_SOURCE 200809L
#include "s21_strchr_suit.h"

#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strchr_basic) {
  const char *str = "hello world";
  char *res = s21_strchr(str, 'l');
  char *expected = strchr(str, 'l');
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strchr_not_found) {
  const char *str = "hello";
  char *res = s21_strchr(str, 'x');
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(test_s21_strchr_null_terminator) {
  const char *str = "hello";
  char *res = s21_strchr(str, '\0');
  ck_assert_ptr_eq(res, str + strlen(str));
}
END_TEST

START_TEST(test_s21_strchr_empty_string) {
  const char *str = "";
  char *res = s21_strchr(str, '\0');
  ck_assert_ptr_eq(res, str);
}
END_TEST

Suite *s21_strchr_suite() {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("case_s21_strchr");

  tcase_add_test(tc, test_s21_strchr_basic);
  tcase_add_test(tc, test_s21_strchr_not_found);
  tcase_add_test(tc, test_s21_strchr_null_terminator);
  tcase_add_test(tc, test_s21_strchr_empty_string);

  suite_add_tcase(s, tc);
  return s;
}
