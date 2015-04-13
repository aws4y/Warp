#ifndef MATRIX_H
#define MATRIX_H

using namespace std;
class Matrix
{
private: 
	double **matrix;
	int rows;
	int columns;
	
public:
	Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix &);
	~Matrix();
	void display();
	void input();
	//matrix specific functions
	Matrix * Trans();
	Matrix *rref();    //produces the reduced row echelon form of a matrix 
	Matrix * Det();    //produces the determinant of a matrix
	Matrix * Inv();    //produces the inverse of a matrix null if the matrix is not invertable 
	Matrix *ref();     //produces the row echelon form of a matrix
	void swap_rows(int i, int j);  //swap two rows of a matrix 
	void row_scalar(int i, double s); //multiply a row of a matrix by a scalar
	void row_multiply_add(int i, int j, double s); //muliply a row by a scalar and add it to another row. 
	//matrix operators
	Matrix & operator=(const Matrix &);
	Matrix & operator*= (const Matrix &);   
	Matrix & operator*(const Matrix &);  //matrix multiplication
	Matrix & operator+(const Matrix &);  //matrix addition
	Matrix & operator+=(const Matrix &); 
	Matrix & operator *(const double &);  //scalar multiplication
	
	//accessor and mutator functions
	void set_element(int, int, double);
	double get_element(int, int);
	int get_rows();
	int get_columns();
	
};


#endif