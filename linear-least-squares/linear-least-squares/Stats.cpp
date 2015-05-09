#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "Stats.h"

using namespace std;

#ifndef _MSC_VER
#define nullptr 0x0
#endif

double mean(double *data, unsigned int N)
{
	double mu = 0.0;
	for (unsigned int i = 0; i < N; i++)
		mu += data[i];
	return mu / (double)N;
}
	
double SST(const double *data, double mu, unsigned int N)
{
	double sst = 0.0;
	for (unsigned int i = 0; i < N; i++)
		sst += (data[i] - mu)*(data[i] - mu);
	return sst;
}

double SSE(Poly *poly, const double *x_i, double mu, unsigned int N)
{
	double sse = 0.0;
	for (unsigned int i = 0; i < N; i++)
	{
		sse += (poly->val(x_i[i]) - mu)*(poly->val(x_i[i]) - mu);
	}
	return sse;
}

Matrix * construct_normal(Matrix *XTX, Matrix *XTy)
{
	Matrix *normal;
        if(XTX->Det()==0.0 || isnan(XTX->Det()))
        {
            return nullptr;
        }
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

