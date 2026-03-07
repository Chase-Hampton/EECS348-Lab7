#include <stdio.h>
#define SIZE 5

void printMatrix(int matrix[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j< SIZE; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for(int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int sum[SIZE][SIZE];
    int product[SIZE][SIZE];
    int transpose[SIZE][SIZE];

    printf("Matrix 1:\n");
    printMatrix(m1);

    printf("\nMatrix 2:\n");
    printMatrix(m2);

    addMatrices(m1, m2, sum);

    printf("\nSum of Matrices:\n");
    printMatrix(sum);

    multiplyMatrices(m1, m2, product);

    printf("\nProudct of Matrices:\n");
    printMatrix(product);

    transposeMatrix(m1, transpose);

    printf("\nTranspose of Matrix 1:\n");
    printMatrix(transpose);

    return 0;

}