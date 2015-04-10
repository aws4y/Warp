#include "Warp.h"




template <class T> WarpImage<T> *sub_add(WarpImage<T> *bottom, WarpImage<T> *top, int width, int length, int x, int y)
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

template <class T> void destroy_stack(WarpImage<T> *stack,int stack_size) //unwind the stack of images
{
    for(int i=0; i<stack_size; i++ )
        delete stack[i];
    delete stack;
}

template <class T> WarpImage<T>* translate(WarpImage<T> *im, int x, int y) //returns a translation of im by the vector <x,y>
{
    return im;
}