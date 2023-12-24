#include "../s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  static char* stringPointer = S21_NULL;
  char* result = S21_NULL;
  if (str) stringPointer = str;
  if (stringPointer) {
    result = stringPointer;
    stringPointer += s21_strcspn(stringPointer, delim);
    if (*stringPointer != '\0') *stringPointer++ = '\0';
  }
  return *result != '\0' ? result : S21_NULL;
}