
/*
 * The purpose of this class is to contain a pointset and int polynomial regression.  
 * 
 */
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
	unsigned int count;
	point *points;
	double x_mu;
	double y_mu;
	double r_squared;
        double r;
	Poly *model;
public:
	Pointset();
	Pointset(int);
	Pointset(int, double*,double* );
	Pointset(Pointset &);
	int get_count();
        void build_model();
        double * X();
        double * Y();
        void print();
};

#endif
