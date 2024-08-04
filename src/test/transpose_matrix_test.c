#include "s21_matrix_test.h"

START_TEST(transpose_matrix_norm) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);

  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = rand() % 100;
      m.matrix[i][j] = rand_val;
      check.matrix[j][i] = rand_val;
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), BIN_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix_neg) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), BIN_INCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_uninitialized) {
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_transpose(&A, &result), BIN_INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_init_empty) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), BIN_OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_transpose_matrix(void) {
  Suite *s = suite_create("suite_transpose_matrix");
  TCase *tc = tcase_create("case_transpose_matrix");

  tcase_add_loop_test(tc, transpose_matrix_norm, 0, 100);
  tcase_add_loop_test(tc, transpose_matrix_neg, 0, 30);
  tcase_add_test(tc, transpose_uninitialized);
  tcase_add_test(tc, transpose_init_empty);

  suite_add_tcase(s, tc);
  return s;
}
