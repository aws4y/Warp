#pragma once

#ifndef WARP_GLOBAL_H
#define WARP_GLOBAL_H
#define NULL 0x0;
enum data_t { UCHAR, USHORT, UINT, FLOAT, DOUBLE, LONG, SHORT, INT };
typedef struct 
{
	int d;
	int m;
	float s;
}coord;

#endif