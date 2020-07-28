 /*
 * Course: CS-2040-041
 * Spring 2020
 * Lab 5 - Matrix Math
 * Name: Stuart Harley
 * Created: 04/18/2020
 */

#include "Matrix.h"

#include <iostream>

using namespace std;

void test1();
void testMatrixMultiplication();
void testFailures();

int main()
{
	test1();
    testMatrixMultiplication();
    testFailures();
    return 0;
}

void test1() {
    // Create matrix
	Matrix A(2, 2);
	
	// Set some values
	A.setValue(0, 0, 3.14);
	A.setValue(0, 1, 10.5);
	A.setValue(1, 0, 1.0);
	A.setValue(1, 1, 1.11);
	
	// Print out a value in the matrix
	cout << "A[0][1] == " << A.getValue(0, 1) << endl;
	
	// Print out the whole matrix
	cout << "A = " << endl;
	cout << A << endl;
    
    // Read a matrix from a file
	string path;
	cout << "Enter path to a matrix file: " << endl;
	cin >> path;
	Matrix B(path);
	
	// Add the matrices
	Matrix C = A + B;
	cout << "A = " << endl;
	cout << A << endl;
	cout << "B = " << endl;
	cout << B << endl;
	cout << "A + B = " << endl;
	cout << C << endl;
    
    // Subtraction;
    C = A - B;
    cout << "A - B = " << endl;
    cout << C << endl;
    
	// Scale a matrix
	Matrix D = 4.0 * A;
	cout << "4.0 * A = " << endl;
	cout << D << endl;
    Matrix E = A * 4.0;
    cout << "A * 4.0 = " << endl;
    cout << E << endl;
	
	// Equivalence check
	if(A != D) {
		cout << "A and D are not equal" << endl;
	}
	if(A == A) {
		cout << "A is equal to itself" << endl;
	}
    cout << endl;
}

void testMatrixMultiplication() {
	Matrix A(2, 2);
	A.setValue(0, 0, 1);
	A.setValue(0, 1, 4);
	A.setValue(1, 0, 2);
	A.setValue(1, 1, 6);
    
    Matrix B(2, 3);
	B.setValue(0, 0, 1);
	B.setValue(0, 1, 4);
    B.setValue(0, 2, 0);
	B.setValue(1, 0, 1);
	B.setValue(1, 1, 2);
    B.setValue(1, 2, 3);
    
    Matrix C = A * B;
    Matrix D = B * A;
	cout << "E = " << endl;
	cout << A << endl;
	cout << "F = " << endl;
	cout << B << endl;
	cout << "E * F = " << endl;
	cout << C << endl;
    cout << "F * E = " << endl;
    cout << D << endl;
}

void testFailures() {
    Matrix A = Matrix("../matrix3.txt");
    Matrix B = Matrix(1,3);
    Matrix C = Matrix(2,1);
    Matrix D = B + C;
    Matrix E = C - B;
    Matrix F = B * C;
    Matrix G = C * B;
    cout << D << endl;
    cout << E << endl;
    cout << (D == E) << endl;
}