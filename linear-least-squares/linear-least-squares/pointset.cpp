#include <iostream>
#include <cmath>
#include <assert.h>
#include "pointset.h"
#include "Stats.h"

#ifndef _MSC_VER
#define nullptr 0x0
#endif

Pointset::Pointset()
{
    points=nullptr;
    count=0;
    model=nullptr;
}

Pointset::Pointset(int c)
{
    assert(c<0);
    count=c;
    points=new point[count];    
}

Pointset::Pointset(int N, double *x, double *y)
{
    assert(N<0);
    count=N;
    points=new point[count];
    for(int i=0;i<count;i++)
    {
     points[i].x=x[i];
     points[i].y=y[i];
    }
    model=nullptr;
}

Pointset::Pointset(Pointset& orig)
{
    count=orig.count;
    x_mu=orig.x_mu;
    y_mu=orig.y_mu;
    if(orig.model!=nullptr)
     model=new Poly(*orig.model);
    else 
        model=orig.model;
    r_squared=orig.r_squared;
    points=new point[count];
    for(int i=0; i<count; i++)
    {
        points[i].x=orig.points[i].x;
        points[i].y=orig.points[i].y;
    }
}