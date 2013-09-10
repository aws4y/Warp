//The header for utils.cpp
#ifndef UTILS_H
#define UTILS_H 

//checks flags for cfitsio
int checkflag(int flag);

//Functions to copy data mostly used to move image data into FFTW compatible containers. 
void float_to_complex(float *data, fftw_complex *fftw_data, int length);
void float_to_long_double(float *data, long double *out, int length);
void float_to_double(float *data, double *out, int length);

//Functions to compute means in various formats used as a check
double real_mean(fftw_complex *data, int length);
double imaginary_mean(fftw_complex *data, int length);
long double mean_long_double(long double *data, int length);
float mean_float(float *data,int length);
double mean_double(double *data, int length);

#endif
