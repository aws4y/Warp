#include <iostream>
#include <assert.h>
#include "Matrix.h"
using namespace std;

#define DEBUG

Matrix * construct_normal(Matrix *, Matrix *);
void print_solution(Matrix *);
int main(void)
{
	int n, N;
	Matrix *X;
	Matrix *XT;
	Matrix *XTX;
	Matrix *y;
	Matrix *XTy;
	Matrix *normal;
	Matrix *solution;
	cout << "Number of unknowns: ";
	cin >> n;
	cout << "Number of Equations:";
	cin >> N;
	X = new Matrix (N, n);
	y = new Matrix(N, 1);
	cout<< "Input coeffecient matrix:" << endl;
	X->input();
	cout << "Input equvalent vector:" << endl;
	y->input();
	X->display();
	XT = X->Trans();
	cout << "X transpose X:" << endl;
	XTX = new Matrix();
	(*XTX) =((*XT)*(*X));
	XTX->display();
	cout << "X transpose y:" << endl;
	XTy = new Matrix();
	*XTy =(*XT)*(*y);	
	XTy->display();
	normal = construct_normal(XTX, XTy);
	cout << "Normal Equations: " << endl;
	normal->display();
	cout << "rref Normal system: " << endl;
	solution=normal->rref();

	solution->display();
	print_solution(solution);
	delete X;
	delete XT;
	delete XTX;
	delete y;
	delete XTy;
	delete normal;
	delete solution;
	cin.get();
	cin.get();
	return 0;
}

Matrix * construct_normal(Matrix *XTX, Matrix *XTy)
{
	Matrix *normal;
	normal = new Matrix(XTX->get_rows(), XTX->get_columns() + 1);
	for (int i = 0; i < XTX->get_rows(); i++)
		for (int j = 0; j < XTX->get_columns(); j++)
		{
		normal->set_element(i, j, XTX->get_element(i, j));
		}
	for (int k = 0; k < XTX->get_rows(); k++)
	{
		normal->set_element(k,XTX->get_columns(), XTy->get_element(k, 0));
	}
	return normal;
}
void print_solution(Matrix *soln)
{

	cout << "Candiate linear least squares fit:" << endl;
	for (int i = 0; i < soln->get_rows(); i++)
	{
		cout << "x" << i+1 << ": " << soln->get_element(i, soln->get_columns() - 1) << endl;
	}
	cout << endl;
}

