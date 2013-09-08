//The header for stats.cpp
#ifndef UTILS_H
#define UTILS_H 
float mean_float(float *data,int length);
double mean_double(double *data, int length);
int checkflag(int flag);
void float_to_complex(float *data, fftw_complex *fftw_data, int length);
double real_mean(fftw_complex *data, int length);
double imaginary_mean(fftw_complex *data, int length);
#endif
