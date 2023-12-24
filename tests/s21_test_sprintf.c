#include <stdio.h>

#include "s21_tests.h"

START_TEST(test_case1) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  int num = 5;
  sprintf(buffer, "Number: %d", num);
  s21_sprintf(buffer1, 100, "Number: %d", num);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case2) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  float f = 0.6581065f;
  sprintf(buffer, "Float: %.2f", f);
  s21_sprintf(buffer1, 100, "Float: %.2f", f);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case3) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  char d1[4] = "abc";
  printf("%s\n", d1);
  sprintf(buffer, "%s", d1);
  s21_sprintf(buffer1, 1000, "%s", d1);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case4) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  sprintf(buffer, "Number: %d", 1000000);
  s21_sprintf(buffer1, 100, "Number: %d", 1000000);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case5) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  sprintf(buffer, "Empty string: %s", "");
  s21_sprintf(buffer1, 100, "Empty string: %s", "");
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case6) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  int oct = 20;
  sprintf(buffer, "Empty string: %x %o %i %s", oct, oct, oct, "124fdgbf");
  s21_sprintf(buffer1, 100, "Empty string: %x %o %i %s", oct, oct, oct,
              "124fdgbf");
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case7) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  double d1 = 123.456;
  sprintf(buffer, "%e", d1);
  s21_sprintf(buffer1, 100, "%e", d1);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case8) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  double d1 = 123.4567, d2 = 1234567.34567;
  sprintf(buffer, "%g\n%g", d1, d2);
  s21_sprintf(buffer1, 100, "%g\n%g", d1, d2);
  ck_assert_str_eq(buffer, buffer1);
}

START_TEST(test_case9) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  unsigned int d1 = 123;
  unsigned int d2 = 256;
  sprintf(buffer, "%#x, %#x", d1, d2);
  s21_sprintf(buffer1, 100, "%#x, %#x", d1, d2);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case10) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  double d1 = 123.4567, d2 = 1234567.34567;
  sprintf(buffer, "%g\n%g", d1, d2);
  s21_sprintf(buffer1, 100, "%g\n%g", d1, d2);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST
START_TEST(test_case11) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  int d1 = -123;
  sprintf(buffer, "%06d", d1);
  s21_sprintf(buffer1, 100, "%06d", d1);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case12) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  int d1 = 123, d2 = 42, d3 = 1543;
  sprintf(buffer, "%-6d%-6d%-6d\n", d1, d2, d3);
  s21_sprintf(buffer1, 100, "%-6d%-6d%-6d\n", d1, d2, d3);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case13) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  long long int d1 = 123;
  sprintf(buffer, "%lld %lld", d1, d1);
  s21_sprintf(buffer1, 100, "%lld %lld", d1, d1);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case14) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  char d1[4] = "abc";
  sprintf(buffer, "%p", d1);
  s21_sprintf(buffer1, 100, "%p", d1);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_case15) {
  char buffer[100] = {0};
  char buffer1[100] = {0};
  char d1 = 'g', d2 = 5;

  sprintf(buffer, "%hhd %hhd", d1, d2);
  s21_sprintf(buffer1, 100, "%hhd %hhd", d1, d2);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST
Suite *test_suite_sprintf() {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_case1);
  tcase_add_test(tc_core, test_case2);
  tcase_add_test(tc_core, test_case3);
  tcase_add_test(tc_core, test_case4);
  tcase_add_test(tc_core, test_case5);
  tcase_add_test(tc_core, test_case6);
  tcase_add_test(tc_core, test_case7);
  tcase_add_test(tc_core, test_case8);
  tcase_add_test(tc_core, test_case9);
  tcase_add_test(tc_core, test_case10);
  tcase_add_test(tc_core, test_case11);
  tcase_add_test(tc_core, test_case12);
  tcase_add_test(tc_core, test_case13);
  tcase_add_test(tc_core, test_case14);
  tcase_add_test(tc_core, test_case15);
  suite_add_tcase(s, tc_core);
  return s;
}