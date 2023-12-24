#include "s21_tests.h"

int main() {
  int numberFailed = 0;
  SRunner *sr = srunner_create(NULL);

  //  srunner_add_suite(sr, test_suite_strlen());
  //  srunner_add_suite(sr, test_suite_memchr());
  //  srunner_add_suite(sr, test_suite_memcpy());
  //  srunner_add_suite(sr, test_suite_strncat());
  //  srunner_add_suite(sr, test_suite_strncmp());
  //  srunner_add_suite(sr, test_suite_strcspn());
  //  srunner_add_suite(sr, test_suite_strpbrk());
  srunner_add_suite(sr, test_suite_sprintf());
  srunner_add_suite(sr, test_suite_insert());

  srunner_run_all(sr, CK_NORMAL);

  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return !numberFailed ? 0 : 1;
}