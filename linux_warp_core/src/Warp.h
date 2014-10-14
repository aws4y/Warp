#pragma once
#ifndef WARP_H
#define WARP_H

#include "Warp_Global.h"
#include "Warp_Image.h"
#include "Warp_Device.h"

void warp_plugin_load(char *plug_file_name);
template <class T> WarpImage<T> *sub_add(WarpImage<T>* im1, WarpImage<T> *im2, int length, int width, int x, int y); //adding subsets of images
template <class T> WarpImage<T> *sub_subtract(WarpImage<T>* im1, WarpImage<T> *im2, int length, int width, int x, int y); //adding ub images
template <class T> WarpImage<T> * rotate(WarpImage<T> *im, float r); //returns an image that is a rotation of r radians of im 
template <class T> WarpImage<T> * create_stack(int size); // Construct an image stack area from heap memory
template <class T> void destroy_stack(WarpImage<T> *stack, int stack_size); //unwind the stack of images
template <class T> WarpImage<T>* translate(WarpImage<T> *im, int x, int y); //returns a translation of im by the vector <x,y>


#endif