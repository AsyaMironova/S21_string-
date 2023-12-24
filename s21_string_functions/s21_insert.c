#include <stdlib.h>

#include "../s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  char* out = NULL;
  if (src && str) {
    size_t src_len = s21_strlen(src);
    size_t str_len = s21_strlen(str);

    out = (char *)calloc((src_len + str_len + 1), sizeof(char));

    if (out && str && s21_strlen(src) >= start_index) {
      s21_strncpy(out, src, start_index);
      s21_strncpy(out + start_index, str, str_len);
      s21_strncpy(out + start_index + str_len, src + start_index,
                  src_len - start_index);
      out[src_len + str_len] = '\0';
    }
  } else if (!str && src) {
    size_t src_len = s21_strlen(src);
    out = (char *)calloc((src_len + 1), sizeof(char));
    if (out) {
      s21_strncpy(out, src, src_len);
    }
  }
  return out;
}