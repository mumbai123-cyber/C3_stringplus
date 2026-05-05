#include "s21_memcmp_suit.h"

#include <string.h>

#include "../s21_string.h"
#include "test_utils.h"

START_TEST(test_memcmp_equal) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  size_t n = 5;

  int std_result = memcmp(str1, str2, n);
  int s21_result = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(std_result, s21_result);
}
END_TEST

START_TEST(test_memcmp_first_less) {
  char str1[] = "Hello";
  char str2[] = "HelLo";
  size_t n = 5;

  int std_result = memcmp(str1, str2, n);
  int s21_result = s21_memcmp(str1, str2, n);

  ck_assert_int_gt(s21_result, 0);
  ck_assert_int_eq((std_result > 0) - (std_result < 0),
                   (s21_result > 0) - (s21_result < 0));
}
END_TEST

START_TEST(test_memcmp_first_greater) {
  char str1[] = "HelLo";
  char str2[] = "Hello";
  size_t n = 5;

  int std_result = memcmp(str1, str2, n);
  int s21_result = s21_memcmp(str1, str2, n);

  ck_assert_int_lt(s21_result, 0);
  ck_assert_sign_eq(std_result, s21_result);
}
END_TEST

START_TEST(test_memcmp_partial) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  size_t n = 5;

  int std_result = memcmp(str1, str2, n);
  int s21_result = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(std_result, s21_result);
}
END_TEST

START_TEST(test_memcmp_different_at_end) {
  char str1[] = "Hello";
  char str2[] = "Hellz";
  size_t n = 5;

  int std_result = memcmp(str1, str2, n);
  int s21_result = s21_memcmp(str1, str2, n);

  ck_assert_sign_eq(std_result, s21_result);
}
END_TEST

START_TEST(test_memcmp_zero_length) {
  char str1[] = "Hello";
  char str2[] = "World";
  size_t n = 0;

  int std_result = memcmp(str1, str2, n);
  int s21_result = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(std_result, s21_result);
}
END_TEST

START_TEST(test_memcmp_binary_data) {
  unsigned char data1[] = {0x01, 0x02, 0x03, 0x04};
  unsigned char data2[] = {0x01, 0x02, 0x03, 0x05};
  size_t n = 4;

  int std_result = memcmp(data1, data2, n);
  int s21_result = s21_memcmp(data1, data2, n);

  ck_assert_int_eq(std_result, s21_result);
}
END_TEST

START_TEST(test_memcmp_identical_but_different_lengths) {
  char str1[] = "Hello";
  char str2[] = "Hello World";
  size_t n = 5;

  int std_result = memcmp(str1, str2, n);
  int s21_result = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(std_result, s21_result);
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *suite = suite_create("s21_memcmp");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memcmp_equal);
  tcase_add_test(tc_core, test_memcmp_first_less);
  tcase_add_test(tc_core, test_memcmp_first_greater);
  tcase_add_test(tc_core, test_memcmp_partial);
  tcase_add_test(tc_core, test_memcmp_different_at_end);
  tcase_add_test(tc_core, test_memcmp_zero_length);
  tcase_add_test(tc_core, test_memcmp_binary_data);
  tcase_add_test(tc_core, test_memcmp_identical_but_different_lengths);

  suite_add_tcase(suite, tc_core);

  return suite;
}
