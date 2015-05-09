#include <iostream>
#include <cmath>
#include <assert.h>
#include "pointset.h"
#include "Matrix.h"
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

void Pointset::build_model(unsigned int d)
{
    	int n, N;
        Matrix *X;
	Matrix *XT;
	Matrix *XTX;
	Matrix *y;
	Matrix *XTy;
	Matrix *normal;
	Matrix *solution;
	cout << "Number of unknowns: ";
	cin >> n;
	cout << "Number of Equations:";
	cin >> N;
	X = new Matrix (N, n);
	y = new Matrix(N, 1);
	cout<< "Input coeffecient matrix:" << endl;
	X->input();
	cout << "Input equvalent vector:" << endl;
	y->input();
	X->display();
	XT = X->Trans();
	cout << "X transpose X:" << endl;
	XTX = new Matrix();
	(*XTX) =((*XT)*(*X));
	XTX->display();
	cout << "Determinant XTX: " << XTX->Det() << endl;
	cout << "X transpose y:" << endl;
	XTy = new Matrix();
	*XTy =(*XT)*(*y);	
	XTy->display();
	normal = construct_normal(XTX, XTy);
        if(normal!=nullptr)
        {
	cout << "Normal Equations: " << endl;
	normal->display();
	cout << "rref Normal system: " << endl;
	solution=normal->rref();
	solution->display();
	print_solution(solution);
        }
        else 
        {
            solution=nullptr;
            cout<<"There is no solution."<<endl<<endl;
        }
	delete X;
	delete XT;
	delete XTX;
	delete y;
	delete XTy;
        if(normal != nullptr)
        {
            delete normal;
            delete solution;
        }
       
}