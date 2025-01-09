// Elijah Kenning
// COP3014, Professor Mishra, Fall 2024

#ifndef MATRIX
#define MATRIX

#include <iostream>
using namespace std;

class Matrix
{
private:
	int** matrix;
	int rowVal;
	int columnVal;
	string matrixName;

	void allocateMemory();
	void deallocateMemory();

public:
	Matrix();
	Matrix(int r, int c, string mName);
	Matrix(const Matrix& matrixToCopy);
	Matrix& operator=(const Matrix& matrixToCopy);
	~Matrix();

	int getCellVal(int r, int c);
	int getRowVal();
	int getColumnVal();
	string getMatrixName();
	void setMatrixName(string mName);
	void setCellVal(int r, int c, int val);

	void printMatrix();

	void defaultPopulation();
};

#endif