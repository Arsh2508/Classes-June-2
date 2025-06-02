#include <iostream>
#include "Matrix.hpp"

Matrix::Matrix() : rows_{}, cols_{} {
	data_ = nullptr;
	std::cout<<"Default ctor"<<std::endl;
}

Matrix::Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols){
	data_ = new double *[rows_];
	
	for(size_t i = 0; i < rows_; ++i){
		data_[i] = new double[cols_];
	}
	std::cout<<"Param ctor"<<std::endl;
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
	for(int i = 0; i < rows_; ++i){
		for(int j = 0; j < cols_; ++j){
			std::cout<<data_[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
//	std::cout<<std::endl;
}

void Matrix::input(){
	for(int i = 0; i < rows_; ++i){
		for(int j  = 0; j < cols_; ++j){
			std::cin>>data_[i][j];
		}
	}
}


