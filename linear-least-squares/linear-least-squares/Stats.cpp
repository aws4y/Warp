#include "Stats.h"
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
}

double n_pow(double b, unsigned int N)
{
	double ans=1;
	for (int i = 0; i < N; i++)
		ans *= b;
	return ans;
}