#include <iostream>
#include "String.hpp"

int main()
{
	String obj("Hello World");
	
	obj.Print();
	std::cout<<"Length: "<<obj.Length()<<std::endl;
	std::cout<<"Access: "<<obj.Access()<<std::endl;

	String obj1(obj);
	obj1.Print();

	String obj2("Another String");
	obj2.Print();
	obj2 = obj1;
	obj2.Print();

	String mv_obj(std::move(obj2));
	mv_obj.Print();

	String mv_obj2;
	mv_obj2 = std::move(mv_obj);
	mv_obj2.Print();

	return 0;

}
