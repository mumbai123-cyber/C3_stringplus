#define _POSIX_C_SOURCE 200809L
#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strrchr_basic) {
  const char *str = "hello world";
  char *res = s21_strrchr(str, 'l');
  char *expected = strrchr(str, 'l');
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strrchr_not_found) {
  const char *str = "hello";
  char *res = s21_strrchr(str, 'x');
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(test_s21_strrchr_null_terminator) {
  const char *str = "hello";
  char *res = s21_strrchr(str, '\0');
  ck_assert_ptr_eq(res, str + strlen(str));
}
END_TEST

START_TEST(test_s21_strrchr_empty_string) {
  const char *str = "";
  char *res = s21_strrchr(str, '\0');
  ck_assert_ptr_eq(res, str);
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("case_s21_strrchr");

  tcase_add_test(tc, test_s21_strrchr_basic);
  tcase_add_test(tc, test_s21_strrchr_not_found);
  tcase_add_test(tc, test_s21_strrchr_null_terminator);
  tcase_add_test(tc, test_s21_strrchr_empty_string);

  suite_add_tcase(s, tc);
  return s;
}
