#include <iostream>
#include <cmath>
#include <assert.h>
#include "pointset.h"
#include "Matrix.h"
#include "Stats.h"

#ifndef _MSC_VER
#define nullptr 0x0
#endif
#define DEBUG

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
    assert(N>=0);
    count=N;
    points=new point[count];
    for(int i=0;i<count;i++)
    {
     points[i].x=x[i];
     points[i].y=y[i];
    }
    model=nullptr;
    x_mu=mean(x,(unsigned int)count);
    y_mu=mean(y,(unsigned int)count);
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

int Pointset::get_count()
{
	return count;
}

void Pointset::build_model()
{
    	int d;
        
        Matrix *X;
	Matrix *XT;
	Matrix *XTX;
	Matrix *y;
	Matrix *XTy;
	Matrix *normal;
	Matrix *solution;
        do
        {
        cout<<"Enter the degree of the model Polynomial: ";
        cin>>d;     
        if(d<0) cout<<"Degree must be greater than or equal to 1";
        }while(d<0);
	X = new Matrix (count, d+1);
	y = new Matrix(count, 1);
        for(unsigned int i=0;i<count;i++)
        {
            for(unsigned int j=0;j<d+1;j++)
            {
                X->set_element(i,j,n_pow(points[i].x,j));
            }
            y->set_element(i,0,points[i].y);
        }
        XT = X->Trans();
        XTX = new Matrix();
	(*XTX) =((*XT)*(*X));
        XTy = new Matrix();
	*XTy =(*XT)*(*y);	
	
#ifdef DEBUG
        cout<<"Coefficient Matrix: "<<endl;
        X->display();	
	cout << "X transpose X:" << endl;	
	XTX->display();
	cout << "Determinant XTX: " << XTX->Det() << endl;
	cout << "X transpose y:" << endl;
	XTy->display();
#endif
	normal = construct_normal(XTX, XTy);
        if(normal!=nullptr)
        {
            solution=normal->rref();
            double *coeffs;
            coeffs=new double[d+1];
            for(int i=0;i<d+1; i++) 
                coeffs[d-i]=solution->get_element(i,solution->get_columns()-1);
            model=new Poly(d,coeffs);
            delete coeffs;
            r_squared=SSE(model,this->X(),y_mu,count)/SST(this->Y(),y_mu,count);
            r=sqrt(r_squared);
        }
        else 
        {
            solution=nullptr;
            model=nullptr;
            return;
        }
        
#ifdef DEBUG
        if(normal!=nullptr)
        {
	cout << "Normal Equations: " << endl;
	normal->display();
	cout << "rref Normal system: " << endl;
	solution->display();
	print_solution(solution);
        }
        else 
        {
            cout<<"There is no solution."<<endl<<endl;
        }
#endif
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

void Pointset::print()
{
    cout<<"mu_x: "<<x_mu<<endl;
    cout<<"mu_y: "<<y_mu<<endl<<endl;
    
    if(model!=nullptr)
    {
        cout<<"Polynomial model: "<<endl;
        model->print();
        cout<<"r^2: "<<r_squared<<endl;
    }
    for(int i=0;i<count;i++)
    {
        cout<<points[i].x<<"\t"<<points[i].y<<endl;
    }
    cout<<endl;
    cout<<"mu_x: "<<x_mu<<endl;
    cout<<"mu_y: "<<y_mu<<endl<<endl;
    
    if(model!=nullptr)
    {
        cout<<"Polynomial model: "<<endl;
        model->print();
        cout<<"r: "<<r<<endl;
        cout<<"r^2: "<<r_squared<<endl;
    }
    cout<<endl;
}

double * Pointset:: X()
{
    double *x;
    x=new double[count];
    for(int i=0; i<count; i++)
        x[i]=points[i].x;
    return x;
}

double * Pointset::Y()
{
     double *x;
    x=new double[count];
    for(int i=0; i<count; i++)
        x[i]=points[i].y;
    return x;
}