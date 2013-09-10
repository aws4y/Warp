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
	//double out;

	fitsfile *image;
	fitsfile *fft_image;
	
	int bitpix,naxis,maxdim=2,anynull,nulval;
	long naxes[2];
	long fpixel[2]={1,1};
	int length;
	int sign=0;
	unsigned int flags=0;
	double *data;
	float *l_data;
	fftw_plan image_plan;
	int flag=0; // Flag takes the place of status from CFITSIO documentation
	double *img_fft;
	
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
	data=(double *)fftw_malloc(naxes[0]*naxes[1]*sizeof(long double));
	img_fft=(double*)fftw_malloc(naxes[0]*naxes[1]*sizeof(long double));
	image_plan=fftw_plan_r2r_2d(naxes[0],naxes[1],data,img_fft,FFTW_REDFT10,FFTW_DHT,FFTW_ESTIMATE_PATIENT);
	flag=fits_read_img(image, TFLOAT,1,length,&nulval,(void *)l_data,&anynull,&flag); //attempting to read the pixel data
	if(checkflag(flag))
		return 1;

	cout<<"Image mean: "<<mean_float(l_data,length)<<endl; 
	float_to_double(l_data,data, length);
	fftw_execute(image_plan);
	fftw_destroy_plan(image_plan);
	fftw_cleanup();
	cout<<"FT mean: "<<mean_double(img_fft,length)<<endl;
	cout<<"FFT First Pixel:"<<img_fft[0]<<endl;
	cout<<"FFT last Pixel:"<<img_fft[length-1]<<endl;
	//write the FFT image
	flag=ffinit(&fft_image,"fft.fit",&flag);
	if(flag==FILE_NOT_CREATED)
	{
		system("del fft.fit");
		flag=0;
		flag=ffinit(&fft_image,"fft.fit",&flag);
	}

	if(checkflag(flag))
	{
		system("pause");
		return 1;
	}
	flag=ffcphd(image, fft_image,&flag);
	if(checkflag(flag))
		{
		system("pause");
		return 1;
	}
	int outpix=-64;
	flag=ffuky(fft_image,TINT,"BITPIX", &outpix,"",&flag);
	if(checkflag(flag))
		{
		system("pause");
		return 1;
	}
	/*flag=ffcrim(fft_image,-32,2,naxes,&flag);
	if(checkflag(flag))
	{
		system("pause");
		return 1;
	}*/
	flag=ffppx(fft_image,TDOUBLE,fpixel,length,img_fft, &flag);
	if(checkflag(flag))
	{
		system("pause");
		return 1;
	}

	cout<<"FFT image written."<<endl;
	if(data !=NULL)
		fftw_free(data);
	if(img_fft!=NULL)
		fftw_free(img_fft);
	free(l_data);
	flag=fits_close_file(image,&flag);
	if(checkflag(flag))
		return 1;
	flag=fits_close_file(fft_image,&flag);
	if(checkflag(flag))
		return 1;

	system("pause");
	
	return 0;
}