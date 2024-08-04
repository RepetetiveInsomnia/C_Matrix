#include "add_funk/s21_add_funk.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  bin_operation_result return_code = SUCCESS;
  if (s21_is_correct(A) || s21_is_correct(B)) {
    return_code = FAILURE;

  } else if (s21_is_eq(A, B)) {
    return_code = FAILURE;
  }
  if (return_code == SUCCESS) {
    for (int i = 0; i < A->rows && return_code == SUCCESS; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > PRECISION) {
          return_code = FAILURE;
        }
      }
    }
  }
  return (int)return_code;
}
