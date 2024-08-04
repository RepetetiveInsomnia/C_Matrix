#include "add_funk/s21_add_funk.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  bin_operation_result return_code = BIN_OK;
  if (s21_is_correct(A) || !result) {
    return_code = BIN_INCORRECT_MATRIX;
  } else if (A->rows <= 1 || A->columns <= 1) {
    return_code = BIN_CALCULATION_ERROR;
  } else {
    return_code = s21_is_square(A);
  }
  if (return_code == BIN_OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0};
        double determinant = 0.0;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        s21_copy_matrix(i, j, A, &minor);
        s21_determinant(&minor, &determinant);
        result->matrix[i][j] = pow(-1, (i + j)) * determinant;
        s21_remove_matrix(&minor);
      }
  }
  return return_code;
}
