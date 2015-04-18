#ifndef MATRIX_H
#define MATRIX_H
/*********************************************************************************************
The purpose of this class is to allow for matrix computation on an N by M matrix with double 
precision floating point entries. Operations which cannot be done will return an empty matrix
**********************************************************************************************/
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
	bool is_square(); //check the matrix is nxn or not
	bool is_empty(); //if the matrix is empty with 0 rows or 0 columns
	void row_scalar(int i, double s); //multiply a row of a matrix by a scalar
	void row_multiply_add(int i, int j, double s); //muliply a row by a scalar and add it to another row. id 
	Matrix * LUSolve(Matrix *);
	void LU(Matrix *, Matrix*);
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