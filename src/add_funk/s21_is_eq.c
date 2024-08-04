#include "s21_add_funk.h"

int s21_is_eq(matrix_t *A, matrix_t *B) {
  bin_operation_result return_code = BIN_OK;
  if ((A->columns != B->columns) || (A->rows != B->rows)) {
    return_code = BIN_CALCULATION_ERROR;
  }
  return (int)return_code;
}
