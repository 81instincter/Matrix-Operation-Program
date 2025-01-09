// Elijah Kenning
// COP3014, Professor Mishra, Fall 2024

#include "matrix.h"

Matrix::Matrix()
{
	rowVal = 3;
	columnVal = 3;
	matrixName = "matrix1";
	allocateMemory();
	defaultPopulation();
}

Matrix::Matrix(int r, int c, string mName)
{
	rowVal = r;
	columnVal = c;
	matrixName = mName;
	allocateMemory();
	defaultPopulation();
}

Matrix::Matrix(const Matrix& original_matrix) // copy constructor
{
	// Copy the values of the original matrix to the copied matrix
	rowVal = original_matrix.rowVal;
	columnVal = original_matrix.columnVal;

	allocateMemory();

	for (int i = 0; i < rowVal; i++)
	{
		for (int j = 0; j < columnVal; j++)
		{
			matrix[i][j] = original_matrix.matrix[i][j];
			// copies the values stored in the original_matrix
			// into the copied matrix 
		}
	}
}

Matrix& Matrix::operator=(const Matrix& original_matrix)
{
	if (this == &original_matrix) // For self-assignment
	{
		return *this;
	}

	if (matrix) // Frees memory taken by the private matrix data member
	{
		deallocateMemory();
	}

	rowVal = original_matrix.rowVal;
	columnVal = original_matrix.columnVal;

	// Allocating the copying the data
	allocateMemory();
	for (int i = 0; i < rowVal; i++)
	{
		for (int j = 0; j < columnVal; j++)
		{
			matrix[i][j] = original_matrix.matrix[i][j];
		}
	}
	return *this;
}

Matrix::~Matrix()
{
	if (matrix)
	{
		cout << "Destructor called" << endl;
		deallocateMemory();
	}
}

// Memory functions

void Matrix::allocateMemory()
{
	matrix = new int* [rowVal];
	for (int i = 0; i < rowVal; i++)
	{
		matrix[i] = new int[columnVal];
	}
}

void Matrix::deallocateMemory()
{
	for (int i = 0; i < rowVal; i++)
	{
		delete[] matrix[i];
		// deallocate the array matrix[i] is pointing to
		// i.e. the array of the actual values
	}
	delete[] matrix; // deallocate the array of pointers 
	matrix = NULL; // prevent potential crashes and errors
}	// may need to comment out matrix =NULL;


// Getter and Setter Functions

int Matrix::getCellVal(int r, int c)
{
	if (r < 0 || r >= rowVal || c < 0 || c >= columnVal)
	{
		cout << "Out of range. Enter a different index." << endl;
	}
	return matrix[r][c];
}

int Matrix::getRowVal() // WORKS
{
	return rowVal;
}

int Matrix::getColumnVal() // WORKS
{
	return columnVal;
}

string Matrix::getMatrixName()
{
	return matrixName;
}

void Matrix::setMatrixName(string mName)
{
	matrixName = mName;
}

void Matrix::setCellVal(int r, int c, int val) // WORKS
{
	// have to work with row and column values of 0 to r - 1 and 0 to c - 1
	if (r < 0 || r >= rowVal || c < 0 || c >= columnVal)
	{
		cout << "Out of range. Enter a different index." << endl;
	}
	matrix[r][c] = val;
}

void Matrix::printMatrix()
{
	cout << matrixName << endl;
	for (int i = 0; i < rowVal; i++)
	{
		for (int j = 0; j < columnVal; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::defaultPopulation()
{
	for (int i = 0; i < rowVal; i++)
	{
		for (int j = 0; j < columnVal; j++)
		{
			matrix[i][j] = 1;
		}
	}
}