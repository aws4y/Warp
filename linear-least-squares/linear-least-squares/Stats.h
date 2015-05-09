#ifndef STATS_H
#define STATS_H
#include "poly.h"

double mean(const double *, unsigned int N);
double SST(const double *data, double mu, unsigned int N);
double SSE(const Poly *poly, const double *x_i, double mu, unsigned int N);
Matrix * construct_normal(Matrix *XTX, Matrix *XTy);
void print_solution(Matrix *soln);
#endif