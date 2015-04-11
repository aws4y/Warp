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
	XTX =Mult(XT, X);
	XTX->display();
	cout << "X transpose y:" << endl;
	XTy = Mult(XT, y);	
	XTy->display();
	normal = construct_normal(XTX, XTy);
	cout << "Normal Equations: " << endl;
	normal->display();
	cout << "rref Normal system: " << endl;
	solution = normal->rref();
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

