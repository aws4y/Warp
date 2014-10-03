#include "Warp.h"




template <class T> WarpImage<T> *sub_add(WarpImage<T> *im1, WarpImage<T> *im2, int width, int length, int x, int y)
{
	WarpImage <T> *result;
	
	return result;
}

template <class T> void rotate(WarpImage<T> *im, float rotation)
{

}

template <class T> WarpImage <T> * create_stack(int size)
{
    WarpImage<T> *stack_ptr;
    stack_ptr=new WarpImage<T>[size];
    return stack_ptr;
}