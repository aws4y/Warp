#include "Warp.h"

template <typename VTYPE> WarpImage<VTYPE>::WarpImage(data_t dataType, int width, int height)
{
	this.data_type = dataType;
	this.width = width;
	this.height = height;
	data = new VTYPE[width*height];
	metadata = new vector < string > ;
}
template <typename VTYPE> WarpImage<VTYPE>::WarpImage(int new_width, int new_height, time_t utc, time_t local, vector<string> new_metadata, data_t dataType, void *buffer)
{
	this.data_type = dataType;
	this.width = new_width;
	this.height = new_height;
	this.metadata = &new_metadata;
	this.utc_time = utc;
	this.local_time = local;
	this.data = (VTYPE)buffer;
}

template <typename T> int WarpImage<T>::getHeight()
{
	return height;
}
template <typename T> int WarpImage<T>::getWidth()
{
	return width;
}

template <typename T> coord WarpImage<T>::getRA()
{
	return RA;
}
template <typename T> coord WarpImage<T>::getDEC()
{
	return DEC;
}
template <typename T> void WarpImage<T>::appendMetadata(string meta_string)
{
	metadata->push_back(meta_string);
}

template <typename T> void WarpImage<T>::setRA(int H, int M, float S)
{
	RA.d = H;
	RA.m = M;
	RA.s = S;
}

template <typename T> void WarpImage<T>::setDEC(int D, int M, float S)
{
	DEC.d = D;
	DEC.m = M;
	DEC.s = S;
}

template <typename T> WarpImage* WarpImage<T>::operator+(const WarpImage* im2)
{
	if (this.width != im2->getWidth())
		return NULL;
	else if (this.height != im2.height)
		return NULL;
	WarpImage *result;
	T *buffer;
	buffer = new T[width*height];
	result = new WarpImage(this.data_type, this.width, this.height)
		// I don't really know what I am doing

	}
}