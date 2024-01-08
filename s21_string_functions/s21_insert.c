#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;
  if (src != S21_NULL && start_index < s21_strlen(src) && str != S21_NULL) {
    result = calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));

    if (result) {
      s21_size_t i = 0;
      for (; i < start_index; i++) result[i] = src[i];

      for (s21_size_t j = 0; str[j]; i++, j++) {
        result[i] = str[j];
      }

      for (s21_size_t j = start_index; src[j]; i++, j++) {
        result[i] = src[j];
      }
    }
  }
  return result;
}
