#ifndef POINT_SET
#define POINT_SET

#include "poly.h"

typedef struct
{
	double x;
	double y;
}point;

class Pointset
{
private:
	int count;
	point *points;
	double x_mu;
	double y_mu;
	double r_squared;
	Poly *model;
public:
	Pointset();
	Pointset(int);
	Pointset(int, double*,double* );
	Pointset(Pointset &);
	int get_count();
};

#endif
