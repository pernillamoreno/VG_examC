/**
 * @file main.c
 * @author {Nilla Moreno} ({stahlbring@gmail.com})
 * @brief Write a C program to do some operations on this matrix:
 * 1. Make a function to fill the matrix with random even, unique numbers, in the range of min and max.
 * 2. Make a function to print the matrix to the terminal.
 * 3.   Make a function to calculate sum of elements in each row of the matrix and store the result in an
 *      element of an array passed to the function. 
 * The function shall calculate sum for all rows.
 * 4.   Make a function to calculate sum of elements in each column of the matrix and store the result
 * in an element of an array passed to the function. 
 * The function shall calculate sum for all columns.
 * 5.   In the program:     Ask the user to enter the array dimensions (R and C) 
 * Make a J x K array and fill it with random, even unique numbers in the range of 10 and 1000.
 *VG: You must create a header file for the module and describe it well using the doxygen format.
You must create in_matrix function to check if the even value that will be randomly generated is in 
matrix or it is a new random value, and this function shall be called inside fillMatrix  function  
to fill the matrix with even, random, unique values.(PDF file point num 1).
 * 
 * @version 0.1
 *
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "matrix_functions.h"

// Define number between 10 and 1000
#define MIN 10
#define MAX 1000

int main()
{
    int r, c;
    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    // matrix is a pointer to an int; malloc allocates memory for the matrix with r rows and c columns.
    int *matrix = (int *)malloc(r * c * sizeof(int));

    // Check if memory allocation is successful
    if (matrix == NULL)
    {
        printf("Memory allocation error.\n");
        return 1;
    }

    // Fill the matrix with unique random numbers
    fillArray(matrix, r, c);
    printf("Matrix:\n");
    // Print the matrix
    printMatrix(matrix, r, c);

    // Print the sum of each row
    calculateRow(matrix, r, c);

    // Print the sum of each column
    calculateCol(matrix, r, c);

    // Free allocated memory
    free(matrix);

    return 0;
}
