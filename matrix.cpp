#include "matrix.h"

Matrix::Matrix(int columns, int rows):columns{columns},rows{rows}{
    matrix1 = new double*[rows];
    for(int i = 0; i < rows; i++) {
        matrix1[i] = new double[columns]{};       
    }
};
Matrix::Matrix(int rows):Matrix(rows,rows){
    for (int i = 0; i < rows; i++)
    {
        set(i,i,1);
    }
    
};
Matrix::Matrix() : matrix1{nullptr},columns{0},rows{0}{};


Matrix::~Matrix(){
    for (int i = 0; i < rows; i++) {
		delete[] matrix1[i];
		matrix1[i] = nullptr;
	}
	delete[] matrix1;
	matrix1 = nullptr;
}

double Matrix::get(int row,int col) const{
    if (this->isValid())
    {
        return matrix1[row][col];
    }   
}

void Matrix::set(int row,int col,double value){
    matrix1[row][col]=value;
}

ostream& operator<<(ostream& os, const Matrix& M){
    if(M.isValid()==false){
        os<< "Something wrong with matrix";
    }
    else{
    	for (int row = 0; row < M.rows; ++row) {

		    for (int column = 0; column < M.columns; ++column) {
			    os << M.get(row, column) << ' ';
		    }

	    }
    }
    

    return os;
}

Matrix::Matrix(const Matrix &rhs) : columns{rhs.columns},rows{rhs.rows},matrix1{ nullptr } {
    if(rhs.isValid()==false){return;}
    matrix1 = new double*[rows];
    for(int i = 0; i < rows; i++) {
        matrix1[i] = new double[columns]{};  
        for (int j = 0; j < columns; j++)
        {
            matrix1[i][j]=rhs.matrix1[i][j];
        }
             
    }
}
Matrix &Matrix::operator=(Matrix rhs) {
    swap(this->matrix1, rhs.matrix1); //swapper pekere
    swap(this->rows,rhs.rows);//swapper rows
    swap(this->columns,rhs.columns);//...
    return *this;
}

Matrix Matrix::operator+=(const Matrix& rhs) {
    if(this->isValid() && rhs.isValid() && this->rows==rhs.rows && this->columns==rhs.columns){
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                this->matrix1[i][j]+=rhs.matrix1[i][j];
            }
            
        }
        return *this; 
    }
    else
    {
        return Matrix{};
    }
    
}

Matrix Matrix::operator+(const Matrix& rhs)const{
    if(this->isValid() && rhs.isValid() && this->rows==rhs.rows && this->columns==rhs.columns){
        return Matrix{*this}+=rhs; //bruker += operatoren til å legge sammen to Matrix
    }
    else{
        return Matrix{};
    }
}
