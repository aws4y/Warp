#ifndef MATRIX_H
#define MATRIX_H

template <class T> class Matrix
{
private: 
	T *matrix;
	int rows;
	int columns;
public:
	Matrix();
	Matrix(int r, int c);
	~Matrix();

	T operator()(int i, int j);
	Matrix operator=(Matrix);

};

template <class T> Matrix<T>::Matrix()
{
	rows = 0;
	columns = 0;
	matrix = nullptr;
}

template <class T> Matrix<T>::Matrix(int r, int c)
{
	rows = r;
	columns = c;
	matrix = new T[rows*columns];
}

template <class T> Matrix<T>:: ~Matrix()
{
	delete matrix;
}

#endif