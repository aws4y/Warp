
#include <iostream>
#include <iomanip>
#include "Matrix.h"

int Matrix::get_rows()
{
	return rows;
}
int Matrix::get_columns()
{
	return columns;
}
double Matrix::get_element(int i, int j)
{
	if (i >= rows || j >= columns)
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
		matrix[i] = new double[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = 0;
}
Matrix::Matrix(const Matrix & rhs)
{
	rows = rhs.rows;
	columns = rhs.columns;
	matrix = new double *[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new double[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = rhs.matrix[i][j];
}
void Matrix::display()
{
	cout << fixed << setprecision(6);
	for (int i = 0; i < rows; i++)
	{
		cout << "|\t";
		for (int j = 0; j < columns; j++)
			cout << matrix[i][j] << "\t";
		cout << "|" << endl;
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
	if (matrix == nullptr)
		return;
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
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

Matrix & Matrix::operator=(const Matrix &orig)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
	rows = orig.rows;
	columns = orig.columns;
	matrix = new double *[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = orig.matrix[i][j];
	return *this;
}

Matrix & Matrix::operator*=(const Matrix & rhs)
{
	double sum;
	Matrix *result;
	Matrix *old;
	old = this;
	result = new Matrix(this->rows, rhs.columns);
	for (int i = 0; i < result->rows; i++)
	{
		for (int j = 0; j < result->columns; j++)
		{
			sum = 0;
			for (int k = 0; k < this->columns; k++)
			{
				sum += this->matrix[i][k] * rhs.matrix[k][j];
			}
			result->matrix[i][j] = sum;
		}
	}
	delete old;
	return *result;
}

Matrix & Matrix::operator*(const Matrix &rhs)
{
	double sum;
	Matrix *result;
	result = new Matrix(this->rows, rhs.columns);
	for (int i = 0; i < result->rows; i++)
	{
		for (int j = 0; j < result->columns; j++)
		{
			sum = 0;
			for (int k = 0; k < this->columns; k++)
			{
				sum += this->matrix[i][k] * rhs.matrix[k][j];
			}
			result->matrix[i][j] = sum;
		}
	}
	return *result;
}

Matrix * Matrix::rref()
{
	Matrix *result;

	int i = 0;
	result = new Matrix();
	(*result) = (*this);
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

void Matrix::swap_rows(int i, int j)
{
	double *temp;
	if (i >= rows || j >= rows)
		return;
	temp = matrix[i];
	matrix[i] = matrix[j];
	matrix[j] = temp;
}

void Matrix::row_scalar(int i, double s)
{
	if (i >= rows)
		return;
	else
		for (int k = 0; k < columns; k++)
			matrix[i][k] *= s;
}
void Matrix::row_multiply_add(int i, int j, double s)
{
	if (i >= rows || j >= rows)
		return;
	else
		for (int k = 0; k < columns; k++)
			matrix[j][k] += s*matrix[i][k];
}

bool Matrix::is_empty()
{
	if (rows == 0 || columns == 0)
		return true;
	return false;
}

bool Matrix::is_square()
{
	if (rows == columns)
		return true;
	return false;
}

Matrix & Matrix::operator+=(const Matrix &rhs)
{
	if (rows != rhs.rows || columns != rhs.columns)
	{
		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
		delete[] matrix;
		rows = 0;
		columns = 0;
		return *this;
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] += rhs.matrix[i][j];
	return *this;
}

Matrix & Matrix::operator+(const Matrix &rhs)
{
	Matrix *result;
	
	if (rows != rhs.rows || columns != rhs.columns)
	{
		result = new Matrix();
		return *result;
	}
	result = new Matrix(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			(*result).matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
}