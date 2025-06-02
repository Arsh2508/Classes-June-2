#include <iostream>
#include "Matrix.hpp"

int main()
{
	size_t rows;
	size_t cols;
	std::cout<<"Enter rows: ";
	std::cin>>rows;
	std::cout<<"Enter cols: ";
	std::cin>>cols;

	Matrix obj(rows, cols);

	obj.input();
	
	size_t row = 0;
	size_t col = 0;
	double val = 0;
	std::cout<<"Enter position and value to set\n";
	std::cout<<"Row - ";
	std::cin>>row;
	std::cout<<"Col - ";
	std::cin>>col;
	std::cout<<"Value - ";
	std::cin>>val;
	
	obj.set(row, col, val);

	std::cout<<"Enter position to get value\n";
	std::cout<<"Row - ";
    std::cin>>row;
    std::cout<<"Col - ";
    std::cin>>col;
	
	std::cout<<"The value is "<<obj.get(row, col)<<"\n\n";


	obj.print();

	return 0;

}
