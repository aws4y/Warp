#include "Warp.h"

template <T> WarpImage<T>::WarpImage(data_t dataType, int width, int height)
{
	this.data_type = dataType;
	this.width = width;
	this.height = height;
	data = new T[width*height];
}

