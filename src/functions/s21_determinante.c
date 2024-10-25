#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res_code = OK;
  if (!is_correct(A)) {
    res_code = MATRIX_ERR;
  } else if (A->rows != A->columns) {
    res_code = CALC_ERR;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = 0;
    double sign = 1, res_buf = 0;
    matrix_t buffer = {0};
    for (int i = 0; i < A->rows; i++) {
      res_buf = 0;
      s21_create_minor(i, 0, A, &buffer);
      s21_determinant(&buffer, &res_buf);
      *result += res_buf * A->matrix[0][i] * sign;
      s21_remove_matrix(&buffer);

      sign *= -1;
    }
  }
  return res_code;
}