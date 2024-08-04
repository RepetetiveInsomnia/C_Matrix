#include "add_funk/s21_add_funk.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  bin_operation_result return_code = BIN_OK;
  if (s21_is_correct(A) || !result) {
    return_code = BIN_INCORRECT_MATRIX;
  } else if (!isfinite(number)) {
    return_code = BIN_CALCULATION_ERROR;
  }
  if (return_code == BIN_OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && return_code == BIN_OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (!isfinite(result->matrix[i][j])) {
          return_code = BIN_CALCULATION_ERROR;
        }
      }
    }
  }
  return return_code;
}
