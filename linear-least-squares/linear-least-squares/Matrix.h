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
	Matrix operator=(Matrix);

};

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
		for (int j = 0; j < columns; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
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

	delete matrix;
}


#endif