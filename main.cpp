#include <iostream>

#include "vector.h"

using namespace std;

void inputVectorValues(int vector[], int size);

int main() {
    cout << "Enter vector A: (Numbers separated by spaces, the first is the dimensions)" << endl;
    int sizeA;
    cin >> sizeA;
    if(sizeA < 0) {
        cout << "\nError, invalid vector dimensions: " << sizeA << " Goodbye." << endl;
        return 1;
    }
    int vectorA[sizeA];
    inputVectorValues(vectorA, sizeA);
    cout << "Enter vector B:" << endl;
    int sizeB;
    cin >> sizeB;
    if(sizeB < 0) {
        cout << "\nError, invalid vector dimensions: " << sizeB << " Goodbye." << endl;
        return 1;
    }
    int vectorB[sizeB];
    inputVectorValues(vectorB, sizeB);
    int operation;
    cout << "\nEnter the operation to perform:\n1: Addition" << endl;
    cout << "2: Subtraction\n3: Dot Product\n4: Cross Product" << endl;
    cin >> operation;
    int vectorC[sizeA];
    switch(operation) {
        case 1:
            if(vectorAdd(vectorA, sizeA, vectorB, sizeB, vectorC, sizeA)) {
                cout << "\nThe result is:" << endl;
                printVector(vectorC, sizeA);
            } else {
                cout << "\nInvalid sizes of vectors for vector addition. Goodbye." << endl;
                return 1;
            }
            break;
        case 2:
            if(vectorSubtract(vectorA, sizeA, vectorB, sizeB, vectorC, sizeA)) {
                cout << "\nThe result is:" << endl;
                printVector(vectorC, sizeA);
            } else {
                cout << "\nInvalid sizes of vectors for vector subtraction. Goodbye." << endl;
                return 1;
            }
            break;
        case 3:
            int result;
            if(vectorDotProduct(vectorA, sizeA, vectorB, sizeB, result)) {
                cout << "\nThe result is:\n" << result << endl;
            } else {
                cout << "\nInvalid sizes of vectors for dot product operation. Goodbye." << endl;
                return 1;
            }
            break;
        case 4:
            if(vectorCrossProduct(vectorA, sizeA, vectorB, sizeB, vectorC, sizeA)) {
            cout << "\nThe result is:" << endl;
            printVector(vectorC, sizeA);
            } else {
                cout << "\nInvalid sizes of vectors for cross product operation. Goodbye." << endl;
                return 1;
            }
            break;
        default:
            cout << "\nInvalid selection. Goodbye." << endl;
            return 1;
    }
    return 0;
}

/**
 * @brief Helper method for inputing the vector values
 * @param vector
 * @param size
 */
void inputVectorValues(int vector[], int size) {
    int num;
    for(int i = 0; i < size; i++) {
        cin >> num;
        vector[i] = num;
    }
}