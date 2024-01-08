#include "s21_tests.h"

START_TEST(s21_test_sprintf_1) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Hello, World!");
  s21_sprintf(actualResult, "Hello, World!");
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_2) {
  char firstString[100] = {0};
  char secondString[100] = {0};
  int expectedResult = sprintf(firstString, "Hello, World!");
  int actualResult = s21_sprintf(secondString, "Hello, World!");
  ck_assert_int_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_3) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "I'm %d years old...", 22);
  s21_sprintf(actualResult, "I'm %d years old...", 22);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_4) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "The temperature today is %d degrees centigrade...",
          -30);
  s21_sprintf(actualResult, "The temperature today is %d degrees centigrade...",
              -30);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_5) {
  char firstString[100] = {0};
  char secondString[100] = {0};
  int expectedResult = sprintf(
      firstString, "The temperature today is %d degrees centigrade...", -30);
  int actualResult = s21_sprintf(
      secondString, "The temperature today is %d degrees centigrade...", -30);
  ck_assert_int_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_6) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "I have a fever of %d...", 37);
  s21_sprintf(actualResult, "I have a fever of %d...", 37);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_7) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "String: %ccc%%...", 'q');
  s21_sprintf(actualResult, "String: %ccc%%...", 'q');
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_8) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "String: % d...", 1);
  s21_sprintf(actualResult, "String: % d...", 1);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_9) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "String:_% 10c...", 63);
  s21_sprintf(actualResult, "String:_% 10c...", 63);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_10) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "String:_%013d...", 6);
  s21_sprintf(actualResult, "String:_%013d...", 6);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_11) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "String:_%13c...", 64);
  s21_sprintf(actualResult, "String:_%13c...", 64);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_12) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "String:_%+08d...", 64);
  s21_sprintf(actualResult, "String:_%+08d...", 64);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_13) {
  char firstString[100] = {0};
  char secondString[100] = {0};
  int expectedResult = sprintf(firstString, "String:_%+08d...", 1000 - 7);
  int actualResult = s21_sprintf(secondString, "String:_%+08d...", 1000 - 7);
  ck_assert_int_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_14) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "String:_%-08d...", 64);
  s21_sprintf(actualResult, "String:_%-08d...", 64);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_15) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "String:_% -+08c...", 65);
  s21_sprintf(actualResult, "String:_% -+08c...", 65);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_16) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "String:_%-+08d...", 666);
  s21_sprintf(actualResult, "String:_%-+08d...", 666);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_17) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%e: %e...", 0.0001);
  s21_sprintf(actualResult, "Number %%e: %e...", 0.0001);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_18) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%e: %e...", 12345.678);
  s21_sprintf(actualResult, "Number %%e: %e...", 12345.678);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_19) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%E: %E...", -6.0);
  s21_sprintf(actualResult, "Number %%E: %E...", -6.0);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_20) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%E: %E %e %E...", 0.00305305, 0.080851,
          0.0000246);
  s21_sprintf(actualResult, "Number %%E: %E %e %E...", 0.00305305, 0.080851,
              0.0000246);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_21) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%f: %f %f %f %f...", 0.0305, 0.3050, 123.123,
          98.108707);
  s21_sprintf(actualResult, "Number %%f: %f %f %f %f...", 0.0305, 0.3050,
              123.123, 98.108707);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_22) {
  char firstString[100] = {0};
  char secondString[100] = {0};
  int expectedResult = sprintf(firstString, "Number %%f: %f %f %f %f...",
                               0.0305, 0.3050, 123.123, 98.108707);
  int actualResult = s21_sprintf(secondString, "Number %%f: %f %f %f %f...",
                                 0.0305, 0.3050, 123.123, 98.108707);
  ck_assert_int_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_23) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%f: %f...", 0.0305);
  s21_sprintf(actualResult, "Number %%f: %f...", 0.0305);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_24) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%f: %.2f %.0f...", 1.11111101, 1.234);
  s21_sprintf(actualResult, "Number %%f: %.2f %0.f...", 1.11111101, 1.234);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_25) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  char testString[] = "Hello, World!";
  sprintf(expectedResult, "String: \"%s\"...", testString);
  s21_sprintf(actualResult, "String: \"%s\"...", testString);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_26) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%u: %u...", UINT_MAX + 1);
  s21_sprintf(actualResult, "Number %%u: %u...", UINT_MAX + 1);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_27) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%hd: %hd...", SHRT_MAX);
  s21_sprintf(actualResult, "Number %%hd: %hd...", SHRT_MAX);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_28) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%ld: %ld...", LONG_MAX);
  s21_sprintf(actualResult, "Number %%ld: %ld...", LONG_MAX);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_29) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%lu: %lu...", ULONG_MAX + 1);
  s21_sprintf(actualResult, "Number %%lu: %lu...", ULONG_MAX + 1);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

START_TEST(s21_test_sprintf_30) {
  char expectedResult[100] = {0};
  char actualResult[100] = {0};
  sprintf(expectedResult, "Number %%su: %hu...", USHRT_MAX + 1);
  s21_sprintf(actualResult, "Number %%su: %hu...", USHRT_MAX + 1);
  ck_assert_str_eq(expectedResult, actualResult);
}
END_TEST

Suite *test_suite_sprintf() {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_test_sprintf_1);
  tcase_add_test(tc_core, s21_test_sprintf_2);
  tcase_add_test(tc_core, s21_test_sprintf_3);
  tcase_add_test(tc_core, s21_test_sprintf_4);
  tcase_add_test(tc_core, s21_test_sprintf_5);
  tcase_add_test(tc_core, s21_test_sprintf_6);
  tcase_add_test(tc_core, s21_test_sprintf_7);
  tcase_add_test(tc_core, s21_test_sprintf_8);
  tcase_add_test(tc_core, s21_test_sprintf_9);
  tcase_add_test(tc_core, s21_test_sprintf_10);
  tcase_add_test(tc_core, s21_test_sprintf_11);
  tcase_add_test(tc_core, s21_test_sprintf_12);
  tcase_add_test(tc_core, s21_test_sprintf_13);
  tcase_add_test(tc_core, s21_test_sprintf_14);
  tcase_add_test(tc_core, s21_test_sprintf_15);
  tcase_add_test(tc_core, s21_test_sprintf_16);
  tcase_add_test(tc_core, s21_test_sprintf_17);
  tcase_add_test(tc_core, s21_test_sprintf_18);
  tcase_add_test(tc_core, s21_test_sprintf_19);
  tcase_add_test(tc_core, s21_test_sprintf_20);
  tcase_add_test(tc_core, s21_test_sprintf_21);
  tcase_add_test(tc_core, s21_test_sprintf_22);
  tcase_add_test(tc_core, s21_test_sprintf_23);
  tcase_add_test(tc_core, s21_test_sprintf_24);
  tcase_add_test(tc_core, s21_test_sprintf_25);
  tcase_add_test(tc_core, s21_test_sprintf_26);
  tcase_add_test(tc_core, s21_test_sprintf_27);
  tcase_add_test(tc_core, s21_test_sprintf_28);
  tcase_add_test(tc_core, s21_test_sprintf_29);
  tcase_add_test(tc_core, s21_test_sprintf_30);

  suite_add_tcase(s, tc_core);
  return s;
}
