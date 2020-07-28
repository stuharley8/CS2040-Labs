#ifndef VECTOR_H
#define VECTOR_H

/**
 * This function prints a vector using cout
 *
 * Return Value - None
 */
void printVector(int vector[], int size);

/**
 * This function performs vector addition on vectors A and B
 * and sets the result in vector C
 *
 * Return Value -
 *    true - The vector operation was successful
 *    false - The vector operation failed
 */
bool vectorAdd(int vectorA[], int sizeA,
    int vectorB[], int sizeB,
    int vectorC[], int sizeC);

/**
 * This function performs vector subtraction on vectors A and B
 * and sets the result in vector C
 *
 * Return Value -
 *    true - The vector operation was successful
 *    false - The vector operation failed
 */
bool vectorSubtract(int vectorA[], int sizeA,
    int vectorB[], int sizeB,
    int vectorC[], int sizeC);

/**
 * This function performs vector dot product on vectors A and B
 * and sets the result in 'result'
 *
 *    true - The vector operation was successful
 *    false - The vector operation failed
 */
bool vectorDotProduct(int vectorA[], int sizeA,
    int vectorB[], int sizeB,
    int& result);

/**
 * This function performs vector cross product on vectors A and B
 * and sets the result in vector C
 *
 *    true - The vector operation was successful
 *    false - The vector operation failed
 */
bool vectorCrossProduct(int vectorA[], int sizeA,
    int vectorB[], int sizeB,
    int vectorC[], int sizeC);

#endif