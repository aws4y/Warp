#include <iostream>
#include "Matrix.h"
using namespace std;

int main(void)
{
	int n, N;
	Matrix <double> *matrix;
	Matrix <double> *normal;
	cout << "Number of unknowns: ";
	cin >> n;
	cout << "Number of Equations:";
	cin >> N;
	matrix = new Matrix <double> (N, n + 1);
	delete matrix;
	return 0;
}