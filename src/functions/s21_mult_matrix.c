#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = OK;

  if (is_correct(A) && is_correct(B)) {
    if (A->columns == B->rows || A->rows == B->columns) {
      res_code = s21_create_matrix(A->rows, B->columns, result);
      if (res_code == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;  // Инициализация элемента результата
            for (int k = 0; k < B->rows; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    } else {
      res_code = CALC_ERR;  // Несовпадающие размеры матриц
    }
  } else {
    res_code = MATRIX_ERR;  // Некорректная матрица
  }

  return res_code;
}