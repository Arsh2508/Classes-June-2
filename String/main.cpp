#include <iostream>
#include "String.hpp"

int main()
{
	String obj("Hello World");
	
	obj.Print();
	std::cout<<"Length: "<<obj.Length()<<std::endl;
	std::cout<<"Access: "<<obj.Access()<<std::endl;

	
	String obj1 = obj + " " + "object 1";
	String obj2 = "object 2 " + obj;

	obj1.Print();
	obj2.Print();
	String obj3 = obj2 + obj1;
	obj3.Print();

	return 0;

}
