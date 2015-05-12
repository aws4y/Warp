#include <iostream>
#include <cstdio>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Matrix.h"
#include "poly.h"
#include "Stats.h"
#include "pointset.h"
using namespace std;

#ifndef _MSC_VER
#define nullptr 0x0
#endif

#define DEBUG

int main(void) {
    ifstream input;
    input.open("data.dat");
    if(!input.is_open()){
        cout<<"File not found is file in: ";
        system("pwd");
        cout<<"?"<<endl;
    }
    double *x;
    double *y; 
    double dum_x;
    double dum_y;
    unsigned int count=0;
    Pointset *data;
    x= new double [1500];
    y= new double [1500];
            
    do
    {
        input>>dum_x;
        input>>dum_y;
        if(!input.eof())
        {
            x[count]=dum_x;
            y[count]=dum_y;
            count++;
        }
    }while(input.eof()==false && count<1500);
    data=new Pointset(count,x,y);
    data->build_model();
    data->print();
    cout << "Press Enter to continue..." << endl;
 
    delete data;
    input.close();
    if (cin.peek() == EOF)
        cin.ignore();
    cin.get();
    return 0;
}

