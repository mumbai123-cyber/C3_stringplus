#include "s21_strpbrk_suit.h"

#include <string.h>

#include "../s21_string.h"

START_TEST(s21_strpbrk_base) {
  const char *str1 = "hello world";
  const char *str2 = "aeiou";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);

  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_base_empty_search) {
  const char *str1 = "hello";
  const char *str2 = "";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strpbrk_base_empty_str) {
  const char *str1 = "";
  const char *str2 = "hello";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strpbrk_base_both_empty) {
  const char *str1 = "";
  const char *str2 = "";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strpbrk_standard) {
  const char *str1 = "Hello, world!";
  const char *str2 = " ,!";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_standard_first_char) {
  const char *str1 = "abcdef";
  const char *str2 = "a";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_standard_last_char) {
  const char *str1 = "abcdef";
  const char *str2 = "f";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_standard_no_match) {
  const char *str1 = "hello";
  const char *str2 = "xyz";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strpbrk_border_NL) {
  const char *str1 = "hello\nworld";
  const char *str2 = "\n";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_border_tab) {
  const char *str1 = "tab\tseparated";
  const char *str2 = "\t";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_border_lowC) {
  const char *str1 = "Hello";
  const char *str2 = "h";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strpbrk_border_upC) {
  const char *str1 = "Hello";
  const char *str2 = "H";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_other_chars_many) {
  const char *str1 = "hello";
  const char *str2 = "abcdefghijklmnopqrstuvwxyz";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_other_all_match) {
  const char *str1 = "abc";
  const char *str2 = "abc";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_other_null) {
  char str1[8] = {'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0'};
  const char *str2 = "d";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strpbrk_other_search_null) {
  const char *str1 = "hello";
  char str2[8] = {'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0'};

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strpbrk_other_all_same) {
  const char *str1 = "aaaaa";
  const char *str2 = "a";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
    ck_assert_ptr_eq(res1, str1);
    ck_assert_ptr_eq(res2, str1);
  }
}
END_TEST

START_TEST(s21_strpbrk_other_no_match_long) {
  const char *str1 = "bbbbb";
  const char *str2 = "a";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strpbrk_other_SC) {
  const char *str1 = "!@#$%^&*()";
  const char *str2 = "*&^";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_other_numbers) {
  const char *str1 = "12345";
  const char *str2 = "345";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_other_ptr) {
  char buf1[30] = "Hello, world!";

  const char *str1 = buf1 + 2;
  const char *str2 = "oe";

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
  }
}
END_TEST

START_TEST(s21_strpbrk_other_bstr) {
  char str1[1024];
  char str2[1024];

  memset(str1, 'a', sizeof(str1) - 1);
  memset(str2, 'b', sizeof(str2) - 1);
  str1[sizeof(str1) - 1] = '\0';
  str2[sizeof(str2) - 1] = '\0';

  str1[500] = 'b';

  char *res1 = s21_strpbrk(str1, str2);
  char *res2 = strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
  if (res1 && res2) {
    ck_assert_int_eq(*res1, *res2);
    ck_assert_ptr_eq(res1, str1 + 500);
    ck_assert_ptr_eq(res2, str1 + 500);
  }
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strpbrk");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strpbrk_base);
  tcase_add_test(tc_core, s21_strpbrk_base_empty_search);
  tcase_add_test(tc_core, s21_strpbrk_base_empty_str);
  tcase_add_test(tc_core, s21_strpbrk_base_both_empty);

  tcase_add_test(tc_core, s21_strpbrk_standard);
  tcase_add_test(tc_core, s21_strpbrk_standard_first_char);
  tcase_add_test(tc_core, s21_strpbrk_standard_last_char);
  tcase_add_test(tc_core, s21_strpbrk_standard_no_match);

  tcase_add_test(tc_core, s21_strpbrk_border_NL);
  tcase_add_test(tc_core, s21_strpbrk_border_tab);
  tcase_add_test(tc_core, s21_strpbrk_border_lowC);
  tcase_add_test(tc_core, s21_strpbrk_border_upC);

  tcase_add_test(tc_core, s21_strpbrk_other_chars_many);
  tcase_add_test(tc_core, s21_strpbrk_other_all_match);
  tcase_add_test(tc_core, s21_strpbrk_other_null);
  tcase_add_test(tc_core, s21_strpbrk_other_search_null);
  tcase_add_test(tc_core, s21_strpbrk_other_all_same);
  tcase_add_test(tc_core, s21_strpbrk_other_no_match_long);
  tcase_add_test(tc_core, s21_strpbrk_other_SC);
  tcase_add_test(tc_core, s21_strpbrk_other_numbers);
  tcase_add_test(tc_core, s21_strpbrk_other_ptr);
  tcase_add_test(tc_core, s21_strpbrk_other_bstr);

  suite_add_tcase(s, tc_core);

  return s;
}
