 /*
 * Course: CS-2040-041
 * Spring 2020
 * Lab 5 - Matrix Math
 * Name: Stuart Harley
 * Created: 04/18/2020
 */
 
#ifndef MATRIX_H
#define MATRIX_H

#include <string>
 
class Matrix
{
private:
    int rows;
    int columns;
    double** matrix;
public:
    Matrix();
    Matrix(int r, int c);
    Matrix(std::string filename);
    Matrix(const Matrix& other);
    ~Matrix();
    int getRows() const;
    int getColumns() const;
    double getValue(int row, int column) const;
    void setValue(int row, int column, double value);
    Matrix& operator=(const Matrix& other);
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double num) const;
    operator bool() const;
};

Matrix operator*(double num, const Matrix& rhs);

std::ostream& operator<<(std::ostream& out, const Matrix& rhs);

#endif