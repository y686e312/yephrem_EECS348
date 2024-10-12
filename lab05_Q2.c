#include <stdio.h>

int addMatrices(int matrix_1[5][5], int matrix_2[5][5], int result[5][5]) 
{
    for (int i = 0; i < 5; i++) //i initialized to 0, loops until i isnt < 5, and i is incremented after each iteration
    {
        for (int j = 0; j < 5; j++) // same as before but for the second matrix
        {
            result[i][j] = matrix_1[i][j] + matrix_2[i][j];  //the new matrix is the sum of the entries
        }
    }
}

int multiplyMatrices(int matrix_1[5][5], int matrix_2[5][5], int result[5][5]) 
{
    for (int i = 0; i < 5; i++) //same loop(row)
    {
        for (int j = 0; j < 5; j++) //same loop (column)
        {
            result[i][j] = 0; // we initialize to 0 to start the multiplication
            for (int k = 0; k < 5; k++) //loops 5 times for each row/column
            {
                result[i][j] += matrix_1[i][k] * matrix_2[k][j];  //multiplies each entry in the row to the other matrix's column
            }
        }
    }
}

int transposeMatrix(int matrix[5][5], int result[5][5]) 
{
    for (int i = 0; i < 5; i++) //same loop
    {
        for (int j = 0; j < 5; j++) //same loop
        {
            result[j][i] = matrix[i][j];  //we switch the entries for the matrices and get the transpose
        }
    }
}

int printMatrix(int matrix[5][5]) 
{
    for (int i = 0; i < 5; i++) //iterates through the matrices after each result
    {
        for (int j = 0; j < 5; j++) 
        {
            printf("%d\t", matrix[i][j]);  //prints the each entry row by row
        }
        printf("\n");   // prints a new line after each row of the matrix
    }
}

int main() 
{
    int matrix_1[5][5] = 
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int matrix_2[5][5] = 
    {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1},
    };

    int result[5][5];
    printf("Matrix Sum: \n");
    addMatrices(matrix_1, matrix_2, result);
    printMatrix(result);
    printf("\nMatrix Product : \n");
    multiplyMatrices(matrix_1, matrix_2, result);
    printMatrix(result);
    printf("\nTranspose of Matrix 1 : \n");
    transposeMatrix(matrix_1, result);
    printMatrix(result);
    printf("\nTranspose of Matrix 2 : \n");
    transposeMatrix(matrix_2, result);
    printMatrix(result);

    return 0;
}