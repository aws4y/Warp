#ifndef POLY_H
#define POLY_H 

class Poly
{
private:
	unsigned int d;
	double *coeff;
public:
	Poly();
	Poly(unsigned int);
	Poly(unsigned int, double *);
	double val(const double x);
	void set_coeff(double *, unsigned int);
	double get_coeff(unsigned int);
};

#endif