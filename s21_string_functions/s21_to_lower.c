#include <stdlib.h>

#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *address = {0};
  s21_size_t strle = s21_strlen(str);
  address = (char *)calloc(strle + 1, sizeof(char));
  if (address != S21_NULL) {
    for (s21_size_t i = 0; i < strle; i++) {
      if (str[i] >= 65 && str[i] <= 90)
        address[i] = str[i] + 32;
      else
        address[i] = str[i];
    }
  }
  return (void *)address;
}