#include "../../s21_matrix.h"

int is_correct(matrix_t *matrix) {
  return (matrix != NULL && matrix->matrix != NULL && matrix->rows >= 1 &&
          matrix->columns >= 1);
}