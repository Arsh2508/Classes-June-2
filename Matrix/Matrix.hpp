#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix{
public:
	Matrix();

	Matrix(size_t, size_t);

	~Matrix();

	void set(size_t, size_t, double);
	double get(size_t, size_t) const;
	size_t getRows() const;
	size_t getCols() const;
	void print() const;

	void input();

private:
	size_t rows_;
	size_t cols_;
	double ** data_;
};

#endif
