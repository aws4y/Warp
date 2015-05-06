#include <assert.h>
#include <iostream>

#include"poly.h"

using namespace std;

#ifndef _MSC_VER
#define nullptr 0x0
#endif
#define DEBUG

Poly::Poly()
{
	d = 0;
	coeff = nullptr;
}

Poly::Poly(unsigned int deg)
{
	d = deg;
	coeff = new double[d+1];
	for (int i = 0; i < d+1; i++)
		coeff[i] = 0.0;
}

Poly::Poly(unsigned int deg, double *c)
{
	d = deg;
	coeff = new double[d+1];
	for (int i = 0; i < d+1; i++)
        {
		coeff[i] = c[i];                  
        }
}

double Poly::val(const double x)
{
	double sum = 0.0;
	for (int i =0; i <d+1 ; i++)
        {     
            
		sum += coeff[i] * n_pow(x, d-i);
        }
	return sum;
}

double Poly::get_coeff(unsigned int i)
{
	if (i > d+1)
		return 0.0;
	return coeff[i];
}

void Poly::set_coeff(const double c, unsigned int i)
{
	if (i > d+1)
	{
		double *new_coeff;
		new_coeff = new double[i];
		for (int j = 0; j < i; j++)
			new_coeff[j] = 0.0;
		for (int j = 0; j < d; j++)
		{
			new_coeff[j] = coeff[j];
		}
		delete coeff;
		new_coeff[i - 1] = c;
		coeff = new_coeff;
	}
	coeff[i - 1] = c;
}

double n_pow(double b, unsigned int N)
{

	double ans = 1.0;
	if (N == 0)
		return 1.0;

	for (int i = 0; i < N; i++)
		ans *= b;
	return ans;
}