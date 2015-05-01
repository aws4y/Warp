#include <assert.h>
#include"poly.h"

Poly::Poly()
{
	d = 0;
	coeff = nullptr;
}

Poly::Poly(unsigned int deg)
{
	d = deg;
	coeff = new double[d];
	for (int i = 0; i < d; i++)
		coeff[i] = 0.0;
}

Poly::Poly(unsigned int deg, double *c)
{
	d = deg;
	coeff = new double[d];
	for (int i = 0; i < d; i++)
		coeff[i] = c[i];
}

double Poly::val(const double x)
{
	int sum = 0.0;
	for (int i = 0; i < d; i++)
		sum += coeff[i] * n_pow(x, i);
	return sum;
}

double Poly::get_coeff(unsigned int i)
{
	if (i > d)
		return 0.0;
	return coeff[i];
}

void Poly::set_coeff(const double c, unsigned int i)
{
	if (i > d)
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
	if (N = 0)
		return 1.0;

	for (int i = 0; i < N; i++)
		ans *= b;
	return ans;
}