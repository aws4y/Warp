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
#include "stats.h"
using namespace std;

int checkflag(int flag)
{
	char message[81];					
	if(flag !=0)
	{
		ffgerr(flag,message);
		cout<<message<<endl;
		return TRUE;
	}
	return FALSE;
}


int main(void)
{
	double in=22;
	double out;

	fitsfile *image;
	
	int bitpix,naxis,maxdim=2,anynull,nulval;
	long naxes[2];
	int length;
	float *data;
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
	data=(float *) calloc(length,sizeof(float));  
	img_fft=(fftw_complex *)calloc(length,sizeof(fftw_complex));
	image_plan=fftw_plan_dft_r2c_2d(naxes[1],naxes[0],(double *)data,img_fft,FFTW_ESTIMATE);
	flag=fits_read_img(image, TFLOAT,1,length,&nulval,data,&anynull,&flag); //attempting to read the pixel data
	if(checkflag(flag))
		return 1;
	cout<<"Image Mean: "<<mean_float(data,length)<<endl;
	fftw_execute(image_plan);
	cout<<"Image Mean after FFT: "<<mean_float(data,length)<<endl;
	
	if(data !=NULL)
		free(data);
	if(img_fft!=NULL)
		free(img_fft);
	flag=fits_close_file(image,&flag);
	if(checkflag(flag))
		return 1;
	system("pause");
	
	return 0;
}