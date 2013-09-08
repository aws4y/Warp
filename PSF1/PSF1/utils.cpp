//fucntions for computing image statistics in various formats.
#include <iostream>
#include "fftw3.h"
#include "fitsio.h"


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