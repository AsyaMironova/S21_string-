#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *(char *)dest = *(char *)src;
    dest = (char *)dest + 1;
    src = (char *)src + 1;
    if (i + 1 == n) {
      dest = (char *)dest - (i + 1);
    }
  }
  return dest;
}