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
#include "utils.h"
using namespace std;




int main(void)
{
	double in=22;
	double out;

	fitsfile *image;
	
	int bitpix,naxis,maxdim=2,anynull,nulval;
	long naxes[2];
	int length;
	int sign=0;
	unsigned int flags=0;
	fftw_complex *data;
	float *l_data;
	fftw_plan image_plan;
	int flag=0; // Flag takes the place of status from CFITSIO documentation
	fftw_complex *img_fft;
	
	flag=ffopen(&image,"noise.fts",0,&flag); //noise.fts is the 4 second dark frame.
	if(checkflag(flag))
		return 1;

	flag=fits_get_img_param(image,maxdim, &bitpix,&naxis, naxes, &flag);
	if(checkflag(flag))
		return 1;

	cout<<"BITPIX: "<<bitpix<<endl;
	cout<<"NAXIS: "<<naxis<<endl;
	cout<<"Image Dimesions: "<<naxes[1]<<"x"<<naxes[0]<<endl;
	length=naxes[0]*naxes[1];
	l_data=(float *)calloc(length, sizeof(float));
	data=fftw_alloc_complex(sizeof(fftw_complex)*naxes[0]*naxes[1]);
	img_fft=fftw_alloc_complex(sizeof(fftw_complex)*naxes[0]*naxes[1]);
	image_plan=fftw_plan_dft_2d(naxes[0],naxes[1],data,img_fft,sign,flags);
	flag=fits_read_img(image, TFLOAT,1,length,&nulval,(void *)l_data,&anynull,&flag); //attempting to read the pixel data
	if(checkflag(flag))
		return 1;

	cout<<"Image mean: "<<mean_float(l_data,length)<<endl; 
	float_to_complex(l_data,data, length);
	fftw_execute(image_plan);

	cout<<"Real Mean: "<<real_mean(img_fft,length)<<endl;
	cout<<"Imaginary Mean: "<<imaginary_mean(img_fft,length)<<endl; 

	
	if(data !=NULL)
		fftw_free(data);
	if(img_fft!=NULL)
		fftw_free(img_fft);
	free(l_data);
	flag=fits_close_file(image,&flag);
	if(checkflag(flag))
		return 1;
	system("pause");
	
	return 0;
}