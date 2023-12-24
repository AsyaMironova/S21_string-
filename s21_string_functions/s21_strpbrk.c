#include <stdio.h>

#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  return s21_strlen(str2) && s21_strlen(str1) &&
                 s21_strcspn(str1, str2) != s21_strlen(str1)
             ? (char *)str1 + s21_strcspn(str1, str2)
             : S21_NULL;
}