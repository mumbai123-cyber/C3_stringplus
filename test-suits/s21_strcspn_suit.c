#include "s21_strcspn_suit.h"

#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(s21_strcspn_base_empty_str_1) {
  ck_assert_int_eq(s21_strcspn("", "hello"), strcspn("", "hello"));
}
END_TEST

START_TEST(s21_strcspn_base_empty_str_2) {
  ck_assert_int_eq(s21_strcspn("hello", ""), strcspn("hello", ""));
}
END_TEST

START_TEST(s21_strcspn_base_strs_empty) {
  ck_assert_int_eq(s21_strcspn("", ""), strcspn("", ""));
}
END_TEST

START_TEST(s21_strcspn_standart) {
  ck_assert_int_eq(s21_strcspn("hello world", " "),
                   strcspn("hello world", " "));
}
END_TEST

START_TEST(s21_strcspn_standart_first_char) {
  ck_assert_int_eq(s21_strcspn("abcdef", "a"), strcspn("abcdef", "a"));
}
END_TEST

START_TEST(s21_strcspn_standart_last_char) {
  ck_assert_int_eq(s21_strcspn("abcdef", "f"), strcspn("abcdef", "f"));
}
END_TEST

START_TEST(s21_strcspn_standart_no_match) {
  ck_assert_int_eq(s21_strcspn("hello", "abcd"), strcspn("hello", "abcd"));
}
END_TEST

START_TEST(s21_strcspn_border_nl) {
  ck_assert_int_eq(s21_strcspn("hello\nworld", "\n"),
                   strcspn("hello\nworld", "\n"));
}
END_TEST

START_TEST(s21_strcspn_border_tab) {
  ck_assert_int_eq(s21_strcspn("tab\tseparated", "\t"),
                   strcspn("tab\tseparated", "\t"));
}
END_TEST

START_TEST(s21_strcspn_border_repeated) {
  ck_assert_int_eq(s21_strcspn("abbaabba", "brak"),
                   strcspn("abbaabba", "brak"));
}
END_TEST

START_TEST(s21_strcspn_border_low) {
  ck_assert_int_eq(s21_strcspn("Hello", "h"), strcspn("Hello", "h"));
}
END_TEST

START_TEST(s21_strcspn_border_up) {
  ck_assert_int_eq(s21_strcspn("Hello", "H"), strcspn("Hello", "H"));
}
END_TEST

START_TEST(s21_strcspn_border_null_in_str) {
  ck_assert_int_eq(s21_strcspn("Hello\0World", "W"),
                   strcspn("Hello\0World", "W"));
}
END_TEST

START_TEST(s21_strcspn_border_null_src) {
  ck_assert_int_eq(s21_strcspn("Hello\0World", "\0"),
                   strcspn("Hello\0World", "\0"));
}
END_TEST

START_TEST(s21_strcspn_other_many_chars) {
  ck_assert_int_eq(s21_strcspn("hello", "abcdefghijklmnopqrstuvwxyz"),
                   strcspn("hello", "abcdefghijklmnopqrstuvwxyz"));
}
END_TEST

START_TEST(s21_strcspn_other_SC) {
  ck_assert_int_eq(s21_strcspn("!@#$%^&*()", "@#$"),
                   strcspn("!@#$%^&*()", "@#$"));
}
END_TEST

START_TEST(s21_strcspn_other_SC_no_match) {
  ck_assert_int_eq(s21_strcspn("!@#$%^&*()", " "), strcspn("!@#$%^&*()", " "));
}
END_TEST

START_TEST(s21_strcspn_other_whitespace_match) {
  ck_assert_int_eq(s21_strcspn(" \t\n\r\v\f", " \t"),
                   strcspn(" \t\n\r\v\f", " \t"));
}
END_TEST

START_TEST(s21_strcspn_other_whitespace_no_match) {
  ck_assert_int_eq(s21_strcspn(" \t\n\r\v\f", "x"),
                   strcspn(" \t\n\r\v\f", "x"));
}
END_TEST

START_TEST(s21_strcspn_other_numbers) {
  ck_assert_int_eq(s21_strcspn("12345", "345"), strcspn("12345", "345"));
}
END_TEST

START_TEST(s21_strcspn_other_numbers_no_match) {
  ck_assert_int_eq(s21_strcspn("12345", "678"), strcspn("12345", "678"));
}
END_TEST

START_TEST(s21_strcspn_other_numbers_single_no_match) {
  ck_assert_int_eq(s21_strcspn("12345", "0"), strcspn("12345", "0"));
}
END_TEST

