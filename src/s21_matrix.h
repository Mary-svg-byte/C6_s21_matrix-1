#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define OK 0
#define MATRIX_ERR 1
#define CALC_ERR 2

#define FAILURE 0
#define SUCCESS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int is_correct(matrix_t *matrix);
void printMatrix(matrix_t *matrix_print);

void s21_create_minor(int pos_x, int pos_y, matrix_t *A, matrix_t *result);

#endif