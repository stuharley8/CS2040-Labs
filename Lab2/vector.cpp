#include <iostream>

using namespace std;

/**
 * This function prints a vector using cout
 *
 * Return Value - None
 */
void printVector(int vector[], int size) {
    for(int i = 0; i < size; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

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
    int vectorC[], int sizeC) {
        if(sizeA != sizeB || sizeA != sizeC) {
            return false;
        }
        for(int i = 0; i < sizeA; i++) {
            vectorC[i] = vectorA[i] + vectorB[i];
        }
        return true;
    }

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
    int vectorC[], int sizeC) {
        if(sizeA != sizeB || sizeA != sizeC) {
            return false;
        }
        for(int i = 0; i < sizeA; i++) {
            vectorC[i] = vectorA[i] - vectorB[i];
        }
        return true;
    }

/**
 * This function performs vector dot product on vectors A and B
 * and sets the result in 'result'
 *
 *    true - The vector operation was successful
 *    false - The vector operation failed
 */
bool vectorDotProduct(int vectorA[], int sizeA,
    int vectorB[], int sizeB,
    int& result) {
        if(sizeA != sizeB) {
            return false;
        }
        for(int i = 0; i < sizeA; i++) {
            result += vectorA[i] * vectorB[i];
        }
        return true;
    }

/**
 * This function performs vector cross product on vectors A and B
 * and sets the result in vector C
 *
 *    true - The vector operation was successful
 *    false - The vector operation failed
 */
bool vectorCrossProduct(int vectorA[], int sizeA,
    int vectorB[], int sizeB,
    int vectorC[], int sizeC) {
        if(sizeA != 3 || sizeB != 3 || sizeC != 3) {
            return false;
        }
        vectorC[0] = vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1];
        vectorC[1] = vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2];
        vectorC[2] = vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0];
        return true;
    }