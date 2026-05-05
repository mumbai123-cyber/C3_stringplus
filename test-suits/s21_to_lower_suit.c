#define _POSIX_C_SOURCE 200809L
#include "s21_to_lower_suit.h"

#include "../s21_string.h"

START_TEST(test_to_lower_basic) {
  const char *str = "HELLO WORLD";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "hello world");
  free(result);
}
END_TEST

START_TEST(test_to_lower_mixed_case) {
  const char *str = "HeLLo WoRLd";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "hello world");
  free(result);
}
END_TEST

START_TEST(test_to_lower_already_lower) {
  const char *str = "hello";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_to_lower_with_numbers) {
  const char *str = "HELLO123WORLD";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "hello123world");
  free(result);
}
END_TEST

START_TEST(test_to_lower_with_special_chars) {
  const char *str = "HELLO!@#$%^&*()";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "hello!@#$%^&*()");
  free(result);
}
END_TEST

START_TEST(test_to_lower_empty_string) {
  const char *str = "";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_to_lower_single_char) {
  const char *str = "A";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "a");
  free(result);
}
END_TEST

START_TEST(test_to_lower_all_letters) {
  const char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "abcdefghijklmnopqrstuvwxyz");
  free(result);
}
END_TEST

START_TEST(test_to_lower_russian_letters) {
  const char *str = "ПРИВЕТ";
  char *result = s21_to_lower(str);

  // Русские буквы не должны измениться (работаем только с ASCII)
  ck_assert_str_eq(result, "ПРИВЕТ");
  free(result);
}
END_TEST

START_TEST(test_to_lower_null_input) {
  char *result = s21_to_lower(NULL);

  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_to_lower_unicode) {
  const char *str = "CAFÉ";
  char *result = s21_to_lower(str);

  // Не-ASCII символы не должны измениться
  ck_assert_str_eq(result, "cafÉ");
  free(result);
}
END_TEST

START_TEST(test_to_lower_mixed_with_spaces) {
  const char *str = "HELLO   WORLD   TEST";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "hello   world   test");
  free(result);
}
END_TEST

START_TEST(test_to_lower_memory_allocation) {
  // Очень длинная строка для проверки выделения памяти
  size_t long_length = 10000;
  char *long_str = (char *)malloc(long_length + 1);

  for (size_t i = 0; i < long_length; i++) {
    long_str[i] = 'A' + (i % 26);
  }
  long_str[long_length] = '\0';

  char *result = s21_to_lower(long_str);

  // Проверяем первые несколько символов
  ck_assert_int_eq(result[0], 'a');
  ck_assert_int_eq(result[25], 'z');

  free(long_str);
  free(result);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *suite = suite_create("s21_to_lower");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_lower_basic);
  tcase_add_test(tc_core, test_to_lower_mixed_case);
  tcase_add_test(tc_core, test_to_lower_already_lower);
  tcase_add_test(tc_core, test_to_lower_with_numbers);
  tcase_add_test(tc_core, test_to_lower_with_special_chars);
  tcase_add_test(tc_core, test_to_lower_empty_string);
  tcase_add_test(tc_core, test_to_lower_single_char);
  tcase_add_test(tc_core, test_to_lower_all_letters);
  tcase_add_test(tc_core, test_to_lower_russian_letters);
  tcase_add_test(tc_core, test_to_lower_null_input);
  tcase_add_test(tc_core, test_to_lower_unicode);
  tcase_add_test(tc_core, test_to_lower_mixed_with_spaces);
  tcase_add_test(tc_core, test_to_lower_memory_allocation);

  suite_add_tcase(suite, tc_core);

  return suite;
}
