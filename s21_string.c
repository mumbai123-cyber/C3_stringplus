#define _POSIX_C_SOURCE 200809L
#include "s21_string.h"

#include <stdlib.h>

#if defined(__linux__)
#include "errors_linux.h"
#elif defined(__APPLE__) || defined(__MACH__)
#include "errors_macos.h"
#elif defined(_WIN32) || defined(__WIN32__) || defined(__MINGW32__)
#include "errors_windows.h"
#else
#error "Unsupported operating system"
#endif

#include "s21_sprintf_ext.h"

s21_size s21_strlen(const char *str) {
  s21_size len = 0;

  while (str[len] != '\0') {
    len++;
  }

  return len;
}

void *s21_memset(void *str, int c, s21_size n) {
  char *s = str;

  for (s21_size i = 0; i < n; ++i) {
    s[i] = (unsigned char)c;
  }

  return str;
}

char *s21_strncpy(char *str1, const char *str2, s21_size n) {
  char *dst = str1;
  s21_size i = 0;
  while (n > i) {
    if (*str2) {
      *dst++ = *str2++;
      i++;
    } else if (!*str2) {
      *dst++ = '\0';
      i++;
    }
  }
  return str1;
}

int s21_strncmp(const char *str1, const char *str2, s21_size n) {
  int sub = 0;
  s21_size i = 0;
  if (n) sub = (int)(*str1 - *str2);
  while (n > i++ && !sub) {
    sub = (int)(*str1 - *str2);
    ++str1;
    ++str2;
  }
  return sub;
}

char *s21_strchr(const char *str, int c) {
  unsigned char target = (unsigned char)c;
  int found = 0;

  while (*str != '\0' && !found) {
    if ((unsigned char)*str == target) {
      found = 1;
    } else {
      str++;
    }
  }

  return (target == 0 || found) ? (char *)str : S21_NULL;
}

void *s21_memchr(const void *str, int c, s21_size n) {
  const unsigned char *ptr = (const unsigned char *)str;
  unsigned char uc = (unsigned char)c;
  for (s21_size i = 0; i < n; i++) {
    if (ptr[i] == uc) {
      return (void *)(ptr + i);
    }
  }
  return S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size n) {
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;

  for (s21_size i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      return (int)(s1[i] - s2[i]);
    }
  }
  return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  for (s21_size i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}

s21_size s21_strcspn(const char *str1, const char *str2) {
  s21_size c_spn = 0;
  for (; *str1; str1++) {
    if (s21_strchr(str2, *str1)) break;
    c_spn++;
  }
  return c_spn;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size index = s21_strcspn(str1, str2);
  return str1[index] ? (char *)str1 + index : S21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  static char *ptr = S21_NULL;
  static char *end = S21_NULL;
  if (str) {
    ptr = str;
    end = &str[s21_strlen(str)];
  } else if (ptr < end) {
    ptr += s21_strlen(ptr) + 1;
  }
  while (ptr < end && s21_strchr(delim, *ptr)) {
    ++ptr;
  }
  for (s21_size i = 0; ptr < end && *ptr;) {
    if (!s21_strchr(delim, ptr[i])) {
      i++;
    } else {
      ptr[i] = '\0';
      break;
    }
  }
  return (ptr && ptr < end) ? ptr : S21_NULL;
}

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  s21_size length = s21_strlen(str);

  char *result = (char *)calloc(length + 1, sizeof(char));
  if (result == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size i = 0; i < length; i++) {
    char c = str[i];
    result[i] = (c >= 'A' && c <= 'Z') ? (c + 32) : c;
  }

  return result;
}

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  s21_size length = s21_strlen(str);

  char *result = (char *)calloc(length + 1, sizeof(char));
  if (result == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size i = 0; i < length; i++) {
    char c = str[i];

    if (c >= 'a' && c <= 'z') {
      result[i] = c - 32;
    } else {
      result[i] = c;
    }
  }

  return result;
}

char *s21_strncat(char *dest, const char *src, s21_size n) {
  char *dest_start = dest;

  while (*dest != '\0') {
    dest++;
  }

  s21_size i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  dest[i] = '\0';

  return dest_start;
}

