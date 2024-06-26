#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = str;
  for (s21_size_t i = 0; i < n; i++) {
    s[i] = (unsigned char)c;
  }
  return n > s21_strlen(str) ? S21_NULL : str;
}
