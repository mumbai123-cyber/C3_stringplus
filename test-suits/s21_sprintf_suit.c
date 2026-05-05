#include "s21_sprintf_suit.h"

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

#define TEST_SPRINTF(format, ...)                                            \
  do {                                                                       \
    char s21_buffer[1024] = {0};                                             \
    char std_buffer[1024] = {0};                                             \
    int s21_result = s21_sprintf(s21_buffer, (char *)format, ##__VA_ARGS__); \
    int std_result = sprintf(std_buffer, format, ##__VA_ARGS__);             \
    ck_assert_int_eq(s21_result, std_result);                                \
    ck_assert_str_eq(s21_buffer, std_buffer);                                \
  } while (0)

// тест без аргументов (только %%)
#define TEST_SPRINTF_NO_ARGS(format)                          \
  do {                                                        \
    char s21_buffer[1024] = {0};                              \
    char std_buffer[1024] = {0};                              \
    int s21_result = s21_sprintf(s21_buffer, (char *)format); \
    int std_result = sprintf(std_buffer, format);             \
    ck_assert_int_eq(s21_result, std_result);                 \
    ck_assert_str_eq(s21_buffer, std_buffer);                 \
  } while (0)

START_TEST(test_sprintf_c_basic) {
  TEST_SPRINTF("%c", 'A');
  TEST_SPRINTF("%c", 'z');
  TEST_SPRINTF("%c", '0');
  TEST_SPRINTF("%c", '\n');
  TEST_SPRINTF("%c", '\t');
}
END_TEST

START_TEST(test_sprintf_c_width) {
  TEST_SPRINTF("%5c", 'X');
  TEST_SPRINTF("%-5c", 'X');
  TEST_SPRINTF("%3c", '!');
  TEST_SPRINTF("%-3c", '!');
  TEST_SPRINTF("%10c", '@');
}
END_TEST

START_TEST(test_sprintf_c_flags) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
  TEST_SPRINTF("%+c", 'A');
  TEST_SPRINTF("% c", 'A');
  TEST_SPRINTF("%-+5c", 'B');
  TEST_SPRINTF("%- 5c", 'B');
#pragma GCC diagnostic pop
}
END_TEST

START_TEST(test_sprintf_c_length) {
  TEST_SPRINTF("%lc", (wint_t)L'A');

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
  TEST_SPRINTF("%hc", (char)'A');
#pragma GCC diagnostic pop
}
END_TEST

START_TEST(test_sprintf_s_basic) {
  TEST_SPRINTF("%s", "Hello");
  TEST_SPRINTF("%s", "");
  TEST_SPRINTF("%s", "Hello World!");
  TEST_SPRINTF("%s", "Test with spaces");
}
END_TEST

START_TEST(test_sprintf_s_width) {
  TEST_SPRINTF("%10s", "Hello");
  TEST_SPRINTF("%-10s", "Hello");
  TEST_SPRINTF("%20s", "Short");
  TEST_SPRINTF("%-20s", "Short");
  TEST_SPRINTF("%5s", "LongerString");
  TEST_SPRINTF("%-5s", "LongerString");
}
END_TEST

START_TEST(test_sprintf_s_precision) {
  TEST_SPRINTF("%.5s", "Hello World");
  TEST_SPRINTF("%.3s", "Hello");
  TEST_SPRINTF("%.0s", "Hello");
  TEST_SPRINTF("%.10s", "Hi");
  TEST_SPRINTF("%.1s", "Hello");
}
END_TEST

START_TEST(test_sprintf_s_width_precision) {
  TEST_SPRINTF("%10.5s", "Hello World");
  TEST_SPRINTF("%-10.5s", "Hello World");
  TEST_SPRINTF("%8.3s", "Hello");
  TEST_SPRINTF("%-8.3s", "Hello");
  TEST_SPRINTF("%5.10s", "Hi");
  TEST_SPRINTF("%-5.10s", "Hi");
}
END_TEST
START_TEST(
    test_sprintf_s_flags) {  // флаги + и пробел обычно игнорируются для %s
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"

  TEST_SPRINTF("%+s", "Hello");
  TEST_SPRINTF("% s", "Hello");
  TEST_SPRINTF("%-+10s", "Hello");
  TEST_SPRINTF("%- 10s", "Hello");
#pragma GCC diagnostic pop
}
END_TEST

START_TEST(
    test_sprintf_s_length) {  // флаги + и пробел обычно игнорируются для %s
  TEST_SPRINTF("%s", "Hello");

#ifndef __MINGW32__
  TEST_SPRINTF("%ls", L"Hello");
  TEST_SPRINTF("%.5ls", L"Hello World");
  TEST_SPRINTF("%10ls", L"Hi");
#endif
}
END_TEST

START_TEST(test_sprintf_s_null) {
  char *null_ptr = NULL;
  TEST_SPRINTF("%s", null_ptr);
  TEST_SPRINTF("%.5s", null_ptr);
  TEST_SPRINTF("%10s", null_ptr);
}
END_TEST

START_TEST(test_sprintf_d_basic) {
  TEST_SPRINTF("%d", 0);
  TEST_SPRINTF("%d", 123);
  TEST_SPRINTF("%d", -123);
  TEST_SPRINTF("%d", INT_MAX);
  TEST_SPRINTF("%d", INT_MIN);
  TEST_SPRINTF("%i", 456);
  TEST_SPRINTF("%i", -789);
}
END_TEST

START_TEST(test_sprintf_d_width) {
  TEST_SPRINTF("%5d", 123);
  TEST_SPRINTF("%5d", -123);
  TEST_SPRINTF("%-5d", 123);
  TEST_SPRINTF("%-5d", -123);
  TEST_SPRINTF("%10d", 42);
  TEST_SPRINTF("%3d", 1000);
  TEST_SPRINTF("%-3d", 1000);
}
END_TEST

START_TEST(test_sprintf_d_precision) {
  TEST_SPRINTF("%.5d", 123);
  TEST_SPRINTF("%.5d", -123);
  TEST_SPRINTF("%.3d", 42);
  TEST_SPRINTF("%.0d", 0);
  TEST_SPRINTF("%.1d", 0);
  TEST_SPRINTF("%.5d", 0);
  TEST_SPRINTF("%.5d", -42);
}
END_TEST

START_TEST(test_sprintf_d_width_precision) {
  TEST_SPRINTF("%8.5d", 123);
  TEST_SPRINTF("%8.5d", -123);
  TEST_SPRINTF("%-8.5d", 123);
  TEST_SPRINTF("%-8.5d", -123);
  TEST_SPRINTF("%10.3d", 42);
  TEST_SPRINTF("%5.10d", 100);
  TEST_SPRINTF("%-5.10d", -100);
}
END_TEST

START_TEST(test_sprintf_d_flags) {
  TEST_SPRINTF("%+d", 123);
  TEST_SPRINTF("%+d", -123);
  TEST_SPRINTF("% d", 123);
  TEST_SPRINTF("% d", -123);
  TEST_SPRINTF("%+5d", 123);
  TEST_SPRINTF("%+5d", -123);
  TEST_SPRINTF("% 5d", 123);
  TEST_SPRINTF("% 5d", -123);
  TEST_SPRINTF("%-+8d", 456);
  TEST_SPRINTF("%- 8d", 456);
}
END_TEST

START_TEST(test_sprintf_d_length) {
  TEST_SPRINTF("%hd", (short)123);
  TEST_SPRINTF("%hd", (short)-123);
  TEST_SPRINTF("%ld", 123456L);
  TEST_SPRINTF("%ld", -123456L);
  TEST_SPRINTF("%lld", 123456789LL);
  TEST_SPRINTF("%lld", -123456789LL);
  TEST_SPRINTF("%hi", (short)456);
}
END_TEST

START_TEST(test_sprintf_d_zero_flag) {
  TEST_SPRINTF("%05d", 123);
  TEST_SPRINTF("%05d", -123);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
  TEST_SPRINTF("%08.5d", 123);
  TEST_SPRINTF("%0-5d", 123);
#pragma GCC diagnostic pop
}
END_TEST

START_TEST(test_sprintf_u_basic) {
  TEST_SPRINTF("%u", 0U);
  TEST_SPRINTF("%u", 123U);
  TEST_SPRINTF("%u", UINT_MAX);
}
END_TEST

START_TEST(test_sprintf_u_width) {
  TEST_SPRINTF("%5u", 123U);
  TEST_SPRINTF("%-5u", 123U);
  TEST_SPRINTF("%10u", 42U);
  TEST_SPRINTF("%3u", 1000U);
}
END_TEST

START_TEST(test_sprintf_u_precision) {
  TEST_SPRINTF("%.5u", 123U);
  TEST_SPRINTF("%.3u", 42U);
  TEST_SPRINTF("%.0u", 0U);
  TEST_SPRINTF("%.1u", 0U);
  TEST_SPRINTF("%.5u", 0U);
}
END_TEST

START_TEST(test_sprintf_u_width_precision) {
  TEST_SPRINTF("%8.5u", 123U);
  TEST_SPRINTF("%-8.5u", 123U);
  TEST_SPRINTF("%10.3u", 42U);
  TEST_SPRINTF("%5.10u", 100U);
}
END_TEST

START_TEST(test_sprintf_u_length) {
  TEST_SPRINTF("%hu", (unsigned short)123U);
  TEST_SPRINTF("%lu", 123456UL);
  TEST_SPRINTF("%llu", 123456789ULL);
}
END_TEST

START_TEST(test_sprintf_f_basic) {
  TEST_SPRINTF("%f", 0.0);
  TEST_SPRINTF("%f", 123.456);
  TEST_SPRINTF("%f", -123.456);
  TEST_SPRINTF("%f", 1.0 / 3.0);
  TEST_SPRINTF("%f", 1e10);
}
END_TEST

START_TEST(test_sprintf_f_precision) {
  TEST_SPRINTF("%.0f", 123.456);
  TEST_SPRINTF("%.1f", 123.456);
  TEST_SPRINTF("%.2f", 123.456);
  TEST_SPRINTF("%.3f", 123.456);
  TEST_SPRINTF("%.10f", 123.456);
  TEST_SPRINTF("%.0f", 0.0);
  TEST_SPRINTF("%.5f", 0.0);
}
END_TEST

START_TEST(test_sprintf_f_width) {
  TEST_SPRINTF("%10f", 123.456);
  TEST_SPRINTF("%-10f", 123.456);
  TEST_SPRINTF("%20f", -123.456);
  TEST_SPRINTF("%-20f", -123.456);
  TEST_SPRINTF("%5f", 123.456);
}
END_TEST

START_TEST(test_sprintf_f_width_precision) {
  TEST_SPRINTF("%10.2f", 123.456);
  TEST_SPRINTF("%-10.2f", 123.456);
  TEST_SPRINTF("%15.5f", -123.456);
  TEST_SPRINTF("%-15.5f", -123.456);
  TEST_SPRINTF("%8.0f", 123.456);
  TEST_SPRINTF("%8.0f", -123.456);
}
END_TEST

START_TEST(test_sprintf_f_flags) {
  TEST_SPRINTF("%+f", 123.456);
  TEST_SPRINTF("%+f", -123.456);
  TEST_SPRINTF("% f", 123.456);
  TEST_SPRINTF("% f", -123.456);
  TEST_SPRINTF("%+10.2f", 123.456);
  TEST_SPRINTF("%+10.2f", -123.456);
  TEST_SPRINTF("% 10.2f", 123.456);
  TEST_SPRINTF("% 10.2f", -123.456);
  TEST_SPRINTF("%-+15.5f", 123.456);
  TEST_SPRINTF("%- 15.5f", 123.456);
}
END_TEST

START_TEST(test_sprintf_f_zero_flag) {
  TEST_SPRINTF("%010f", 123.456);
  TEST_SPRINTF("%010f", -123.456);
  TEST_SPRINTF("%010.2f", 123.456);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
  TEST_SPRINTF("%0-10f", 123.456);
#pragma GCC diagnostic pop
}
END_TEST

START_TEST(test_sprintf_f_rounding) {
  TEST_SPRINTF("%.0f", 1.5);
  TEST_SPRINTF("%.0f", 2.5);
  TEST_SPRINTF("%.1f", 1.55);
  TEST_SPRINTF("%.2f", 1.555);
  TEST_SPRINTF("%.2f", 1.554);
  TEST_SPRINTF("%.5f", 1.99999);
}
END_TEST

START_TEST(test_sprintf_percent) {
  TEST_SPRINTF_NO_ARGS("%%");
  TEST_SPRINTF("%% %d %%", 123);
  TEST_SPRINTF_NO_ARGS("%%s");
  TEST_SPRINTF_NO_ARGS("%%d");
}
END_TEST

START_TEST(test_sprintf_multiple_specifiers) {
  TEST_SPRINTF("%d %s %c %.2f", 123, "hello", 'A', 45.67);
  TEST_SPRINTF("%+8d %-10.3s %05d", 456, "world", 789);
  TEST_SPRINTF("%ld %lld %f", 123L, 456LL, 78.9);
  TEST_SPRINTF("%.5s %+10.2f %u", "test", -3.14, 42U);
}
END_TEST

START_TEST(test_sprintf_mixed_text) {
  TEST_SPRINTF("Result: %d", 123);
  TEST_SPRINTF("Value = %f, String = '%s'", 45.67, "test");
  TEST_SPRINTF("Numbers: %+5d and %-5d", 123, -123);
  TEST_SPRINTF("Precision: %.3f and %.5s", 1.23456, "Hello World");
}
END_TEST

START_TEST(test_sprintf_edge_cases) {
  TEST_SPRINTF("%d %d %d", INT_MAX, 0, INT_MIN);
  TEST_SPRINTF("%f %f %f", 1e-10, 1e10, -1e-10);
  TEST_SPRINTF("%.0f %.0f", 0.5, 1.5);
  TEST_SPRINTF("%s %s", "Hello", "");
  TEST_SPRINTF("%c %c %c", ' ', '\n', '\t');
}
END_TEST

START_TEST(test_invalid_specifiers) {
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
#endif

  char orig[100] = {0};
  char our[100] = {0};

  sprintf(orig, "%k %d", 123);
  s21_sprintf(our, "%k %d", 123);
  ck_assert_str_eq(orig, our);

  sprintf(orig, "%y %s", "test");
  s21_sprintf(our, "%y %s", "test");
  ck_assert_str_eq(orig, our);

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf");
  tc_core = tcase_create("Core");

  // спецификатора c
  tcase_add_test(tc_core, test_sprintf_c_basic);
  tcase_add_test(tc_core, test_sprintf_c_width);
  tcase_add_test(tc_core, test_sprintf_c_flags);
  tcase_add_test(tc_core, test_sprintf_c_length);
  // спецификатора s
  tcase_add_test(tc_core, test_sprintf_s_basic);
  tcase_add_test(tc_core, test_sprintf_s_width);
  tcase_add_test(tc_core, test_sprintf_s_precision);
  tcase_add_test(tc_core, test_sprintf_s_width_precision);
  tcase_add_test(tc_core, test_sprintf_s_flags);
  tcase_add_test(tc_core, test_sprintf_s_length);
  tcase_add_test(tc_core, test_sprintf_s_null);
  // спецификатора d/i
  tcase_add_test(tc_core, test_sprintf_d_basic);
  tcase_add_test(tc_core, test_sprintf_d_width);
  tcase_add_test(tc_core, test_sprintf_d_precision);
  tcase_add_test(tc_core, test_sprintf_d_width_precision);
  tcase_add_test(tc_core, test_sprintf_d_flags);
  tcase_add_test(tc_core, test_sprintf_d_length);
  tcase_add_test(tc_core, test_sprintf_d_zero_flag);
  // спецификатора u
  tcase_add_test(tc_core, test_sprintf_u_basic);
  tcase_add_test(tc_core, test_sprintf_u_width);
  tcase_add_test(tc_core, test_sprintf_u_precision);
  tcase_add_test(tc_core, test_sprintf_u_width_precision);
  tcase_add_test(tc_core, test_sprintf_u_length);
  // спецификатора f
  tcase_add_test(tc_core, test_sprintf_f_basic);
  tcase_add_test(tc_core, test_sprintf_f_precision);
  tcase_add_test(tc_core, test_sprintf_f_width);
  tcase_add_test(tc_core, test_sprintf_f_width_precision);
  tcase_add_test(tc_core, test_sprintf_f_flags);
  tcase_add_test(tc_core, test_sprintf_f_zero_flag);
  tcase_add_test(tc_core, test_sprintf_f_rounding);
  // для %%
  tcase_add_test(tc_core, test_sprintf_percent);
  // для комбинаций
  tcase_add_test(tc_core, test_sprintf_multiple_specifiers);
  tcase_add_test(tc_core, test_sprintf_mixed_text);
  tcase_add_test(tc_core, test_sprintf_edge_cases);
  // тест не правилного спец. с подавлением предупреждения только для этого
  // блока
  tcase_add_test(tc_core, test_invalid_specifiers);

  suite_add_tcase(s, tc_core);

  return s;
}