#include "Stats.h"
#include "poly.h"
#ifndef _MSC_VER
#define nullptr 0x0
#endif
double mean(double *data, unsigned int N)
{
	double mu = 0.0;
	for (int i = 0; i < N; i++)
		mu += data[i];
	return mu / (double)N;
}
	
double SST(const double *data, double mu, unsigned int N)
{
	double sst = 0.0;
	for (int i = 0; i < N; i++)
		sst += (data[i] - mu)*(data[i] - mu);
	return sst;
}

double SSE(const double *poly, const double *x_i, double mu, unsigned int N, unsigned int k)
{
	double sse = 0.0;
	//include this code eventually
	return sse;
}

