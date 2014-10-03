#pragma once

#ifndef WARP_GLOBAL_H
#define WARP_GLOBAL_H
#ifndef NULL
#define NULL 0
#endif
enum data_t { UCHAR, USHORT, UINT, FLOAT, DOUBLE, LONG, SHORT, INT };
typedef struct 
{
	int d;
	int m;
	float s;
}coord;

#endif