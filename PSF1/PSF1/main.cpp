/*****************************************************
*Name: PSF1 (Ex.WARP.1)
*Author: Aaron (Ron) Smith
*Project: Warp experiment 1 The goal of PSF1 is to implement the Alard-Lupton method for generating the PSF of two fits images 
*this experiment will also use FFTW to generate a "noisy" PSF image.
******************************************************/
#include <iostream>
#include "fitsio.h"
#include "fftw3.h"
#include "defines.h"
using namespace std;

int main(void)
{
	double in=22;
	double out;

	fitsfile *image;
	char message[81];
	int bitpix,naxis,maxdim=2;
	long naxes[2];
	long length;
	int flag=0; // Flag takes the place of status from CFITSIO documentation
	
	flag=ffopen(&image,"noise.fts",0,&flag); //noise.fts is the 4 second dark frame.
	if(flag==0)
	{
		fits_get_img_param(image,maxdim, &bitpix,&naxis, naxes, &flag);
		cout<<"MAXDIM: "<<maxdim<<endl;
		cout<<"BITPIX: "<<bitpix<<endl;
		cout<<"NAXIS: "<<naxis<<endl;
		cout<<"Image Dimesions: "<<naxes[1]<<"x"<<naxes[0]<<endl;
		
	}
	else 
	{
		ffgerr(flag,message);
		cout<<message<<endl;
	}
	
	fits_close_file(image,&flag);
	system("pause");
	
	return 0;
}