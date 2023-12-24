#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *pointer = 0;
  for (s21_size_t i = 0; i < s21_strlen(str) - 1; i++) {
    if (str[i] == c) pointer = (char *)str + i;
  }
  return pointer;
}
