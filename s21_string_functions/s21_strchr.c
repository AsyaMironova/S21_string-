#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *pointer = 0;
  int i = 0;
  while (str[i] && str[i] != c) ++i;  // нашли первое вхождене символа
  if (c == str[i])
    pointer = (char *)str + i;
  else
    pointer = S21_NULL;
  return pointer;
}