#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
class Matrix
{
private: 
	double **matrix;
	int rows;
	int columns;
public:
	Matrix();
	Matrix(int r, int c);
	~Matrix();
	void display();
	void input();
	Matrix * Trans();
	Matrix & operator=(Matrix *);
	Matrix & operator* (Matrix *);
	Matrix * Mult(Matrix *lhs, Matrix *rhs);
	void set_element(int, int, double);
const double get_element(int, int);
const int get_rows();
const	int get_columns();
};

const int Matrix::get_rows()
{
	return rows;
}
const int Matrix::get_columns()
{
	return columns;
}
const double Matrix::get_element(int i, int j)
{
	return matrix[i][j];
}

void Matrix::set_element(int i, int j, double val)
{
	matrix[i][j] = val;
}
Matrix::Matrix()
{
	rows = 0;
	columns = 0;
	matrix = nullptr;
}

Matrix::Matrix(int r, int c)
{
	rows = r;
	columns = c;
	matrix = new double *[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new double [columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = 0;
}

void Matrix::display()
{
	for (int i = 0; i < rows; i++)
	{
		cout << "|\t";
		for (int j = 0; j < columns; j++)
			cout << matrix[i][j] << "\t";
		cout <<"|"<< endl;
	}
	cout << endl;
}

void Matrix::input()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> matrix[i][j];
		}

	}

}
Matrix:: ~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete [] matrix;
}
Matrix * Matrix::Trans()
{
	Matrix *transpose;
	transpose = new Matrix(columns, rows);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			transpose->set_element(j, i, matrix[i][j]);
	return transpose;
}

Matrix & Matrix::operator=(Matrix *orig)
{
	if (matrix != nullptr)
	{
		delete matrix;
	}

	rows = orig->get_rows();
	columns=orig->get_columns();
	for (int i = 0; i < rows; i++)
		matrix[i] = new double[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = orig->get_element(i,j);
	return *this;
}

Matrix & Matrix::operator*(Matrix * rhs )
{
	double sum;
	Matrix *result;
	if (columns != rhs->get_rows())
	{
		rows = 0;
		columns = 0;
		matrix = nullptr;
		return *this;
	}
	result = new Matrix(rows, rhs->get_columns());
	for (int i = 0; i < rows - 1; ++i)
	{
		for (int j = 0; j < rhs->get_columns() - 1; ++j)
		{
			sum = 0;
			for (int k = 0; k < rhs->get_rows() - 1; ++k)
			{
				sum+= matrix[i][k] * rhs->get_element(k,j);
			}

			result->set_element(i,j,sum);
		}
	}
	return *result;
}


#endif