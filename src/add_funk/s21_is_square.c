#include "s21_add_funk.h"

int s21_is_square(matrix_t *A) {
  bin_operation_result return_code = BIN_CALCULATION_ERROR;
  if (A->rows == A->columns) {
    return_code = BIN_OK;
  }
  return return_code;
}
