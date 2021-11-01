#pragma once
#include "std_lib_facilities.h"

class Matrix{
private:
    int columns;
    int rows;
    double** matrix1;


public:
    Matrix();
    Matrix(int columns, int rows);
    explicit Matrix(int rows1);
    Matrix(const Matrix &other); //kopikonstruktør
    ~Matrix();
    double get(int row, int col) const;
    void set(int row, int col, double value);
    friend ostream& operator<<(ostream& os, const Matrix& M);
    int getRows() const{return rows;}
    int getColumns() const{return columns;}
    bool isValid() const{if(matrix1!=nullptr){return true;}return false;}
    Matrix& operator=(Matrix rhs);
    Matrix operator+=(const Matrix& rhs);
    Matrix operator+(const Matrix& rhs)const;
    //double getMatrix() const {return **matrix1;}
};
