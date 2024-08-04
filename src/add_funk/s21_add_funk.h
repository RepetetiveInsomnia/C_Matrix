#ifndef SRC_ADD_FUNK_S21_ADD_FUNK_H_
#define SRC_ADD_FUNK_S21_ADD_FUNK_H_

#include "../s21_matrix.h"

int s21_is_correct(matrix_t *A);
int s21_is_eq(matrix_t *A, matrix_t *B);
void s21_initialize_matrix(matrix_t *A, double start, double step);
int s21_can_i_mult(matrix_t *A, matrix_t *B);
int s21_is_square(matrix_t *A);
void s21_copy_matrix(int row, int col, matrix_t *A, matrix_t *result);

#endif  // SRC_ADD_FUNK_S21_ADD_FUNK_H_
