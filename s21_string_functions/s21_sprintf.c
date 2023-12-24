#include "s21_sprintf.h"
#include "../s21_string.h"
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
//проверка на точность аргументов

int s21_validateArguments(char* buff, int size, const char* str) {
  int ValArg = 0;

  if (buff == NULL || size <= 0 || str == NULL) {
    ValArg = -1;
  }  //некорректные аргументы
  else {
    ValArg = 0;
  }
  return ValArg;  //корректные аргументы
}

// Функция для обработки флагов
int s21_processFlags(const char** str) {
  int flagWidth = 0;

  // Проверяем наличие флагов '-' '+' ' ' ':' '#'
  while (**str == '-' || **str == '+' || **str == ' ' || **str == ':' ||
         **str == '#') {
    if (**str == '-') {
      flagWidth = -1;  // Устанавливаем флаг ширины '-' (-1)
    } else if (**str == '+') {
      flagWidth = 1;  // Устанавливаем флаг ширины '+' (1)
    } else if (**str == ' ') {
      if (flagWidth == 0) {
        flagWidth = 1;  // Устанавливаем флаг ширины ' ' (1) только если флаг
                        // ширины ранее не был установлен
      }
    } else if (**str == ':') {
      flagWidth = 2;  // Устанавливаем флаг ширины ':' (2)
    } else if (**str == '#') {
      flagWidth = 3;  // Устанавливаем флаг ширины '#' (3)
    }
    (*str)++;
  }

  return flagWidth;
}

void s21_alignmentProcess(sprint_data* data){
  data->flagWidthArg = s21_alignment(data->flagWidth, data->flagWidthArg);
}

int s21_alignment(int flagWidth, int flagWidthArg) {
//  printf("flagWidth %d, flagWidthArg %d\t", flagWidth, flagWidthArg);
    if (flagWidth == -1) {
        flagWidthArg = flagWidthArg * -1;
    }
     if (flagWidth == 0) {
        flagWidthArg = flagWidthArg * 1;
    }
//    printf("flagWidth1 %d, flagWidthArg1 %d\n", flagWidth, flagWidthArg);
    return flagWidthArg;
}

// Функция для обработки ширины
int s21_processWidth(const char** str, va_list args) {
  int flagWidth = 0;

  if (**str >= '0' && **str <= '9') {
    flagWidth = 0;
    while (**str >= '0' && **str <= '9') {
      flagWidth =
          flagWidth * 10 + (**str - '0');  // Получаем числовое значение ширины
      (*str)++;
    }
    if (**str == '*') {
      flagWidth = va_arg(
          args,
          int);  // Если символ '*', получаем ширину из аргумента переменной
      (*str)++;
    }
  }

  return flagWidth;
}

// Функция для обработки точности
int s21_processPrecision(const char** str, va_list args) {
  int flagPrecision = -1;  // -1 указывает на отсутствие точности

  if (**str == '.') {
    (*str)++;
    if (**str == '*') {
      flagPrecision = va_arg(
          args,
          int);  // Если символ '*', получаем точность из аргумента переменной
      (*str)++;
    } else {
      flagPrecision = 0;
      while (**str >= '0' && **str <= '9') {
        flagPrecision = flagPrecision * 10 +
                        (**str - '0');  // Получаем числовое значение точности
        (*str)++;
      }
    }
  }

  return flagPrecision;
}

int toHex(char* buff, int written, int remaining, unsigned long long arg, sprint_data* data) {
  int hex;
  if (data->is_sharp == true){
    data->is_sharp = false;
    hex = snprintf(buff + written, remaining, "%#*.*llx", data->flagWidth,
                   data->flagPrecision, arg);
  } else hex = snprintf(buff + written, remaining, "%*.*llx", data->flagWidth,
                   data->flagPrecision, arg);



  return hex;
}

int toOct(char* buff, int written, int remaining, int flagWidth,
          int flagPrecision, unsigned long long arg, bool isSharp) {
  int oct;
  if (isSharp == true){
    isSharp = false;
    oct = snprintf(buff + written, remaining, "%#*.*llo", flagWidth,
                   flagPrecision, arg);
  } else oct = snprintf(buff + written, remaining, "%*.*llo", flagWidth,
                   flagPrecision, arg);

  return oct;
}

int toPointer(char* buff, int written, int remaining, int flagWidth,
              int flagPrecision, unsigned long long arg) {
  int pointer = snprintf(buff + written, remaining, "%#*.*llx", flagWidth,
                         flagPrecision, arg);
  return pointer;
}

