#include "Warp.h"




template <class T> WarpImage<T> *sub_add(WarpImage<T> *im1, WarpImage<T> *im2, int width, int length, int x, int y)
{
	WarpImage <T> *result;
	
	return result;
}

template<class T>
WarpImage<T>* sub_subtract(WarpImage<T>* im1, WarpImage<T>* im2, int length, int width, int x, int y)
{
	return nullptr;
}

template <class T> void rotate(WarpImage<T> *im, float rotation)
{

}

template <class T> WarpImage <T> * create_stack(int size)
{
	return (WarpImage <T> *)calloc(size, sizeof(WarpImage<T>)a);
}

void warp_plugin_load(char * plug_file_name)
{
}