START_TEST(s21_strcspn_other_numbers_all_match) {
  ck_assert_int_eq(s21_strcspn("12345", "12345"), strcspn("12345", "12345"));
}
END_TEST

START_TEST(s21_strcspn_other_mixed_alnum) {
  ck_assert_int_eq(s21_strcspn("abc123!@#", "123"),
                   strcspn("abc123!@#", "123"));
}
END_TEST

START_TEST(s21_strcspn_other_long_strings_no_match) {
  char str1[1024];
  char str2[1024];

  memset(str1, 'a', sizeof(str1) - 1);
  memset(str2, 'b', sizeof(str2) - 1);
  str1[sizeof(str1) - 1] = '\0';
  str2[sizeof(str2) - 1] = '\0';

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_other_long_strings_match) {
  char str1[1024];
  char str2[1024];

  memset(str1, 'a', sizeof(str1) - 1);
  memset(str2, 'b', sizeof(str2) - 1);
  str1[sizeof(str1) - 1] = '\0';
  str2[sizeof(str2) - 1] = '\0';

  str1[500] = 'b';
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_other_ptr) {
  char str[30] = "Hello, world!";
  const char *str1 = str + 2;
  const char *str2 = "oe";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_other_long_reject) {
  char reject[256];
  for (int i = 0; i < 255; i++) {
    reject[i] = (char)(i + 1);
  }
  reject[255] = '\0';
  ck_assert_int_eq(s21_strcspn("hello", reject), strcspn("hello", reject));
}
END_TEST

START_TEST(s21_strcspn_other_long_reject_match) {
  char reject[256];
  for (int i = 0; i < 255; i++) {
    reject[i] = (char)(i + 1);
  }
  reject[255] = '\0';

  ck_assert_int_eq(s21_strcspn("\x01hello", reject),
                   strcspn("\x01hello", reject));
}
END_TEST

START_TEST(s21_strcspn_overlap) {
  char str[] = "abcabc";

  if (str != str + 1) {
    ck_assert_int_eq(s21_strcspn(str, str + 1), strcspn(str, str + 1));
  }
}
END_TEST

START_TEST(s21_strcspn_one_pointer) {
  char str[] = "hello";
  ck_assert_int_eq(s21_strcspn(str, str), strcspn(str, str));
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strcspn");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strcspn_base_empty_str_1);
  tcase_add_test(tc_core, s21_strcspn_base_empty_str_2);
  tcase_add_test(tc_core, s21_strcspn_base_strs_empty);

  tcase_add_test(tc_core, s21_strcspn_standart);
  tcase_add_test(tc_core, s21_strcspn_standart_first_char);
  tcase_add_test(tc_core, s21_strcspn_standart_last_char);
  tcase_add_test(tc_core, s21_strcspn_standart_no_match);

  tcase_add_test(tc_core, s21_strcspn_border_nl);
  tcase_add_test(tc_core, s21_strcspn_border_tab);
  tcase_add_test(tc_core, s21_strcspn_border_repeated);
  tcase_add_test(tc_core, s21_strcspn_border_low);
  tcase_add_test(tc_core, s21_strcspn_border_up);
  tcase_add_test(tc_core, s21_strcspn_border_null_in_str);
  tcase_add_test(tc_core, s21_strcspn_border_null_src);

  tcase_add_test(tc_core, s21_strcspn_other_many_chars);
  tcase_add_test(tc_core, s21_strcspn_other_SC);
  tcase_add_test(tc_core, s21_strcspn_other_SC_no_match);
  tcase_add_test(tc_core, s21_strcspn_other_whitespace_match);
  tcase_add_test(tc_core, s21_strcspn_other_whitespace_no_match);
  tcase_add_test(tc_core, s21_strcspn_other_numbers);
  tcase_add_test(tc_core, s21_strcspn_other_numbers_no_match);
  tcase_add_test(tc_core, s21_strcspn_other_numbers_single_no_match);
  tcase_add_test(tc_core, s21_strcspn_other_numbers_all_match);
  tcase_add_test(tc_core, s21_strcspn_other_mixed_alnum);
  tcase_add_test(tc_core, s21_strcspn_other_long_strings_no_match);
  tcase_add_test(tc_core, s21_strcspn_other_long_strings_match);
  tcase_add_test(tc_core, s21_strcspn_other_ptr);
  tcase_add_test(tc_core, s21_strcspn_other_long_reject);
  tcase_add_test(tc_core, s21_strcspn_other_long_reject_match);

  tcase_add_test(tc_core, s21_strcspn_overlap);
  tcase_add_test(tc_core, s21_strcspn_one_pointer);

  suite_add_tcase(s, tc_core);

  return s;
}
