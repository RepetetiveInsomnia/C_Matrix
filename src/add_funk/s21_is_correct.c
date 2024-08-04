#include "s21_add_funk.h"

int s21_is_correct(matrix_t *A) {
  bin_operation_result return_code = BIN_INCORRECT_MATRIX;
  if (A) {
    if (A->matrix) {
      if (A->rows >= 1 && A->columns >= 1) {
        return_code = BIN_OK;
      }
    }
  }
  return (int)return_code;
}