// Функция для обработки длины
char s21_processLength(const char** str) {
  char flagLength = '\0';  // '\0' указывает на отсутствие длины

  if (**str == 'h' || **str == 'l' || **str == 'L') {
    flagLength = **str;  // Устанавливаем обработанную длину
    (*str)++;  // Переходим к следующему символу
  }

  return flagLength;
}

sprint_data init_sprint_data(const char* str, va_list* args) {
  sprint_data data;
  data.flagWidth = s21_processFlags(&str);
  data.flagWidthArg = s21_processWidth(&str, *args);
  data.flagPrecision = s21_processPrecision(&str, *args);
  data.is_sharp = false;
  data.flagSpecifier = *str;
  strncpy(data.longSpecifier, str, sizeof(data.longSpecifier) - 1);
  data.longSpecifier[sizeof(data.longSpecifier) - 1] = '\0'; // Ensure null-termination
  return data;
}

void check_sharp(sprint_data* data) {
  if (data->flagWidth == 3) {
    data->is_sharp = true;
  }
}
void check_flagWidth(sprint_data* data) {
  if (data->flagWidthArg != 0) {
    data->flagWidth = data->flagWidthArg;
  }
}
int s21_sprintf(char* buff, int size, const char* str, ...) {
  int written = 0;
  int remaining = size - 1;
  va_list args;
  va_start(args, str);
  sprint_data data;
  while (*str != '\0') {
    if (*str == '%') {
      str++;  // Пропускаем символ '%'
      data = init_sprint_data(str, &args);
      s21_alignmentProcess(&data);
//      printf("flagWidth: %d, flagWidthArg: %d, flagPrecision: %d\n", data.flagWidth, data.flagWidthArg, data.flagPrecision);
      check_flagWidth(&data);
      check_sharp(&data);
      parser(&data, buff, &written, &remaining, args);
      bool parser_check = parser_long(&data, buff, &written, &remaining, args);
      skip_spec_char(data,str,parser_check);
      if (*str == '#') {
        str++;
      }
      if (data.flagWidthArg > 0 || data.flagWidthArg < -1 || data.flagPrecision > 0) {
        str++;
        str++;
      }
      str++;  // Обработали спецификатор, переходим к следующему символу
      if (parser_check == true) {
        str++;
        str++;
      }
    } else {
      buff[written] = *str;
      written++;
      str++;
    }
    if (written >= size - 1) {
      break;
    }
    remaining = size - written - 1;
  }

  va_end(args);
  buff[written] = '\0';  // Завершаем строку в буфере
  return written;
}

void skip_spec_char(sprint_data data, const char* str, bool parser_check) {
  if (*str == '#') {
    str++;
  }

  if (data.flagWidthArg > 0 || data.flagWidthArg < -1 || data.flagPrecision > 0) {
    str++;
    str++;
  }


  str++;  // Обработали спецификатор, переходим к следующему символу
  if (parser_check == true) {
    str++;
    str++;
  }
}

void parser(sprint_data* data, char* buff, int* written, const int* remaining,
            va_list args) {
  switch (data->flagSpecifier) {
    case 'c': {
      int arg = va_arg(args, int);
      *written += snprintf(buff + *written, *remaining, "%c", arg);
      break;
    }
    case 'd':
    case 'i': {
      int arg = va_arg(args, int);
      *written += snprintf(buff + *written, *remaining, "%0*.*d",
                           data->flagWidth, data->flagPrecision, arg);
//      printf("flagWidth %d, flagWidthArg %d\n", data->flagWidth, data->flagWidthArg);
      break;
    }

    case 'f':
    case 'g':
    case 'G': {
      double arg = va_arg(args, double);
      *written += snprintf(buff + *written, *remaining, "%0*.*g",
                           data->flagWidth, data->flagPrecision, arg);
      break;
    }
    case 'e':
    case 'E': {
      double arg = va_arg(args, double);
      *written += snprintf(buff + *written, *remaining, "%0*.*e",
                           data->flagWidth, data->flagPrecision, arg);
      break;
    }
    case 's': {
      const char* arg = va_arg(args, const char*);
      *written += snprintf(buff + *written, *remaining, "%*.*s",
                           data->flagWidth, data->flagPrecision, arg);
      break;
    }
    case 'u': {
      unsigned int arg = va_arg(args, unsigned int);
      *written += snprintf(buff + *written, *remaining, "%0*.*u",
                           data->flagWidth, data->flagPrecision, arg);
      break;
    }
    case '%': {
      *written += snprintf(buff + *written, *remaining, "%%");
      break;
    }
    case 'x':
    case 'X': {
      unsigned long long arg = va_arg(args, unsigned long long);
      *written += toHex(buff, *written, *remaining, arg ,data);
      break;
    }
    case 'p':
    case 'P': {
      unsigned long long arg = va_arg(args, unsigned long long);
      *written += toPointer(buff, *written, *remaining, data->flagWidth,
                            data->flagPrecision, arg);
      break;
    }
    case 'o':
    case 'O': {
      unsigned long long arg = va_arg(args, unsigned long long);
      *written += toOct(buff, *written, *remaining, data->flagWidth,
                        data->flagPrecision, arg, data->is_sharp);
      break;
    }
  }
}

