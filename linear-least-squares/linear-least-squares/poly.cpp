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
}

Poly::Poly(unsigned int deg, double *c)
{
	d = deg;
	coeff = new double[d];
	for (int i = 0; i < d; i++)
		coeff[i] = c[i];
}