char *s21_strerror(int errnum) {
#if defined(__linux__)
  static const char **error_messages = linux_error_messages;
  int max_errors = LINUX_ERRORS_COUNT;
  const char *unknown_prefix = "Unknown error %d";
#elif defined(__APPLE__) || defined(__MACH__)
  static const char **error_messages = macos_error_messages;
  int max_errors = MACOS_ERRORS_COUNT;
  const char *unknown_prefix = "Unknown error: %d";
#elif defined(_WIN32) || defined(__WIN32__) || defined(__MINGW32__)
  static const char **error_messages = windows_error_messages;
  int max_errors = WINDOWS_ERRORS_COUNT;
  const char *unknown_prefix = "Unknown error";
#else
  const char *unknown_prefix = "Unknown error %d";
#endif

  if (errnum >= 0 && errnum < max_errors) {
    return (char *)error_messages[errnum];
  }

#if defined(_WIN32) || defined(__WIN32__) || defined(__MINGW32__)
  return (char *)unknown_prefix;
#endif

  static char unknown_error[100];
  s21_sprintf(unknown_error, (char *)unknown_prefix, errnum);

  return unknown_error;
}

char *s21_strrchr(const char *str, int c) {
  unsigned char target = (unsigned char)c;
  const char *last = S21_NULL;

  while (*str != '\0') {
    if ((unsigned char)*str == target) {
      last = str;
    }
    str++;
  }

  return (target == 0) ? (char *)str : (last ? (char *)last : S21_NULL);
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size hstck_len = s21_strlen(haystack);
  s21_size ndl_len = s21_strlen(needle);
  const char *hstck_end = haystack + hstck_len - ndl_len;

  if (ndl_len == 0) {
    return (char *)haystack;
  } else if (ndl_len > hstck_len) {
    return S21_NULL;
  }

  while (haystack <= hstck_end) {
    if (*haystack == *needle) {
      if (s21_strncmp(haystack, needle, ndl_len) == 0) {
        return (char *)haystack;
      }
    }

    haystack++;
  }

  return S21_NULL;
}

void *s21_insert(const char *src, const char *str, s21_size start_index) {
  if (str == S21_NULL || src == S21_NULL || start_index > s21_strlen(src)) {
    return S21_NULL;
  }

  s21_size src_length = s21_strlen(src);
  s21_size str_length = s21_strlen(str);

  char *res = (char *)calloc(src_length + str_length + 1, sizeof(char));

  if (res != S21_NULL) {
    s21_memcpy(res, src, start_index);
    s21_memcpy(res + start_index, str, str_length);
    s21_memcpy(res + start_index + str_length, src + start_index,
               src_length - start_index);
  }

  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL) {
    return S21_NULL;
  }

  const char *chars = trim_chars;
  if (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0) {
    chars = " \t\n\r\f\v";
  }

  s21_size len = s21_strlen(src);
  s21_size start = 0;
  s21_size end = len;

  while (start < len && s21_strchr(chars, src[start])) ++start;

  char *res = S21_NULL;

  if (start == len) {
    res = (char *)calloc(1, sizeof(char));
    if (res) res[0] = '\0';
  } else {
    while (end > start && s21_strchr(chars, src[end - 1])) --end;

    s21_size result_len = end - start;
    res = (char *)calloc(result_len + 1, sizeof(char));

    if (res) {
      s21_memcpy(res, src + start, result_len);
    }
  }

  return res;
}

int s21_sprintf(char *str, char *format, ...) {
  va_list arg;
  va_start(arg, format);
  char *start_str = str;
  while (*format) {
    if (*format != '%') {
      *str = *format;
      str++;
      format++;
    } else if (*format == '%' && *(format + 1) == '%') {
      *str = '%';
      str++;
      format += 2;
    } else {
      specif spec = {0};
      spec.precision = -1;
      spec.width_field = -1;
      s21_size len_spec;
      if ((len_spec = parse_specif(format, &spec))) {
        str = write_specif(str, &spec, &arg);
        format += len_spec;
      }
    }
  }
  *str = '\0';
  va_end(arg);
  return (int)(str - start_str);
}
