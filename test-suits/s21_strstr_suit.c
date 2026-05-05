#include "s21_strstr_suit.h"

#include <string.h>

#include "../s21_string.h"

START_TEST(s21_strstr_base_midstr) {
  char *haystack = "Hello, world!";
  char *needle = "wor";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_base_startstr) {
  char *haystack = "Hello, world!";
  char *needle = "Hel";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_base_endstr) {
  char *haystack = "Hello, world!";
  char *needle = "ld!";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_base_subone) {
  char *haystack = "Hello, world!";
  char *needle = "l";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_boundary_emptysubstr) {
  char *haystack = "Hello, world!";
  char *needle = "";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_boundary_emptystr) {
  char *haystack = "";
  char *needle = "Hel";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_boundary_emptyall) {
  char *haystack = "";
  char *needle = "";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_boundary_shortstr) {
  char *haystack = "Hel";
  char *needle = "Hello, world!";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_boundary_partial_match_endstr) {
  char *haystack = "12345";
  char *needle = "3456";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_boundary_special_char_lnbrks) {
  char *haystack = "Hello\nworld";
  char *needle = "\nworld";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_difficult_partial_match) {
  char *haystack = "Hello, w ew ewo wo world!";
  char *needle = "wor";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_difficult_duplicate_characters) {
  char *haystack = "aaaaaaaaaaaa";
  char *needle = "aaa";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_difficult_no_matches) {
  char *haystack = "qwerty";
  char *needle = "asd";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_difficult_search_specifications_space) {
  char *haystack = "  121";
  char *needle = " ";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_difficult_search_specifications_tab) {
  char *haystack = " \t121";
  char *needle = " \t";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_difficult_search_specifications_numbers) {
  char *haystack = "      121";
  char *needle = "12";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_uniqueness_register) {
  char *haystack = "hello, world!";
  char *needle = "World";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

START_TEST(s21_strstr_uniqueness_multiple_occurrences) {
  char *haystack = "hello, hello, world!";
  char *needle = "hello";

  char *get = s21_strstr(haystack, needle);
  char *expt = strstr(haystack, needle);

  ck_assert_ptr_eq(get, expt);
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strstr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strstr_base_midstr);
  tcase_add_test(tc_core, s21_strstr_base_startstr);
  tcase_add_test(tc_core, s21_strstr_base_endstr);
  tcase_add_test(tc_core, s21_strstr_base_subone);

  tcase_add_test(tc_core, s21_strstr_boundary_emptysubstr);
  tcase_add_test(tc_core, s21_strstr_boundary_emptystr);
  tcase_add_test(tc_core, s21_strstr_boundary_emptyall);
  tcase_add_test(tc_core, s21_strstr_boundary_shortstr);
  tcase_add_test(tc_core, s21_strstr_boundary_partial_match_endstr);
  tcase_add_test(tc_core, s21_strstr_boundary_special_char_lnbrks);

  tcase_add_test(tc_core, s21_strstr_difficult_partial_match);
  tcase_add_test(tc_core, s21_strstr_difficult_duplicate_characters);
  tcase_add_test(tc_core, s21_strstr_difficult_no_matches);
  tcase_add_test(tc_core, s21_strstr_difficult_search_specifications_space);
  tcase_add_test(tc_core, s21_strstr_difficult_search_specifications_tab);
  tcase_add_test(tc_core, s21_strstr_difficult_search_specifications_numbers);

  tcase_add_test(tc_core, s21_strstr_uniqueness_register);
  tcase_add_test(tc_core, s21_strstr_uniqueness_multiple_occurrences);

  suite_add_tcase(s, tc_core);

  return s;
}
