#include "s21_matrix_test.h"

START_TEST(create_norm) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 0;
      ck_assert_double_eq(0, m.matrix[i][j]);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_zero_1) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), BIN_INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_zero_2) {
  const int rows = 10;
  const int cols = 0;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), BIN_INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_null) {
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), BIN_INCORRECT_MATRIX);
}
END_TEST
Suite *suite_create_matrix(void) {
  Suite *s = suite_create("suite_create_matrix");
  TCase *tc = tcase_create("case_create_matrix");

  tcase_add_loop_test(tc, create_norm, 0, 100);
  tcase_add_test(tc, create_zero_1);
  tcase_add_test(tc, create_zero_2);
  tcase_add_test(tc, create_null);
  suite_add_tcase(s, tc);
  return s;
}
