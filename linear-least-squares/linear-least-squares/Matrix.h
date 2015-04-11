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
	Matrix *rref();
const double get_element(int, int);
const int get_rows();
const	int get_columns();
void swap_rows(int i, int j)
{
	double *temp;
	if (i >= rows || j >= rows)
		return;
	temp = matrix[i];
	matrix[i] = matrix[j];
	matrix[j] = temp;
}
void row_scalar(int i, double s)
{
	if (i >= rows)
		return;
	else
		for (int k = 0; k < columns; k++)
			matrix[i][k] *= s;
}
void row_multiply_add(int i, int j, double s)
{
	if (i >= rows || j >= rows)
		return;
	else
		for (int k = 0; k < columns; k++)
			matrix[j][k] += s*matrix[i][k];
}
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
	if (i >= rows|| j >= columns)
		return 0.0;
	return matrix[i][j];
}

void Matrix::set_element(int i, int j, double val)
{
	if (i >= rows || j >= columns)
		return;
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

Matrix * Matrix::rref()
{
	Matrix *result;
	int i=0;
	result = this;
	int l = 0;
	for (int r = 0; r < rows; r++)
	{
		if (columns <= l)
			break;
		i = r;
		while (matrix[i][l] == 0)
		{
			i++;
			if (i == rows)
			{
				i = r;
				l++;
				if (columns == l)
					break;
			}
		}
		result->swap_rows(i, r);
		if (result->matrix[r][l] != 1)
			result->row_scalar(r, 1.0 / (result->matrix[r][l]));
		for (i = 0; i < rows; i++)
		{
			if (i != r)
				result->row_multiply_add(r, i, -1.0*result->matrix[i][l]);
		}
		l++;
	}
	return result;
}
#endif