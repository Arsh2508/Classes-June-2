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
	
	Matrix obj2(obj);

	Matrix Sum = obj2 + obj + 3;
	Sum.print();
	
	std::cout<<Sum << obj;

	return 0;

}
