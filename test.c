#define _POSIX_C_SOURCE 200809L
#include <check.h>
#include <string.h>

#include "./test-suits/s21_insert_suit.h"
#include "./test-suits/s21_memchr_suit.h"
#include "./test-suits/s21_memcmp_suit.h"
#include "./test-suits/s21_memcpy_suit.h"
#include "./test-suits/s21_memset_suit.h"
#include "./test-suits/s21_sprintf_suit.h"
#include "./test-suits/s21_strchr_suit.h"
#include "./test-suits/s21_strcspn_suit.h"
#include "./test-suits/s21_strerror_suit.h"
#include "./test-suits/s21_strlen_suit.h"
#include "./test-suits/s21_strncat_suit.h"
#include "./test-suits/s21_strncmp_suit.h"
#include "./test-suits/s21_strncpy_suit.h"
#include "./test-suits/s21_strpbrk_suit.h"
#include "./test-suits/s21_strrchr_suit.h"
#include "./test-suits/s21_strstr_suit.h"
#include "./test-suits/s21_strtok_suit.h"
#include "./test-suits/s21_to_lower_suit.h"
#include "./test-suits/s21_to_upper_suit.h"
#include "./test-suits/s21_trim_suit.h"
#include "s21_sprintf_ext.h"
#include "s21_string.h"

int main(void) {
  int number_failed;
  SRunner *sr;

  Suite *_strlen_suite = s21_strlen_suite();
  Suite *_memset_suite = s21_memset_suite();
  Suite *_strncpy_suite = s21_strncpy_suite();
  Suite *_strncmp_suite = s21_strncmp_suite();
  Suite *_strchr_suite = s21_strchr_suite();
  Suite *_memchr_suite = s21_memchr_suite();
  Suite *_memcmp_suite = s21_memcmp_suite();
  Suite *_memcpy_suite = s21_memcpy_suite();
  Suite *_strcspn_suite = s21_strcspn_suite();
  Suite *_strpbrk_suite = s21_strpbrk_suite();
  Suite *_strstr_suite = s21_strstr_suite();
  Suite *_strtok_suite = s21_strtok_suite();
  Suite *_trim_suite = s21_trim_suite();
  Suite *_insert_suite = s21_insert_suite();
  Suite *_strrchr_suite = s21_strrchr_suite();
  Suite *_to_lower_suite = s21_to_lower_suite();
  Suite *_to_upper_suite = s21_to_upper_suite();
  Suite *_strerror_suite = s21_strerror_suite();
  Suite *_strncat_suite = s21_strncat_suite();
  Suite *_sprintf_suite = s21_sprintf_suite();

  sr = srunner_create(_strlen_suite);
  srunner_add_suite(sr, _memset_suite);
  srunner_add_suite(sr, _strncpy_suite);
  srunner_add_suite(sr, _strncmp_suite);
  srunner_add_suite(sr, _strchr_suite);
  srunner_add_suite(sr, _memchr_suite);
  srunner_add_suite(sr, _memcmp_suite);
  srunner_add_suite(sr, _memcpy_suite);
  srunner_add_suite(sr, _strcspn_suite);
  srunner_add_suite(sr, _strpbrk_suite);
  srunner_add_suite(sr, _strstr_suite);
  srunner_add_suite(sr, _strtok_suite);
  srunner_add_suite(sr, _trim_suite);
  srunner_add_suite(sr, _insert_suite);
  srunner_add_suite(sr, _strrchr_suite);
  srunner_add_suite(sr, _to_lower_suite);
  srunner_add_suite(sr, _to_upper_suite);
  srunner_add_suite(sr, _strerror_suite);
  srunner_add_suite(sr, _strncat_suite);
  srunner_add_suite(sr, _sprintf_suite);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
