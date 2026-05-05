#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <check.h>

static inline int s21_sign(int x) {
    return (x > 0) - (x < 0);
}

#define ck_assert_sign_eq(val1, val2) \
  ck_assert_int_eq(s21_sign(val1), s21_sign(val2))

#endif
