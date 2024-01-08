#include "../s21_string.h"

int is_delim(int symbol, const char *delim);

char *s21_strtok(char *str, const char *delim) {
  static char *stringPointer = S21_NULL;
  char *result = S21_NULL;
  if (!str) str = stringPointer;
  if (str) {
    while (*str && is_delim(*str, delim)) str++;
    if (!*str) {
      result = S21_NULL;
    } else {
      result = str;
    }
    char *strCpy = str;
    while (*strCpy && !is_delim(*strCpy, delim)) {
      strCpy++;
    }
    while (*strCpy && is_delim(*strCpy, delim)) {
      *strCpy++ = '\0';
      stringPointer = strCpy;
    }
  }
  return result;
}

int is_delim(int symbol, const char *delim) {
  int result = 0;
  for (s21_size_t i = 0; i < s21_strlen(delim); i++)
    if (symbol == delim[i]) result = 1;
  return result;
}
