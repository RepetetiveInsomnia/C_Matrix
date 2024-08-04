#include "s21_add_funk.h"

void s21_copy_matrix(int row, int col, matrix_t *A, matrix_t *result) {
  int mem_row = 0;
  int mem_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    mem_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) continue;
      result->matrix[mem_row][mem_col] = A->matrix[i][j];
      mem_col++;
    }
    mem_row++;
  }
}
