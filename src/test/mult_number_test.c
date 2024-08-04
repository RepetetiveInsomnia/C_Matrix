#include "s21_matrix_test.h"

START_TEST(mult_number_norm) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  double mult_number = rand() % 100;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = rand() % 100;
      check.matrix[i][j] = m.matrix[i][j] * mult_number;
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res), BIN_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_wrong) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  double mult_number = rand() % 100;

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res),
                   BIN_INCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_infinity) {
  matrix_t A = {0};
  matrix_t result = {0};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  A.matrix[2][2] = INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), BIN_CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_mult_number_matrix(void) {
  Suite *s = suite_create("suite_mult_number_matrix");
  TCase *tc = tcase_create("case_mult_number_matrix");

  tcase_add_loop_test(tc, mult_number_norm, 0, 100);
  tcase_add_loop_test(tc, mult_number_wrong, 0, 30);
  tcase_add_test(tc, mult_number_infinity);

  suite_add_tcase(s, tc);
  return s;
}
