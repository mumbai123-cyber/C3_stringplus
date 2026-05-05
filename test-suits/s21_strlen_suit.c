#define _POSIX_C_SOURCE 200809L
#include "s21_strlen_suit.h"

#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strlen) {
  ck_assert_int_eq(s21_strlen(""), strlen(""));
  ck_assert_int_eq(s21_strlen("this is a string"), strlen("this is a string"));
  ck_assert_int_eq(s21_strlen("this is a broken\0 string"),
                   strlen("this is a broken\0 stting"));
  ck_assert_int_eq(s21_strlen("Hello\nWorld\t!"), strlen("Hello\nWorld\t!"));
  ck_assert_int_eq(s21_strlen("1234567890"), strlen("1234567890"));
  ck_assert_int_eq(s21_strlen("!@#$%^&*("), strlen("!@#$%^&*("));
  ck_assert_int_eq(s21_strlen("Привет"), strlen("Привет"));
  char buffer[100];
  char *str = buffer + 1;
  strcpy(str, "Hello");
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strlen");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strlen);

  suite_add_tcase(s, tc_core);

  return s;
}
