#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res_code =
      OK;  // Изначально устанавливаем результирующий код как успешный

  // Проверяем корректность входной матрицы A
  if (!is_correct(A)) {
    res_code = MATRIX_ERR;  // Возвращаем код ошибки: некорректная матрица
  }
  // Проверяем, что матрица A является квадратной
  else if (A->rows != A->columns) {
    res_code =
        CALC_ERR;  // Возвращаем код ошибки: несовпадающие размеры матрицы
  }

  else if (A->columns == 1) {
    res_code = CALC_ERR;
  }

  else {
    double det;
    s21_determinant(A, &det);

    // Проверяем, что определитель матрицы A не равен нулю
    if (det != 0) {
      matrix_t alg_add;
      res_code = s21_calc_complements(A, &alg_add);

      // Проверяем успешность вычисления алгебраических дополнений
      if (res_code == OK) {
        matrix_t tmp_trans;
        res_code = s21_transpose(&alg_add, &tmp_trans);

        // Проверяем успешность транспонирования матрицы алгебраических
        // дополнений
        if (res_code == OK) {
          // Выполняем умножение транспонированной матрицы на обратное значение
          // определителя
          s21_mult_number(&tmp_trans, 1 / det, result);
        }

        s21_remove_matrix(&tmp_trans);
      }

      s21_remove_matrix(&alg_add);
    } else {
      res_code = CALC_ERR;  // Возвращаем код ошибки: матрица вырожденная,
                            // определитель равен нулю
    }
  }

  return res_code;
}