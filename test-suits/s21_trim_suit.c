#include "s21_trim_suit.h"

#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(s21_trim_base_spaces_both) {
  char src[] = "  Hello World  ";
  char *result = s21_trim(src, NULL);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_base_spaces_left) {
  char src[] = "  Hello World";
  char *result = s21_trim(src, NULL);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_base_spaces_right) {
  char src[] = "Hello World  ";
  char *result = s21_trim(src, NULL);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_base_no_spaces) {
  char src[] = "Hello World";
  char *result = s21_trim(src, NULL);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_specific_chars_both) {
  char src[] = "xxHello Worldxx";
  char trim_chars[] = "x";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_specific_chars_left) {
  char src[] = "xxxHello World";
  char trim_chars[] = "x";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_specific_chars_right) {
  char src[] = "Hello Worldxxx";
  char trim_chars[] = "x";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_specific_chars_multiple) {
  char src[] = "***!!!Hello World!!!***";
  char trim_chars[] = "*!";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_special_chars) {
  char src[] = "\n\t\rHello World\n\t\r";
  char *result = s21_trim(src, NULL);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_tab_chars) {
  char src[] = "\t\t\tHello World\t\t\t";
  char *result = s21_trim(src, NULL);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_newline_chars) {
  char src[] = "\n\n\nHello World\n\n\n";
  char *result = s21_trim(src, NULL);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_empty_src) {
  char src[] = "";
  char *result = s21_trim(src, NULL);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_trim_all_spaces) {
  char src[] = "     ";
  char *result = s21_trim(src, NULL);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_trim_all_specific_chars) {
  char src[] = "xxxxx";
  char trim_chars[] = "x";
  char *result = s21_trim(src, trim_chars);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_trim_single_char) {
  char src[] = "a";
  char *result = s21_trim(src, NULL);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "a");
  free(result);
}
END_TEST

START_TEST(s21_trim_single_char_trim) {
  char src[] = " ";
  char *result = s21_trim(src, NULL);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_trim_null_src) {
  char *result = s21_trim(NULL, "x");
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(s21_trim_null_trim_chars) {
  char src[] = "  Hello  ";
  char *result = s21_trim(src, NULL);
  char expected[] = "Hello";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_empty_trim_chars) {
  char src[] = "  Hello  ";
  char trim_chars[] = "";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_mixed_chars) {
  char src[] = " \t\nHello \t\nWorld \t\n";
  char *result = s21_trim(src, NULL);
  char expected[] = "Hello \t\nWorld";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_no_match) {
  char src[] = "Hello World";
  char trim_chars[] = "x";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_partial_match_left) {
  char src[] = "xxHello World";
  char trim_chars[] = "xy";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_partial_match_right) {
  char src[] = "Hello Worldxx";
  char trim_chars[] = "xy";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_numbers) {
  char src[] = "123Hello World123";
  char trim_chars[] = "123";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_special_symbols) {
  char src[] = "!@#$Hello World!@#$";
  char trim_chars[] = "!@#$";
  char *result = s21_trim(src, trim_chars);
  char expected[] = "Hello World";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(s21_trim_multiple_calls) {
  char *results[10];

  for (int i = 0; i < 10; i++) {
    results[i] = s21_trim("  Hello  ", NULL);
    ck_assert_ptr_nonnull(results[i]);
  }

  for (int i = 0; i < 10; i++) {
    ck_assert_str_eq(results[i], "Hello");
    free(results[i]);
  }
}
END_TEST

START_TEST(s21_trim_null_terminator) {
  char src[] = "  Hello  ";
  char *result = s21_trim(src, NULL);

  ck_assert_ptr_nonnull(result);
  ck_assert_int_eq(result[5], '\0');
  free(result);
}
END_TEST

START_TEST(s21_trim_long_string) {
  char src[1000];
  memset(src, ' ', 998);
  src[0] = 'H';
  src[1] = 'i';
  src[998] = '\0';

  char *result = s21_trim(src, NULL);
  char expected[] = "Hi";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_trim");
  tc_core = tcase_create("Core");

  // Базовые тесты с пробелами
  tcase_add_test(tc_core, s21_trim_base_spaces_both);
  tcase_add_test(tc_core, s21_trim_base_spaces_left);
  tcase_add_test(tc_core, s21_trim_base_spaces_right);
  tcase_add_test(tc_core, s21_trim_base_no_spaces);

  // Тесты с конкретными символами
  tcase_add_test(tc_core, s21_trim_specific_chars_both);
  tcase_add_test(tc_core, s21_trim_specific_chars_left);
  tcase_add_test(tc_core, s21_trim_specific_chars_right);
  tcase_add_test(tc_core, s21_trim_specific_chars_multiple);

  // Тесты со специальными символами
  tcase_add_test(tc_core, s21_trim_special_chars);
  tcase_add_test(tc_core, s21_trim_tab_chars);
  tcase_add_test(tc_core, s21_trim_newline_chars);

  // Тесты с пустыми и граничными строками
  tcase_add_test(tc_core, s21_trim_empty_src);
  tcase_add_test(tc_core, s21_trim_all_spaces);
  tcase_add_test(tc_core, s21_trim_all_specific_chars);
  tcase_add_test(tc_core, s21_trim_single_char);
  tcase_add_test(tc_core, s21_trim_single_char_trim);

  // Тесты с NULL аргументами
  tcase_add_test(tc_core, s21_trim_null_src);
  tcase_add_test(tc_core, s21_trim_null_trim_chars);
  tcase_add_test(tc_core, s21_trim_empty_trim_chars);

  // Тесты со сложными случаями
  tcase_add_test(tc_core, s21_trim_mixed_chars);
  tcase_add_test(tc_core, s21_trim_no_match);
  tcase_add_test(tc_core, s21_trim_partial_match_left);
  tcase_add_test(tc_core, s21_trim_partial_match_right);

  // Тесты с цифрами и символами
  tcase_add_test(tc_core, s21_trim_numbers);
  tcase_add_test(tc_core, s21_trim_special_symbols);

  // Дополнительные тесты
  tcase_add_test(tc_core, s21_trim_multiple_calls);
  tcase_add_test(tc_core, s21_trim_null_terminator);
  tcase_add_test(tc_core, s21_trim_long_string);

  suite_add_tcase(s, tc_core);

  return s;
}
