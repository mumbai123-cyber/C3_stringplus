#define _POSIX_C_SOURCE 200809L
#include "s21_to_upper_suit.h"

#include "../s21_string.h"

START_TEST(test_to_upper_basic) {
  const char *str = "hello world";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "HELLO WORLD");
  free(result);
}
END_TEST

START_TEST(test_to_upper_mixed_case) {
  const char *str = "HeLLo WoRLd";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "HELLO WORLD");
  free(result);
}
END_TEST

START_TEST(test_to_upper_already_upper) {
  const char *str = "HELLO";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(test_to_upper_with_numbers) {
  const char *str = "hello123world";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "HELLO123WORLD");
  free(result);
}
END_TEST

START_TEST(test_to_upper_with_special_chars) {
  const char *str = "hello!@#$%^&*()";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "HELLO!@#$%^&*()");
  free(result);
}
END_TEST

START_TEST(test_to_upper_empty_string) {
  const char *str = "";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_to_upper_single_char) {
  const char *str = "a";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "A");
  free(result);
}
END_TEST

START_TEST(test_to_upper_all_letters) {
  const char *str = "abcdefghijklmnopqrstuvwxyz";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(result);
}
END_TEST

START_TEST(test_to_upper_russian_letters) {
  const char *str = "привет";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "привет");
  free(result);
}
END_TEST

START_TEST(test_to_upper_null_input) {
  char *result = s21_to_upper(NULL);

  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_to_upper_unicode) {
  const char *str = "café";
  char *result = s21_to_upper(str);

  ck_assert_str_eq(result, "CAFé");
  free(result);
}
END_TEST

START_TEST(test_to_upper_memory_allocation) {
  size_t long_length = 10000;
  char *long_str = (char *)malloc(long_length + 1);

  for (size_t i = 0; i < long_length; i++) {
    long_str[i] = 'a' + (i % 26);
  }
  long_str[long_length] = '\0';

  char *result = s21_to_upper(long_str);

  ck_assert_int_eq(result[0], 'A');
  ck_assert_int_eq(result[25], 'Z');

  free(long_str);
  free(result);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *suite = suite_create("s21_to_upper");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_upper_basic);
  tcase_add_test(tc_core, test_to_upper_mixed_case);
  tcase_add_test(tc_core, test_to_upper_already_upper);
  tcase_add_test(tc_core, test_to_upper_with_numbers);
  tcase_add_test(tc_core, test_to_upper_with_special_chars);
  tcase_add_test(tc_core, test_to_upper_empty_string);
  tcase_add_test(tc_core, test_to_upper_single_char);
  tcase_add_test(tc_core, test_to_upper_all_letters);
  tcase_add_test(tc_core, test_to_upper_russian_letters);
  tcase_add_test(tc_core, test_to_upper_null_input);
  tcase_add_test(tc_core, test_to_upper_unicode);
  tcase_add_test(tc_core, test_to_upper_memory_allocation);

  suite_add_tcase(suite, tc_core);

  return suite;
}