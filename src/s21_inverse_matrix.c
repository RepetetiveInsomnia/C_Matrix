#include "add_funk/s21_add_funk.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  bin_operation_result return_code = BIN_OK;
  if (s21_is_correct(A) || !result) {
    return_code = BIN_INCORRECT_MATRIX;
  } else if (A->rows == 1 && A->columns == 1 && A->matrix[0][0] != 0) {
    return_code = s21_create_matrix(A->rows, A->rows, result);
    if (return_code == BIN_OK) {
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    }
  } else {
    double det = 0.0;
    return_code = s21_determinant(A, &det);
    if (return_code == BIN_OK && det != 0) {
      matrix_t calc = {0};
      return_code = s21_calc_complements(A, &calc);
      if (return_code == BIN_OK) {
        matrix_t trans = {0};
        return_code = s21_transpose(&calc, &trans);
        if (return_code == BIN_OK) {
          s21_mult_number(&trans, 1 / det, result);
        }
        s21_remove_matrix(&trans);
      }
      s21_remove_matrix(&calc);
    }
    if (det == 0.0) {
      return_code = BIN_CALCULATION_ERROR;
    }
  }
  return return_code;
}
