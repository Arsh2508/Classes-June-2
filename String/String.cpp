#include <iostream>
#include <cstring>
#include "String.hpp"

String::String(){
	m_size = 0;
	m_data = nullptr;
}

String::String(const char * src){
	if(src){
		m_size = std::strlen(src);
		m_data = new char[m_size + 1];
		for(size_t i = 0; i <= m_size; ++i){
			m_data[i] = src[i];
		}
	}
	else{
		m_size = 0;
		m_data = nullptr;
	}
}

//copy constructor
String::String(const String& other)
	: m_size{other.m_size}
	, m_data{nullptr}
{
	if(other.m_data == nullptr){
		return;
	}

	m_data = new char[m_size + 1];
	for(size_t i = 0; i <= m_size; ++i){
		m_data[i] = other.m_data[i];
	}
}

//copy assignment operator
String& String::operator=(const String& other){
	if(this == &other){
		return *this;
	}

	delete []m_data;
	
	m_size = other.m_size;
	m_data = new char[m_size + 1];

	for(size_t i = 0; i <= m_size; ++i){
		m_data[i] = other.m_data[i];
	}

	return *this;
}

String::~String(){
	delete []m_data;
}

//move constructor
String::String(String&& other)
	: m_size{other.m_size}
	, m_data{other.m_data}
{
	std::cout<<"move ctor\n";

	other.m_data = nullptr;
	other.m_size = 0;
}

//move assignment operator
String& String::operator=(String&& rhs){
std::cout<<"move assignment operator\n";
	if(this == &rhs){
		return *this;
	}

	delete []m_data;
	m_data = rhs.m_data;
	m_size - rhs.m_size;

	rhs.m_data = nullptr;
	rhs.m_size = 0;

	return *this;
}

size_t String::Length() const{
	return m_size;
}

const char * String::Access() const{
	return m_data;
}

void String::Print() const{
	std::cout<<m_data<<std::endl;
}


String operator+(const String& lhs, const String& rhs){
	
	String res;

	res.m_size = lhs.m_size + rhs.m_size;
	res.m_data = new char[res.m_size];
	
	for(size_t i = 0; i < lhs.m_size; ++i){
		res.m_data[i] = lhs.m_data[i];
	}

	for(size_t i = 0; i < rhs.m_size; ++i){
		res.m_data[rhs.m_size + i] = rhs.m_data[i];
	}

	res.m_data[res.m_size] = '\0';
	return res;

}
String operator+(const String& lhs, const char* rhs){
    String res;

	size_t rhs_size = strlen(rhs);

    res.m_size = lhs.m_size + rhs_size;
	res.m_data = new char[res.m_size + 1];

    for(size_t i = 0; i < lhs.m_size; ++i){
        res.m_data[i] = lhs.m_data[i];
    }

    for(size_t i = 0; i < rhs_size; ++i){
        res.m_data[i + lhs.m_size] = rhs[i];
    }

	res.m_data[res.m_size] = '\0';
    return res;

}

String operator+(const char* lhs, const String& rhs){
    String res;

	size_t lhs_size = strlen(lhs);
    res.m_size = rhs.m_size + lhs_size;
	res.m_data = new char[res.m_size + 1];

    for(size_t i = 0; i < lhs_size; ++i){
        res.m_data[i] = lhs[i];
    }

    for(size_t i = 0; i < rhs.m_size; ++i){
        res.m_data[lhs_size + i] = rhs.m_data[i];
    }
	
	res.m_data[res.m_size] = '\0';
    return res;

}












