#include "add_funk/s21_add_funk.h"

void s21_remove_matrix(matrix_t *A) {
  if (s21_is_correct(A) == (int)BIN_OK) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
    A->matrix = NULL;
  }
}
