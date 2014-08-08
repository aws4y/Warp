#pragma once
#ifndef WARP_IMAGE_H
#define WAPR_IMAGE_H
#include <vector>
#include <time.h>
#include "Warp_Global.h"
using namespace std;

template <typename VTYPE> class WarpImage{
private:
	VTYPE *data;
	int width; //Image width
	int height; //Image height
	time_t utc_time; // UTC time the image was taken
	time_t local_time; // Local time at which the image was taken
	coord RA;   //RA coordinate for the image center
	coord DEC;  //Dec Coordinate for the image center
	vector <string> *metadata;
	data_t data_type;
	char *file_name;
public:
	WarpImage(data_t,int,int);
	WarpImage(int,int,time_t,time_t, vector<string> metadata, data_t, void *);
	int getWidth();
	int getHeight();
	coord getRA();
	coord getDEC();
	void setRA(int, int, float);
	void setDEC(int, int, float);
	void appendMetadata(string);
	char *getFile_name();
	WarpImage<VTYPE>* operator +(const WarpImage *);  //in place (i.e. no transalation) addition of images only works for images of the same size 
	WarpImage<VTYPE>* operator -(const WarpImage *);  // in place subtraction of images of the same size, NULL otherwise;
	WarpImage<double>* operator *(const double);        //scalar multiplication of images, type cast to whatever the image is
	WarpImage<double>* operator / (const WarpImage *);
	~WarpImage();
	
};
#endif