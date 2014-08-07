#pragma once
#ifndef WARP_IMAGE_H
#define WAPR_IMAGE_H
#include <vector>
#include <time.h>
#include "Warp.h"
using namespace std;

template <T> class WarpImage {
private:
	vector <T> *data;
	int width; //Image width
	int height; //Image height
	time_t utc_time; // UTC time the image was taken
	time_t local_time; // Local time at which the image was taken
	vector <string> *metadata;
	data_t data_type;
public:
	WarpImage(data_t);
	WarpImage(int,int,time_t,time_t, vector<string> metadata, data_t, void *);

};
#endif