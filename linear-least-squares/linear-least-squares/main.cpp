#include <iostream>
#include <cstdio>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include "Matrix.h"
#include "poly.h"
#include "Stats.h"
#include "pointset.h"
using namespace std;

#ifndef _MSC_VER
#define nullptr 0x0
#endif

#define DEBUG

Matrix * construct_normal(Matrix *, Matrix *);
void print_solution(Matrix *);
int main(void)
{
        double array[5]={1.0,0,0,0,-1.0};
        Poly *test;
        test=new Poly(4,array);
        cout<<test->val(2.0)<<endl;
        system("pwd");
	cout << "Press Enter to continue..." << endl;
	delete test;
        if(cin.peek()==EOF)
            cin.ignore();
	cin.get();
	return 0;
}

