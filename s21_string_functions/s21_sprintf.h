#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> // Заголовочный файл для работы с переменным количеством аргументов
#include <stdbool.h>


typedef struct {
    va_list args;
    bool is_sharp;
    int flagWidth;
    int flagWidthArg;
    int flagPrecision;
    char flagSpecifier;
    char longSpecifier[10];
} sprint_data;





sprint_data init_sprint_data(const char* str, va_list* args);
int s21_sprintf(char *buff, int size, const char *str,
                ...);

int s21_validateArguments(char* buff, int size, const char* str);
int s21_processFlags(const char** str);
int s21_processPrecision(const char** str, va_list args);
int s21_alignment(int flagWidth, int flagWidthArg);
void s21_alignmentProcess(sprint_data* data);
int s21_processWidth(const char** str, va_list args);
int toHex(char* buff, int written, int remaining, unsigned long long arg, sprint_data* data);
int toOct(char* buff, int written, int remaining, int flagWidth, int flagPrecision, unsigned long long arg, bool isSharp);
int toPointer(char* buff, int written, int remaining, int flagWidth, int flagPrecision, unsigned long long arg);
void parser(sprint_data* data, char* buff, int* written, const int* remaining, va_list args);
void check_sharp(sprint_data* data);
void check_flagWidth(sprint_data* data);
int parser_long(sprint_data* data, char* buff, int* written, int* remaining, va_list args);
int long_long_group (sprint_data* data, char* buff, int* written,const int* remaining, va_list args);
int long_group(sprint_data* data, char* buff, int* written,const int* remaining, va_list args);
int long_double_group(sprint_data* data, char* buff, int* written,const int* remaining, va_list args);
int short_int_group(sprint_data* data, char* buff, int* written, const int* remaining, va_list args);
int ascii_dec(sprint_data* data, char* buff, int* written, const int* remaining, va_list args);
void skip_spec_char(sprint_data data, const char* str, bool parser_check);
#endif // S21_SPRINTF_H
