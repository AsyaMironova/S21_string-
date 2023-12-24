#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *s1 = str1;
  const unsigned char *s2 = str2;
  int res = 0;
  int find_res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (find_res != 1) {
      if (s1[i] != s2[i]) {
        res = (int)s1[i] - (int)s2[i];
        find_res = 1;
      }
    }
  }
  return res;
}