#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = OK;

  if (!is_correct(A) || !is_correct(B)) {
    return_code = MATRIX_ERR;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    return_code = CALC_ERR;
  }

  if (return_code == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return return_code;
}