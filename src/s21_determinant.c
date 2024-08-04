#include "add_funk/s21_add_funk.h"

int s21_determinant(matrix_t *A, double *result) {
  *result = 0.0;
  double mem_result = 0.0;
  bin_operation_result return_code = BIN_OK;
  if (s21_is_correct(A)) {
    return_code = BIN_INCORRECT_MATRIX;
  } else {
    return_code = s21_is_square(A);
  }
  if (return_code == BIN_OK) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      matrix_t minor = {0};
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      for (int i = 0; i < A->columns; i++) {
        s21_copy_matrix(0, i, A, &minor);
        s21_determinant(&minor, &mem_result);
        if (i % 2) {
          *result -= A->matrix[0][i] * mem_result;
        } else {
          *result += A->matrix[0][i] * mem_result;
        }
      }
      s21_remove_matrix(&minor);
    }
  }
  return return_code;
}
