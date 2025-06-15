#ifndef STRING_HPP
#define STRING_HPP	

class String{
public:
	String();		// Default Constructor
	String(const char *);	// Parameterized Constructor

	~String();

	String(const String&);
	String& operator=(const String&);

	String(String&&);
	String& operator=(String&&);
	
	size_t Length() const;
	const char * Access() const;
	void Print() const;

	friend String operator+(const String&, const String&);
	friend String operator+(const String&, const char*);
	friend String operator+(const char*, const String&);
	
	friend std::ostream& operator<<(std::ostream &, const String&);

private:
	size_t m_size;
	char * m_data;
};

#endif
