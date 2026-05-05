#include "s21_strerror_suit.h"

#include <errno.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(s21_strerror_standard_range) {
  int code = _i;
  ck_assert_str_eq(s21_strerror(code), strerror(code));
}
END_TEST

START_TEST(s21_strerror_negative_range) {
  int code = -(_i + 1);
  ck_assert_str_eq(s21_strerror(code), strerror(code));
}
END_TEST

START_TEST(s21_strerror_errno_codes) {
  int errno_codes[] = {EPERM,   ENOENT, ESRCH,  EINTR,  EIO,     ENXIO,  E2BIG,
                       ENOEXEC, EBADF,  ECHILD, EAGAIN, ENOMEM,  EACCES, EFAULT,
                       EBUSY,   EEXIST, EXDEV,  ENODEV, ENOTDIR, EISDIR, EINVAL,
                       ENFILE,  EMFILE, ENOTTY, EFBIG,  ENOSPC,  ESPIPE, EROFS,
                       EMLINK,  EPIPE,  EDOM,   ERANGE};

  int num_codes = sizeof(errno_codes) / sizeof(errno_codes[0]);

  for (int i = 0; i < num_codes; i++) {
    ck_assert_str_eq(s21_strerror(errno_codes[i]), strerror(errno_codes[i]));
  }
}
END_TEST

START_TEST(s21_strerror_boundary) {
  int boundary_codes[] = {0,    1,    33, 34, 133, 134,  135,
                          1000, 9999, -0, -1, -33, -134, -1000};

  ck_assert_str_eq(s21_strerror(boundary_codes[_i]),
                   strerror(boundary_codes[_i]));
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strerror");
  tc_core = tcase_create("Core");

  tcase_add_loop_test(tc_core, s21_strerror_standard_range, 0, 135);
  tcase_add_loop_test(tc_core, s21_strerror_negative_range, 0, 135);
  tcase_add_test(tc_core, s21_strerror_errno_codes);
  tcase_add_loop_test(tc_core, s21_strerror_boundary, 0, 14);

  suite_add_tcase(s, tc_core);

  return s;
}
