#include "s21_memcpy_suit.h"

#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_memcpy_basic) {
  char src[] = "Hello, World!";
  char dest1[20] = {0};
  char dest2[20] = {0};
  size_t n = strlen(src) + 1;

  memcpy(dest1, src, n);
  s21_memcpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(test_memcpy_partial) {
  char src[] = "Hello, World!";
  char dest1[20] = {0};
  char dest2[20] = {0};
  size_t n = 5;

  memcpy(dest1, src, n);
  s21_memcpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(test_memcpy_empty) {
  char src[] = "Hello";
  char dest1[20] = {0};
  char dest2[20] = {0};
  size_t n = 0;

  memcpy(dest1, src, n);
  s21_memcpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 20);
}
END_TEST

START_TEST(test_memcpy_binary) {
  unsigned char src[] = {0x01, 0x02, 0x03, 0x04, 0x05};
  unsigned char dest1[5] = {0};
  unsigned char dest2[5] = {0};
  size_t n = 5;

  memcpy(dest1, src, n);
  s21_memcpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(test_memcpy_overlap) {
  char buffer1[20] = "Test string";
  char buffer2[20] = "Test string";
  char dest1[20] = {0};
  char dest2[20] = {0};

  memcpy(dest1, buffer1, 5);
  s21_memcpy(dest2, buffer2, 5);

  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_memcpy_return_value) {
  char src[] = "Hello";
  char dest1[10] = {0};
  char dest2[10] = {0};

  char *ret1 = (char *)memcpy(dest1, src, 5);
  char *ret2 = (char *)s21_memcpy(dest2, src, 5);

  ck_assert_ptr_eq(ret1, dest1);
  ck_assert_ptr_eq(ret2, dest2);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_memcpy_large_data) {
  size_t size = 1024;
  char *src = (char *)malloc(size);
  char *dest1 = (char *)malloc(size);
  char *dest2 = (char *)malloc(size);

  for (size_t i = 0; i < size; i++) {
    src[i] = (char)(i % 256);
  }

  memcpy(dest1, src, size);
  s21_memcpy(dest2, src, size);

  ck_assert_mem_eq(dest1, dest2, size);

  free(src);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_memcpy_array_of_structs) {
  struct test_struct {
    int a;
    char b;
    double c;
  };

  struct test_struct src[3] = {0};
  src[0].a = 1;
  src[0].b = 'x';
  src[0].c = 3.14;
  src[1].a = 2;
  src[1].b = 'y';
  src[1].c = 2.71;
  src[2].a = 3;
  src[2].b = 'z';
  src[2].c = 1.41;

  struct test_struct dest1[3] = {0};
  struct test_struct dest2[3] = {0};
  size_t n = sizeof(src);

  memcpy(dest1, src, n);
  s21_memcpy(dest2, src, n);

  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(dest1[i].a, dest2[i].a);
    ck_assert_int_eq(dest1[i].b, dest2[i].b);
    ck_assert_double_eq(dest1[i].c, dest2[i].c);
  }
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *suite = suite_create("s21_memcpy");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memcpy_basic);
  tcase_add_test(tc_core, test_memcpy_partial);
  tcase_add_test(tc_core, test_memcpy_empty);
  tcase_add_test(tc_core, test_memcpy_binary);
  tcase_add_test(tc_core, test_memcpy_overlap);
  tcase_add_test(tc_core, test_memcpy_return_value);
  tcase_add_test(tc_core, test_memcpy_large_data);
  tcase_add_test(tc_core, test_memcpy_array_of_structs);

  suite_add_tcase(suite, tc_core);

  return suite;
}
