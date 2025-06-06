#ifndef STRING_HPP
#define STRING_HPP	

class String{
public:
	String();		// Default Constructor
	String(const char *);	// Parameterized Constructor

	~String();
	
	size_t Length() const;
	const char * Access() const;
	void Print() const;

private:
	char * m_data;
	size_t m_size;

};

#endif
