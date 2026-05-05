#ifndef S21_STRERROR_SUIT_H
#define S21_STRERROR_SUIT_H

#include <check.h>

Suite *s21_strerror_suite(void);

#define MIN_CODE -200
#define MAX_CODE 200

#if defined(__linux__)
#define OS_NAME "Linux"
#elif defined(__APPLE__) && defined(__MACH__)
#define OS_NAME "macOS"
#elif defined(_WIN32) || defined(__WIN32__) || defined(__MINGW32__)
#define OS_NAME "Windows"
#else
#define OS_NAME "Unknown"
#endif

#endif
