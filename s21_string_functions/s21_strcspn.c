#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  short int match = 0;
  for (int i = 0; str2[i]; i++) {
    for (int j = 0; str1[j]; j++) {
      if (str2[i] == str1[j] &&
          (result > (long unsigned int)j || (!result && !match))) {
        result = j;
        match = 1;
      }
    }
  }
  return !match ? s21_strlen(str1) : result;
}