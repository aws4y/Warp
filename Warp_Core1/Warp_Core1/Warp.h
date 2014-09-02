#pragma once
#ifndef WARP_H
#define WARP_H

#include "Warp_Global.h"
#include "Warp_Image.h"

void warp_plugin_load(char *plug_file_name);
template <class T> WarpImage<T> *sub_add(WarpImage<T>* im1, WarpImage<T> *im2, int length, int width, int x, int y); //adding subsets of images
template <class T> WarpImage<T> *sub_subtract(WarpImage<T>* im1, WarpImage<T> *im2, int length, int width, int x, int y); //adding sub images
template <class T> void rotate(WarpImage<T> *im, float rotation); //rotate an image representation in memory
#endif