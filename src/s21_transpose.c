#include "add_funk/s21_add_funk.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  bin_operation_result return_code = BIN_OK;
  if (s21_is_correct(A) || !result) {
    return_code = BIN_INCORRECT_MATRIX;
  }
  if (return_code == BIN_OK) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return (int)return_code;
}
