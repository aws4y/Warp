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


template <typename T> WarpImage<T>* WarpImage<T>::operator+(const WarpImage* im2)
{
	if (this.width != im2->getWidth())
		return NULL;
	else if (this.height != im2.height)
		return NULL;
	WarpImage *result;
	T *buffer;
	int length = width*height;
	buffer = new T[length];
	result = new WarpImage(this.data_type, this.width, this.height);
	for (int i = 0; i < length; i++)
		buffer[i] = this.data[i] + im2.data[i];
	result.setData(buffer);
	result.appendMetadata(string("The result of adding ") + this.im_name+string(" and ")+im2.im_name)
	return result;
	
}

template <class T> void WarpImage<T>::setData(void *buffer)
{
	switch (data_type)
	{
		if (this.data != NULL)
			delete this.data;
		this.data = (T)buffer;

	}
}