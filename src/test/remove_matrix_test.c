#include "s21_matrix_test.h"

START_TEST(simple_remove) {
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(null_error) {
  // failure handle null pointer
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(empty_matrix) {
  // failure handle INCORRECT_MATRIX structure
  matrix_t A = {};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

Suite *suite_remove_matrix(void) {
  Suite *s = suite_create("suite_remove_matrix");
  TCase *tc = tcase_create("case_remove_matrix");

  tcase_add_test(tc, simple_remove);
  tcase_add_test(tc, null_error);
  tcase_add_test(tc, empty_matrix);
  suite_add_tcase(s, tc);

  return s;
}
