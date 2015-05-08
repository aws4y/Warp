#include "Stats.h"

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

