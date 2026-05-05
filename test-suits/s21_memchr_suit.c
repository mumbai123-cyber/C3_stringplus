#include "s21_memchr_suit.h"

#include <string.h>

#include "../s21_string.h"

START_TEST(test_memchr_basic) {
  char str1[] = "Hello, World!";
  char *std_result1 = memchr(str1, 'W', strlen(str1));
  char *s21_result1 = s21_memchr(str1, 'W', strlen(str1));

  ck_assert_ptr_eq(std_result1, s21_result1);
}
END_TEST

START_TEST(test_memchr_not_found) {
  char str2[] = "Hello";
  char *std_result2 = memchr(str2, 'z', strlen(str2));
  char *s21_result2 = s21_memchr(str2, 'z', strlen(str2));

  ck_assert_ptr_eq(std_result2, s21_result2);
}
END_TEST

START_TEST(test_memchr_limit) {
  char str3[] = "Hello";
  char *std_result3 = memchr(str3, 'o', 3);
  char *s21_result3 = s21_memchr(str3, 'o', 3);

  ck_assert_ptr_eq(std_result3, s21_result3);
}
END_TEST

START_TEST(test_memchr_first_char) {
  char str4[] = "Test";
  char *std_result4 = memchr(str4, 'T', strlen(str4));
  char *s21_result4 = s21_memchr(str4, 'T', strlen(str4));

  ck_assert_ptr_eq(std_result4, s21_result4);
}
END_TEST

START_TEST(test_memchr_empty) {
  char str5[] = "";
  char *std_result5 = memchr(str5, 'a', 0);
  char *s21_result5 = s21_memchr(str5, 'a', 0);

  ck_assert_ptr_eq(std_result5, s21_result5);
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *suite = suite_create("s21_memchr");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memchr_basic);
  tcase_add_test(tc_core, test_memchr_not_found);
  tcase_add_test(tc_core, test_memchr_limit);
  tcase_add_test(tc_core, test_memchr_first_char);
  tcase_add_test(tc_core, test_memchr_empty);

  suite_add_tcase(suite, tc_core);

  return suite;
}
