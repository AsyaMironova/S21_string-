#include "../s21_string.h"

char* s21_strstr(const char* src, const char* search) {
  char* ans = S21_NULL;
  int len_src = s21_strlen(src);
  int len_search = s21_strlen(search);
  for (int i = 0; i <= len_src - len_search && !ans; i++) {
    int flag = 1;
    for (int j = 0; j < len_search && flag; j++) {
      if (src[i + j] != search[j]) {
        flag = 0;
      }
    }
    if (flag) {
      ans = (char*)&src[i];
    }
  }
  return ans;
}