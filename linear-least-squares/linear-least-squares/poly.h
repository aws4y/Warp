#ifndef POLY_H
#define POLY_H 

double n_pow(double b, unsigned int N)
{
	 
	double ans = 1;
	for (int i = 0; i < N; i++)
		ans *= b;
	return ans;
}

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