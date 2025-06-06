#include <iostream>
#include "String.hpp"

int main()
{
	String obj("Hello World");
	
	obj.Print();
	std::cout<<"Length: "<<obj.Length()<<std::endl;
	std::cout<<"Access: "<<obj.Access()<<std::endl;

	return 0;

}
