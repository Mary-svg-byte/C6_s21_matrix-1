#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res_code = OK;

  if (is_correct(A)) {
    // Создаем новую матрицу для результата транспонирования
    res_code = s21_create_matrix(A->columns, A->rows, result);

    // Проверка успешности создания матрицы
    if (res_code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  } else {
    res_code = MATRIX_ERR;
  }

  return res_code;
}