#include "Matrix.h"


int main(void)
{
	int n, N;
	Matrix *input;
	Matrix *normal;
	cout << "Number of unknowns: ";
	cin >> n;
	cout << "Number of Equations:";
	cin >> N;
	input = new Matrix (N, n + 1);
	input->input();
	input->display();

	delete input;
	cin.get();
	cin.get();
	return 0;
}