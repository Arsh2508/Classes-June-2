#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix{
public:
	Matrix();

	Matrix(size_t, size_t);
	~Matrix();

	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);

	Matrix(Matrix&&);
	Matrix& operator=(Matrix&&);

	void set(size_t, size_t, double);
	double get(size_t, size_t) const;
	size_t getRows() const;
	size_t getCols() const;
	void print() const;
	void input();

	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator+(const Matrix&, double);
	friend Matrix operator+(double, const Matrix&);

	friend std::ostream& operator<<(std::ostream &, const Matrix&);

	Matrix& operator++();
	const Matrix operator++(int);

private:
	size_t rows_;
	size_t cols_;
	double ** data_;
};

#endif
