#include "s21_strtok_suit.h"

#include <string.h>

#include "../s21_string.h"

START_TEST(s21_strtok_base_single_token) {
  char str1[] = "Hello";
  const char *delim = " ";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello";
  char *res2 = strtok(str2, delim);

  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_base_multiple_tokens) {
  char str1[] = "Hello world test";
  const char *delim = " ";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello world test";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_base_empty_string) {
  char str1[] = "";
  const char *delim = " ";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "";
  char *res2 = strtok(str2, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_base_empty_delim) {
  char str1[] = "Hello";
  const char *delim = "";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello";
  char *res2 = strtok(str2, delim);

  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_base_both_empty) {
  char str1[] = "";
  const char *delim = "";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "";
  char *res2 = strtok(str2, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_standard_multiple_delims) {
  char str1[] = "Hello,world;test";
  const char *delim = ",;";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello,world;test";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_standard_consecutive_delims) {
  char str1[] = "Hello,,,world;;;test";
  const char *delim = ",;";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello,,,world;;;test";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_standard_leading_delims) {
  char str1[] = ",,Hello,world";
  const char *delim = ",";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = ",,Hello,world";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_standard_trailing_delims) {
  char str1[] = "Hello,world,,";
  const char *delim = ",";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello,world,,";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_standard_only_delims) {
  char str1[] = ",,;;";
  const char *delim = ",;";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = ",,;;";
  char *res2 = strtok(str2, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_border_newline) {
  char str1[] = "Hello\nworld\ntest";
  const char *delim = "\n";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello\nworld\ntest";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_border_tab) {
  char str1[] = "Hello\tworld\ttest";
  const char *delim = "\t";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello\tworld\ttest";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_border_multiple_whitespace) {
  char str1[] = "Hello   world\t\ttest\n\nend";
  const char *delim = " \t\n";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello   world\t\ttest\n\nend";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_border_change_delim) {
  char str1_s21[] = "Hello,world;test";
  char str1_std[] = "Hello,world;test";
  const char *delim1 = ",";
  const char *delim2 = ";";

  char *res1_s21 = s21_strtok(str1_s21, delim1);
  res1_s21 = s21_strtok(NULL, delim2);

  char *res1_std = strtok(str1_std, delim1);
  res1_std = strtok(NULL, delim2);

  if (res1_s21 == NULL && res1_std == NULL) {
    ck_assert_ptr_eq(res1_s21, res1_std);
  } else {
    ck_assert_str_eq(res1_s21, res1_std);
  }
}
END_TEST

START_TEST(s21_strtok_other_special_chars) {
  char str1[] = "!@#$%^&*()";
  const char *delim = "@#$";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "!@#$%^&*()";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_other_numbers) {
  char str1[] = "123,456;789";
  const char *delim = ",;";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "123,456;789";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_other_mixed) {
  char str1[] = "abc123!@# def456$%^";
  const char *delim = " !@#$%^";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "abc123!@# def456$%^";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_other_long_string) {
  char str1_s21[1024];
  char str1_std[1024];
  const char *delim = " ";

  memset(str1_s21, 'a', sizeof(str1_s21) - 1);
  memset(str1_std, 'a', sizeof(str1_std) - 1);
  str1_s21[sizeof(str1_s21) - 1] = '\0';
  str1_std[sizeof(str1_std) - 1] = '\0';

  str1_s21[500] = ' ';
  str1_std[500] = ' ';
  str1_s21[800] = ' ';
  str1_std[800] = ' ';

  char *res1_s21 = s21_strtok(str1_s21, delim);
  char *res1_std = strtok(str1_std, delim);
  ck_assert_str_eq(res1_s21, res1_std);

  res1_s21 = s21_strtok(NULL, delim);
  res1_std = strtok(NULL, delim);

  if (res1_s21 == NULL && res1_std == NULL) {
    ck_assert_ptr_eq(res1_s21, res1_std);
  } else {
    ck_assert_str_eq(res1_s21, res1_std);
  }
}
END_TEST

START_TEST(s21_strtok_other_ptr_arithmetic) {
  char buffer1[30] = "Hello, world!";
  char buffer2[30] = "Hello, world!";
  const char *delim = " ,!";

  char *str1 = buffer1 + 2;
  char *str2 = buffer2 + 2;

  char *res1 = s21_strtok(str1, delim);
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_other_return_value) {
  char str1[] = "Hello world";
  const char *delim = " ";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello world";
  char *res2 = strtok(str2, delim);

  ck_assert_ptr_eq(res1, str1);
  ck_assert_ptr_eq(res2, str2);
}
END_TEST

START_TEST(s21_strtok_other_all_delims) {
  char str1[] = ",,,,,,";
  const char *delim = ",";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = ",,,,,,";
  char *res2 = strtok(str2, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_other_single_char_token) {
  char str1[] = "a,b,c";
  const char *delim = ",";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "a,b,c";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_other_token_at_end) {
  char str1[] = "Hello,world,";
  const char *delim = ",";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Hello,world,";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_other_token_at_start) {
  char str1[] = ",Hello,world";
  const char *delim = ",";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = ",Hello,world";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strtok_other_unicode) {
  char str1[] = "Привет,мир";
  const char *delim = ",";

  char *res1 = s21_strtok(str1, delim);

  char str2[] = "Привет,мир";
  char *res2 = strtok(str2, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_str_eq(res1, res2);

  res1 = s21_strtok(NULL, delim);
  res2 = strtok(NULL, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strtok");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strtok_base_single_token);
  tcase_add_test(tc_core, s21_strtok_base_multiple_tokens);
  tcase_add_test(tc_core, s21_strtok_base_empty_string);
  tcase_add_test(tc_core, s21_strtok_base_empty_delim);
  tcase_add_test(tc_core, s21_strtok_base_both_empty);

  tcase_add_test(tc_core, s21_strtok_standard_multiple_delims);
  tcase_add_test(tc_core, s21_strtok_standard_consecutive_delims);
  tcase_add_test(tc_core, s21_strtok_standard_leading_delims);
  tcase_add_test(tc_core, s21_strtok_standard_trailing_delims);
  tcase_add_test(tc_core, s21_strtok_standard_only_delims);

  tcase_add_test(tc_core, s21_strtok_border_newline);
  tcase_add_test(tc_core, s21_strtok_border_tab);
  tcase_add_test(tc_core, s21_strtok_border_multiple_whitespace);
  tcase_add_test(tc_core, s21_strtok_border_change_delim);

  tcase_add_test(tc_core, s21_strtok_other_special_chars);
  tcase_add_test(tc_core, s21_strtok_other_numbers);
  tcase_add_test(tc_core, s21_strtok_other_mixed);
  tcase_add_test(tc_core, s21_strtok_other_long_string);
  tcase_add_test(tc_core, s21_strtok_other_ptr_arithmetic);
  tcase_add_test(tc_core, s21_strtok_other_return_value);

  tcase_add_test(tc_core, s21_strtok_other_all_delims);
  tcase_add_test(tc_core, s21_strtok_other_single_char_token);
  tcase_add_test(tc_core, s21_strtok_other_token_at_end);
  tcase_add_test(tc_core, s21_strtok_other_token_at_start);
  tcase_add_test(tc_core, s21_strtok_other_unicode);

  suite_add_tcase(s, tc_core);

  return s;
}
