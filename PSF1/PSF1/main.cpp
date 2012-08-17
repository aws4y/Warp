/*****************************************************
*Name: PSF1 (Ex.WARP.1)
*Author: Aaron (Ron) Smith
*Project: Warp experiment 1 The goal of PSF1 is to implement the Alard-Lupton method for generating the PSF of two fits images 
*this experiment will also use FFTW to generate a "noisy" PSF image.
******************************************************/
#include <iostream>
#include "fitsio.h"
#include "fftw3.h"
using namespace std;

int main(void)
{
	double in=22;
	double out;
	fftw_plan dumb_plan;
	dumb_plan=fftw_plan_r2r_1d(1, &in, &out,FFTW_DHT,FFTW_ESTIMATE);
	fftw_execute(dumb_plan);
	cout<<out<<endl;
	system("pause");
	return 0;
}