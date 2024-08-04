#include "s21_matrix_test.h"

START_TEST(mult_matrix_norm) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = rand() % 100;

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = rand() % 100;

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < mtx.columns; j++) {
      check.matrix[i][j] = 0;
      for (int k = 0; k < m.columns; k++)
        check.matrix[i][j] += m.matrix[i][k] * mtx.matrix[k][j];
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), BIN_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix_wrong) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), BIN_INCORRECT_MATRIX);

  s21_remove_matrix(&m);

  s21_remove_matrix(&mtx);

  s21_remove_matrix(&res);

  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix_error) {
  matrix_t m = {0};
  int rows = 2;
  int cols = 3;
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  int rows1 = 4;
  int cols1 = 5;
  s21_create_matrix(rows1, cols1, &mtx);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), BIN_CALCULATION_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_m_infinity) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_initialize_matrix(&A, 1, 1);
  B.matrix[2][2] = INFINITY;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), BIN_CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST
Suite *suite_mult_matrix(void) {
  Suite *s = suite_create("suite_mult_matrix");
  TCase *tc = tcase_create("case_mult_matrix");

  tcase_add_loop_test(tc, mult_matrix_norm, 0, 100);
  tcase_add_loop_test(tc, mult_matrix_wrong, 0, 30);
  tcase_add_test(tc, mult_matrix_error);
  tcase_add_test(tc, mult_m_infinity);

  suite_add_tcase(s, tc);
  return s;
}
