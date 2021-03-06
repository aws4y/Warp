#ifndef POLY_H
#define POLY_H 

double n_pow(double b, unsigned int N);

class Poly
{
private:
	unsigned int d;
	double *coeff;
public:
	Poly();
	Poly(unsigned int);
	Poly(unsigned int, double *);
        Poly(const Poly &);
	double val(const double x);
        ~Poly();
	void set_coeff(const double, unsigned int);
	double get_coeff(unsigned int);
        void print();
};

#endif