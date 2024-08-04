#include "add_funk/s21_add_funk.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  bin_operation_result return_code = BIN_OK;
  if (rows <= 0 || columns <= 0 || !result) {
    return_code = BIN_INCORRECT_MATRIX;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      return_code = BIN_INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          return_code = BIN_INCORRECT_MATRIX;
          break;
        }
      }
    }
    if (return_code == BIN_OK) {
      result->columns = columns;
      result->rows = rows;
    }
  }
  return (int)return_code;
}
