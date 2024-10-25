#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res_code = OK;
  if (!is_correct(A)) {
    res_code = MATRIX_ERR;
  } else if (A->rows != A->columns || A->rows == 1) {
    res_code = CALC_ERR;
  } else {
    double buffer = 0;
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        buffer = 0;
        matrix_t BufferMat = {0};
        s21_create_minor(j, i, A, &BufferMat);
        s21_determinant(&BufferMat, &buffer);
        result->matrix[i][j] = buffer * pow(-1, i + j);
        s21_remove_matrix(&BufferMat);
      }
    }
  }
  return res_code;
}

void s21_create_minor(int pos_x, int pos_y, matrix_t *A, matrix_t *result) {
  s21_create_matrix(A->rows - 1, A->columns - 1, result);
  int flag = 0, flag_y = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == pos_y) {
      flag_y = 1;
      continue;
    }
    for (int j = 0; j < A->columns; j++) {
      if (j == pos_x) {
        flag = 1;
        continue;
      }
      result->matrix[i - flag_y][j - flag] = A->matrix[i][j];
    }
    flag = 0;
  }
}