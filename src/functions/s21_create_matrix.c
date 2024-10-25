#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res_code = OK;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    res_code = MATRIX_ERR;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->rows = rows;
    result->columns = columns;
  }
  return res_code;
}