 /*
 * Course: CS-2040-041
 * Spring 2020
 * Lab 5 - Matrix Math
 * Name: Stuart Harley
 * Created: 04/18/2020
 */
 
#include "Matrix.h"
 
#include <cfloat>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>

bool doublesEquals(double a, double b);

Matrix::Matrix()
    :rows(0), columns(0)
{
    this -> matrix = nullptr;
}

Matrix::Matrix(int r, int c)
    :rows(r), columns(c)
{
    if(r <= 0 || c <= 0) {
        Matrix();
    } else {
        this -> matrix = new double*[r];
        for(int i = 0; i < r; i++) {
            this -> matrix[i] = new double[c];
            for(int j = 0; j < c; j++) {
                this -> matrix[i][j] = 0.0;
            }
        }
    }            
}

Matrix::Matrix(std::string filename)
{
    std::ifstream fin;
    fin.open(filename);
    if(!fin.good()) {
        std::cout << "Unable to load file" << std::endl;
        Matrix();
    } else {
        int r;
        int c;
        fin >> r;
        fin >> c;
        this -> rows = r;
        this -> columns = c;
        double num;
        this -> matrix = new double*[r];
        for(int i = 0; i < rows; i++) {
            this -> matrix[i] = new double[c];
            for(int j = 0; j < columns; j++) {
                fin >> num;
                this -> matrix[i][j] = num;
            }
        }
    }
}

Matrix::Matrix(const Matrix& other)
{
    if(!other) {
        Matrix();
    } else {
        this -> rows = other.getRows();
        this -> columns = other.getColumns();
        this -> matrix = new double*[rows];
        for(int i = 0; i < rows; i++) {
            this -> matrix[i] = new double[columns];
            for(int j = 0; j < columns; j++) {
                this -> matrix[i][j] = other.getValue(i, j);
            }
        }
    }
}

Matrix::~Matrix()
{   
    if(*this) {
        for(int i = 0; i < rows; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;
    }
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

double Matrix::getValue(int row, int column) const {
    if(!*this || row >= rows || column >= columns) {
        return 0;
    }
    return matrix[row][column];
}

void Matrix::setValue(int row, int column, double value) {
    if(*this && row >= 0 && row < rows && column >= 0 && column < columns) {
        matrix[row][column] = value;
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if(this != &other) {
        if(*this) {
            for(int i = 0; i < rows; i++) {
                delete [] matrix[i];
            }
            delete [] matrix;
        }
        this -> rows = other.getRows();
        this -> columns = other.getColumns();
        this -> matrix = new double*[rows];
        for(int i = 0; i < rows; i++) {
            this -> matrix[i] = new double[columns];
            for(int j = 0; j < columns; j++) {
                this -> matrix[i][j] = other.getValue(i, j);
            }
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix& other) const {
    bool equal = true;
    if(rows != other.getRows() || columns != other.getColumns()) {
        equal = false;
    } else {
        if(*this && other) {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    if(!doublesEquals(getValue(i, j), other.getValue(i, j))) {
                        equal = false;
                        break;
                    }
                }
            }
        }
    }
    return equal;
}

bool Matrix::operator!=(const Matrix& other) const {
    bool unequal = false;
    if(rows != other.getRows() || columns != other.getColumns()) {
        unequal = true;
    } else {
        if(*this && other) {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    if(!doublesEquals(getValue(i, j), other.getValue(i, j))) {
                        unequal = true;
                        break;
                    }
                }
            }
        }
    }
    return unequal;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if(rows != other.getRows() || columns != other.getColumns()) {
        return Matrix();
    } else {
        Matrix C = Matrix(rows, columns);
        if(C) {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    C.setValue(i, j, getValue(i, j) + other.getValue(i, j));
                }
            }
        }
        return C;
    }
}

Matrix Matrix::operator-(const Matrix& other) const {
    if(rows != other.getRows() || columns != other.getColumns()) {
        return Matrix();
    } else {
        Matrix C = Matrix(rows, columns);
        if(C) {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    C.setValue(i, j, getValue(i, j) - other.getValue(i, j));
                }
            }
        }
        return C;
    }
}

Matrix::operator bool() const {
    bool valid = true;
    if(rows <= 0 || columns <= 0) {
        valid = false;
    }
    return valid;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if(columns != other.getRows()) {
        return Matrix();
    } else {
        Matrix C = Matrix(rows, other.getColumns());
        if(C) {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < other.getColumns(); j++) {
                    for(int k = 0; k < other.getColumns(); k++) {
                        C.setValue(i, j, C.getValue(i, j) + matrix[i][k] * other.getValue(k, j));
                    }
                }
            }
        }
        return C;
    }
}

Matrix Matrix::operator*(double num) const {
    Matrix C = Matrix(rows, columns);
    if(C) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                C.setValue(i, j, matrix[i][j]*num);
            }
        }
    }
    return C;
}

Matrix operator*(double num, const Matrix& rhs) {
    Matrix C = Matrix(rhs.getRows(), rhs.getColumns());
    if(C) {
        for(int i = 0; i < rhs.getRows(); i++) {
            for(int j = 0; j < rhs.getColumns(); j++) {
                C.setValue(i, j, rhs.getValue(i, j)*num);
            }
        }
    }
    return C;
}

bool doublesEquals(double a, double b) {
    return (fabs(a-b) < DBL_EPSILON);
}

std::ostream& operator<<(std::ostream& out, const Matrix& rhs) {
    if(!rhs) {
        std::cout << "NOT A MATRIX" << std::endl;
    } else {
        for(int i = 0; i < rhs.getRows(); i++) {
            for(int j = 0; j < rhs.getColumns(); j++) {
                std::cout << rhs.getValue(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
    return out;
}