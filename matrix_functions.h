/**
 * @file matrix_functions.h
 * @author {Nilla Moreno} ({stahlbring@gmail.com})
 * @brief bool uniqueEvenNumber. Check if a number is unique and even in the array.
 * fillMatrix: Fill a matrix with unique random numbers.
 * printMatrix: Print the elements of a matrix.
 * calculateRow: Calculate and print the sum of elements in each row of the matrix.
 * void calculateCol: Calculate and print the sum of elements in each column of the matrix.
 * @version 0.1
 * 
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H
#define MIN 10
#define MAX 1000

#include <stdbool.h>

bool uniqueEvenNumber(int number, int *array, int size);
void fillMatrix(int *array, int rows, int col);
void printMatrix(int *array, int rows, int col);
void calculateRow(int *array, int rows, int col);
void calculateCol(int *array, int rows, int col);

bool uniqueEvenNumber(int number, int *array, int size)
{
    // If the number is odd
    if (number % 2 != 0)
    {
        return false; // Number is not even
    }

    // Check if the number is already exsist in the array
    for (int i = 0; i < size; i++)
    {
        if (number == array[i])
        {
            return false; // False if number is not unique
        }
    }
    return true; // True if number is unique and even
}

// Function to fill array with unique random numbers
void fillArray(int *array, int rows, int col)
{
    srand(time(NULL));

    // Loop to fill array with unique random numbers
    for (int i = 0; i < rows * col;)
    {
        int randomNumber;
        /*This is a do-while loop.
        The loop will generate random numbers and checking if they are
        unique and even in uniqueEvenNumber function.
        It will continue looping until a unique and even number
        pops up :).*/
        do
        {
            randomNumber = rand() % (MAX - MIN + 1) + MIN;
        } while (!uniqueEvenNumber(randomNumber, array, i));

        array[i++] = randomNumber;
    }
}

// Function to print a matrix
void printMatrix(int *array, int rows, int col)
{
    // Loop that print element of the matrix

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            /*array[i * col + j] retrieves the value of the
            element at the current row and column, and
            sum += array[i * col + j] adds that value to
            the running total sum. */
            printf("%d ", array[i * col + j]);
        }
        printf("\n");
    }
}

// Function that calculate and print the sum of elements in every row of the matrix
void calculateRow(int *array, int rows, int col)
{
    // Loop that calculate and print the sum of every row
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += array[i * col + j];
        }
        printf("Row nr:%d sum:%d  \n", i + 1, sum);
    }
    printf("\n");
}

void calculateCol(int *array, int rows, int col)
{
    // Loop to calculate and print the sum of each column
    for (int j = 0; j < col; j++)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            sum += array[i * col + j];
        }
        printf("Column nr:%d sum: %d \n", j + 1, sum);
    }
    printf("\n");
}

#endif // MATRIX_FUNCTIONS_H