int long_long_group (sprint_data* data, char* buff, int* written,const int* remaining, va_list args) {
  bool stat = false;
  if (strcmp(data->longSpecifier, "lld") == 0) {
    long long int arg = va_arg(args, long long int);
    *written += snprintf(buff + *written, *remaining, "%0*.*lld", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  else if (strcmp(data->longSpecifier, "llu") == 0) {
    unsigned long long int arg = va_arg(args, unsigned long long int);
    *written += snprintf(buff + *written, *remaining,"%0*.*llu", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  return stat;
}

int long_group(sprint_data* data, char* buff, int* written,const int* remaining, va_list args){
  bool stat = false;
  if (strcmp(data->longSpecifier, "ld") == 0|| strcmp(data->longSpecifier, "li") == 0) {
    long int arg = va_arg(args, long int);
    *written += snprintf(buff + *written, *remaining, "%0*.*ld", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  else if (strcmp(data->longSpecifier, "lu") == 0) {
    unsigned long int arg = va_arg(args, unsigned long int);
    *written += snprintf(buff + *written, *remaining, "%0*.*lu", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }

  else if (strcmp(data->longSpecifier, "lf") == 0) {
    double arg = va_arg(args, double );
    *written += snprintf(buff + *written, *remaining, "%0*.*lf", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  else if (strcmp(data->longSpecifier, "le") == 0) {
    double arg = va_arg(args, double );
    *written += snprintf(buff + *written, *remaining, "%0*.*le", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  else if (strcmp(data->longSpecifier, "lg") == 0) {
    double arg = va_arg(args, double );
    *written += snprintf(buff + *written, *remaining, "%0*.*lg", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  return stat;
}

int long_double_group(sprint_data* data, char* buff, int* written,const int* remaining, va_list args){
  bool stat = false;
  if (strcmp(data->longSpecifier, "Lf") == 0) {
    long double arg = va_arg(args,long double );
    *written += snprintf(buff + *written, *remaining, "%0*.*Lf", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  else if (strcmp(data->longSpecifier, "Le") == 0) {
    long double arg = va_arg(args,long double );
    *written += snprintf(buff + *written, *remaining, "%0*.*Le", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  else if (strcmp(data->longSpecifier, "Lg") == 0) {
    long double arg = va_arg(args,long double );
    *written += snprintf(buff + *written, *remaining, "%0*.*Le", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  return stat;
}
int short_int_group(sprint_data* data, char* buff, int* written, const int* remaining, va_list args) {
  bool stat = false;
  if (strcmp(data->longSpecifier, "hd") == 0 || strcmp(data->longSpecifier, "hi") == 0){
    short int arg = va_arg(args, int);
    *written += snprintf(buff + *written, *remaining,"%0*.*hd", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  else if (strcmp(data->longSpecifier, "hu") == 0){
    unsigned short int arg = va_arg(args,  int);
    *written += snprintf(buff + *written, *remaining,"%0*.*hu", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  return stat;
}

int ascii_dec(sprint_data* data, char* buff, int* written, const int* remaining, va_list args) {
  bool stat = false;
  if (strcmp(data->longSpecifier, "hhd") == 0 || strcmp(data->longSpecifier, "hi") == 0) {
    int arg = va_arg(args,  int);
    *written += snprintf(buff + *written, *remaining, "%0*.*hhd", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  else if (strcmp(data->longSpecifier, "hhu") == 0) {
    unsigned int arg = va_arg(args,  int);
    *written += snprintf(buff + *written, *remaining, "%0*.*hhu", data->flagWidth, data->flagPrecision, arg);
    stat = true;
  }
  return stat;
}

int parser_long(sprint_data* data, char* buff, int* written, int* remaining, va_list args){
  bool stat = false;
  strtok(data->longSpecifier, " %");
  // Пока есть мусорный вывод есть артефакты при мусорном выводе. Жду фикса и дальнейшей проверки
  if (long_long_group(data, buff ,written, remaining, args) ||
      long_group(data, buff ,written, remaining, args) ||
      long_double_group(data, buff, written, remaining, args) ||
      short_int_group(data, buff, written, remaining, args) ||
      ascii_dec(data, buff ,written, remaining, args))
  {
    stat = true;
  }
  return stat;
}
