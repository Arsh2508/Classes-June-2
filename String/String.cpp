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

String::~String(){
	delete []m_data;
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









