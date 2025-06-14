#include <iostream>
#include "Matrix.hpp"

Matrix::Matrix() : rows_{}, cols_{}, data_{nullptr} {
	std::cout<<"Default ctor"<<std::endl;
}

Matrix::Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols), data_{new double*[rows]}{
	for(size_t i = 0; i < rows_; ++i){
		data_[i] = new double[cols_];
	}
	std::cout<<"Param ctor"<<std::endl;
} 

// copy constructor
Matrix::Matrix(const Matrix& other)
	: rows_{other.rows_}
	, cols_{other.cols_}
	, data_{nullptr}
{

	if(other.data_ == nullptr){
		return;
	}	

	data_ = new double*[rows_];

	for(size_t i = 0; i < rows_; ++i){
		data_[i] = new double[cols_];
	}

	for(size_t i = 0; i < rows_; ++i){
		for(size_t j = 0; j < cols_; ++j){
			data_[i][j] = other.data_[i][j];
		}
	}

	std::cout<<"Copy ctor"<<std::endl;
}

//copy assignment operator
Matrix& Matrix::operator=(const Matrix& other){
	if(this == &other){
		return *this;
	}

	if(data_){
		for(size_t i = 0; i < rows_; ++i){
			delete []data_[i];
		}
		delete []data_;
	}

	rows_ = other.rows_;
	cols_ = other.cols_;
	data_ = new double* [rows_];
	for(size_t i = 0; i < rows_; ++i){
		data_[i] = new double[cols_];
	}

	for(size_t i = 0; i < rows_; ++i){
		for(size_t j = 0; j < cols_; ++j){
			data_[i][j] = other.data_[i][j];
		}
	}

	return *this;

}

//move constructor
Matrix::Matrix(Matrix&& other) 
	: rows_{other.rows_}
	, cols_{other.cols_}
	, data_{other.data_}
{
	other.data_ = nullptr;
	other.rows_ = 0;
	other.cols_ = 0;
}

//move assignment operator
Matrix& Matrix::operator=(Matrix&& rhs){
	if(this == &rhs){
		return *this;
	}

	for(size_t i = 0; i < rows_; ++i){
		delete []data_[i];
	}
	delete []data_;
	
	rows_ = rhs.rows_;
	cols_ = rhs.cols_;
	data_ = rhs.data_;

	rhs.data_ = nullptr;
	rhs.cols_ = 0;
	rhs.rows_ = 0;

	return *this;
}

Matrix::~Matrix(){
	std::cout<<"Calling Destructor"<<std::endl;
	for(size_t i = 0; i < rows_; ++i){
		delete []data_[i];
	}
	delete []data_;
}

void Matrix::set(size_t row, size_t col, double value){
	if(row < rows_ && col < cols_ && row >= 0 && col >= 0){
		data_[row][col] = value;
	}
	else{
		std::cout<<"Invalid position"<<std::endl;
	}
}

double Matrix::get(size_t row, size_t col) const{
	if(row < rows_ && col < cols_ && row >= 0 && col >= 0){
		return data_[row][col];
	}
	else{
		std::cout<<"Invalid position"<<std::endl;
		return -1;
	}
}

size_t Matrix::getRows() const{
	return rows_;
}

size_t Matrix::getCols() const{
	return cols_;
}

void Matrix::print() const{
	for(size_t i = 0; i < rows_; ++i){
		for(size_t j = 0; j < cols_; ++j){
			std::cout<<data_[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

void Matrix::input(){
	for(size_t i = 0; i < rows_; ++i){
		for(size_t j  = 0; j < cols_; ++j){
			std::cin>>data_[i][j];
		}
	}
}


Matrix operator+(const Matrix& lhs, const Matrix& rhs){
	if(lhs.cols_ != rhs.cols_ || lhs.rows_ != rhs.cols_){
		return{};
	}

	Matrix tmp(lhs);
	
	for(size_t i = 0; i < tmp.rows_; ++i){
		for(size_t j = 0; j < tmp.cols_; ++j){
			tmp.data_[i][j] += rhs.data_[i][j];
		}
	}

	return tmp;

}

Matrix operator+(const Matrix& lhs, double val){
	Matrix tmp(lhs);
	
	for(size_t i = 0; i < tmp.rows_; ++i){
		for(size_t j = 0; j < tmp.cols_; ++j){
			tmp.data_[i][j] += val;
		}
	}
	return tmp;
}

Matrix operator+(double val, const Matrix rhs){
	return operator+(rhs, val);
}

std::ostream& operator<<(std::ostream &os, const Matrix& rhs){
    for(size_t i = 0; i < rhs.rows_; ++i){
        for(size_t j = 0; j < rhs.cols_; ++j){
            os << rhs.data_[i][j]<< ' ';
        }
        os<<std::endl;
    }
    return os;
}

Matrix& Matrix::operator++(){
	for(size_t i = 0; i < rows_; ++i){
		for(size_t j = 0; j < cols_; ++j){
        	++data_[i][j];
        }
    }
    return *this;
}   

const Matrix Matrix::operator++(int){
    Matrix tmp(*this);
        
	for(size_t i = 0; i < rows_; ++i){
        for(size_t j = 0; j < cols_; ++j){
            ++data_[i][j];
        }
    }

    return tmp;
}
