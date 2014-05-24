//fucntions for computing image statistics in various formats.
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "fftw3.h"
#include "fitsio.h"
#include "utils.h"

using namespace std;

float mean_float(float *data,int length)
{
	double sum=0;
	for(int i=0;i<length;i++)
	{
		sum+=(double) data[i];
	}
	return (float)(sum/(double) length);
}

double mean_double(double *data,int length)
{
	double sum=0;
	for(int i=0;i<length;i++)
	{
		sum+=(double) data[i];
	}
	return (float)(sum/(double) length);
}

void float_to_complex(float *data, fftw_complex *fftw_data, int length)
{
	for(int i=0; i<length; i++)
		fftw_data[i][0]=(float) data[i];
}

int checkflag(int flag)
{
	char message[81];					
	if(flag !=0)
	{
		ffgerr(flag,message);
		std::cout<<message<<std::endl;
		return TRUE;
	}
	return FALSE;
}

double real_mean(fftw_complex *data, int length)
{
	int i;
	double mean=0;
	for(i=0; i<length; i++)
		mean=data[i][0];
	return mean/(float) length;
}

double imaginary_mean(fftw_complex *data, int length)
{
	int i;
	double mean=0;
	for(i=0; i<length; i++)
		mean+=data[i][1];
	return mean/(float) length;
}

void float_to_long_double(float *data, long double *out, int length)
{ 
	int i;
	for(i=0;i<length;i++)
	{
		out[i]=(long double) data[i];
	}
}

long double mean_long_double(long double *data, int length)
{
	int i;
	long double mean=0;
	for (i=0; i< length; i++)
	{
	 mean +=data[i];
	}
	return mean/(long double) length;
}

void float_to_double(float *data, double *out, int length)
{
	int i;
	for(i=0; i<length; i++)
		out[i]=(double) data[i];

}

float background_v_float(float *data, int length)
{
	float background;
	float sigma=1;
	float sigma_old=0;
	float mean, median;
	vector <float> b_set(data,data+length);
	int i, j;
	bool sk_median_found = false;
	for (i = 0; i < length; i++)
	{
		b_set[i] = data[i];
	}
	mean = mean_float(data, length);
	sigma_old = sigma_float(data, mean, length);
	while (!sk_median_found)
	{
		mean = mean_float(b_set.data(), b_set.size());

	}
	if (((sigma - sigma_old) / sigma) < 0.2)
		return mean;

	background = (float) 2.5*median - (float)1.5*mean_float(data, length);

	return background;
}

float median_float(float *data, int length) //median of medians
{
	
}

float sigma_float(float *data, float m, int length)
{
	float sum = 0.0;
	for (int i = 0; i < length; i++)
	{
		sum += (data[i] - m)*(data[i] - m);
	}
	sum = sum / length;
	return sqrt(sum);
}