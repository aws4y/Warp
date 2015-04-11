#include "Matrix.h"

Matrix * Mult(Matrix *lhs, Matrix *rhs)
{
	double sum;
	Matrix *result;
	if (lhs->get_columns() != rhs->get_rows())
	{
		result = new Matrix();
		return result;
	}
	result = new Matrix(lhs->get_rows(), rhs->get_columns());
	for (int i = 0; i < result->get_rows(); i++)
	{
		for (int j = 0; j < result->get_columns(); j++)
		{
			sum = 0;
			for (int k = 0; k < lhs->get_columns(); k++)
			{
				sum += lhs->get_element(i, k)*rhs->get_element(k, j);
			}
			result->set_element(i, j, sum);
		}
	}
	return result;
}

int main(void)
{
	int n, N;
	Matrix *X;
	Matrix *XT;
	Matrix *XTX;
	Matrix *y;
	Matrix *XTy;
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
	XTX =Mult(XT, X);
	XTX->display();
	cout << "X transpose y:" << endl;
	XTy = Mult(XT, y);	
	XTy->display();
	delete X;
	delete XT;
	delete XTX;
	delete y;
	delete XTy;
	cin.get();
	cin.get();
	return 0;
}