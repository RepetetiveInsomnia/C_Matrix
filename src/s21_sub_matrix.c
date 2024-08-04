#include "add_funk/s21_add_funk.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  bin_operation_result return_code = BIN_OK;
  if (s21_is_correct(A) || s21_is_correct(B) || !result) {
    return_code = BIN_INCORRECT_MATRIX;
  } else {
    return_code = s21_is_eq(A, B);
  }

  if (return_code == BIN_OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && return_code == BIN_OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        if (!isfinite(result->matrix[i][j])) {
          return_code = BIN_CALCULATION_ERROR;
        }
      }
    }
  }
  return (int)return_code;
}
