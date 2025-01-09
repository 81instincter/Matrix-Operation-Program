// Elijah Kenning
// COP3014, Professor Mishra, Fall 2024

#include "matrix.h"
#include <fstream> // contains support for input and output operations
#include <string>
#include <vector> // for storing matrices created for later copying modification

// Matrix Operation Functions
 
Matrix matrixAddition(Matrix addend_matrix1, Matrix addend_matrix2) // WORKS
{
	if ((addend_matrix1.getRowVal() == addend_matrix2.getRowVal()) && (addend_matrix1.getColumnVal() == addend_matrix2.getColumnVal()))
	{
		int sumMatrix_rowVal = addend_matrix1.getRowVal();
		int sumMatrix_columnVal = addend_matrix1.getColumnVal();
		Matrix sumMatrix(sumMatrix_rowVal, sumMatrix_columnVal, "SumMatrix");

		int cell_sum;

		for (int i = 0; i < sumMatrix_rowVal; i++)
		{
			for (int j = 0; j < sumMatrix_columnVal; j++)
			{
				cell_sum = addend_matrix1.getCellVal(i, j) + addend_matrix2.getCellVal(i, j);
				sumMatrix.setCellVal(i, j, cell_sum);
			}
			cout << endl;
		}

		cout << "After matrix addition" << endl;
		return sumMatrix;
	}
	else
	{
		cout << "Unable to perform matrix addition due to incorrect dimensions." << endl;
	}
}

Matrix matrixSubtraction(Matrix minuend_matrix, Matrix subtrahend_matrix) // WORKS
{
	// identifier

	if ((minuend_matrix.getRowVal() == subtrahend_matrix.getRowVal()) && (minuend_matrix.getColumnVal() == subtrahend_matrix.getColumnVal()))
	{
		int differenceMatrix_rowVal = minuend_matrix.getRowVal();
		int differenceMatrix_columnVal = minuend_matrix.getColumnVal();
		Matrix differenceMatrix(differenceMatrix_rowVal, differenceMatrix_columnVal, "DifferenceMatrix");

		int cell_difference;

		for (int i = 0; i < differenceMatrix_rowVal; i++)
		{
			for (int j = 0; j < differenceMatrix_columnVal; j++)
			{
				cell_difference = minuend_matrix.getCellVal(i, j) - subtrahend_matrix.getCellVal(i, j);
				differenceMatrix.setCellVal(i, j, cell_difference);
			}
			cout << endl;
		}


		cout << "After matrix subtraction" << endl;
		return differenceMatrix;
	}

	else
	{
		cout << "Unable to perform matrix subtraction due to incorrect dimensions." << endl;
	}
}


Matrix matrixMultiplication(Matrix multiplicand_matrix, Matrix multiplier_matrix) // WORKS
{
	// identifier

	// if the column value of the multiplicand matrix == to the row value of the multiplier_matrix, then can do a multiplication
	if (multiplicand_matrix.getColumnVal() == multiplier_matrix.getRowVal())
	{
		// Product matrix dimensions: row value = row value of the multiplicand matrix, column value = column value of the multiplier matrix
		int productMatrix_rowVal = multiplicand_matrix.getRowVal();
		int productMatrix_columnVal = multiplier_matrix.getColumnVal();
		Matrix productMatrix(productMatrix_rowVal, productMatrix_columnVal, "ProductMatrix");

		/*
		First two loops are the typical loops used for accessing 2D array values.
		The innermost loop is the matrix multiplication, where it takes the product of the current row of the first matrix
		and the current column of the second matrix, then sums up the parts.
		*/
		for (int i = 0; i < productMatrix_rowVal; i++)
		{
			for (int j = 0; j < productMatrix_columnVal; j++)
			{
				int cell_product_sum = 0;
				for (int k = 0; k < multiplier_matrix.getRowVal(); k++)
				{
					cell_product_sum += multiplicand_matrix.getCellVal(i, k) * multiplier_matrix.getCellVal(k, j);
					productMatrix.setCellVal(i, j, cell_product_sum);
				}
			}
		}
		cout << "After matrix multiplication" << endl;
		return productMatrix;
	}
	else 
	{
		cout << "Unable to perform matrix multiplication due to incorrect dimensions." << endl;
	}
}

Matrix userPopulateMatrixA()
{
	int r_a = 0, c_a = 0;

	cout << "Matrix A:" << endl;
	cout << "Enter a positive non-zero integer for Matrix A's row dimension: ";
	cin >> r_a;
	cout << "Enter a positive non-zero integer for Matrix A's column dimension: ";
	cin >> c_a;

	// Create Matrix A
	Matrix matrixA(r_a, c_a, "MatrixA");

	// Populating Matrix A
	int userMatrixACellInput;
	for (int i = 0; i < r_a; i++)
	{
		for (int j = 0; j < c_a; j++)
		{
			cout << "matrixA(" << i << "," << j << "): ";
			cin >> userMatrixACellInput;
			cout << endl;
			matrixA.setCellVal(i, j, userMatrixACellInput);
		}
	}
	return matrixA;
}

Matrix userPopulateMatrixB()
{
	int r_b = 0, c_b = 0;

	cout << "Matrix B:" << endl;
	cout << "Enter a positive non-zero integer for Matrix B's row dimension: ";
	cin >> r_b;
	cout << "Enter a positive non-zero integer for Matrix B's column dimension: ";
	cin >> c_b;

	// Create Matrix B
	Matrix matrixB(r_b, c_b, "MatrixB");

	// Populating Matrix B
	int userMatrixBCellInput;
	for (int i = 0; i < r_b; i++)
	{
		for (int j = 0; j < c_b; j++)
		{
			cout << "matrixB(" << i << "," << j << "): ";
			cin >> userMatrixBCellInput;
			cout << endl;
			matrixB.setCellVal(i, j, userMatrixBCellInput);
		}
	}
	return matrixB;
}

void saveToCSV(vector<Matrix> matrixObjVec, vector<string> names)
{
	fstream fout;
	fout.open("results.csv");
	if (!fout.is_open())
	{
		cout << "Error: The file could not be opened" << endl;
	}
	// Printing the matrix names

	// Insert the data into the results.csv file
	for (int e = 0; e < matrixObjVec.size(); e++)
	{
		fout << names.at(e) << "\n";
		for (int r = 0; r < matrixObjVec.at(e).getRowVal(); r++) // iterate through the rows first
		{
			for (int c = 0; c < matrixObjVec.at(e).getColumnVal() ; c++) // iterate through the columns next
			{
				fout << matrixObjVec.at(e).getCellVal(r, c) << ",";
			}
			fout << "\n";
		}
		fout << "\n";
		// need to work on the formatting
	}
}
	

void mainMenuOptions()
{
	cout << endl;
	cout << "---Main Menu---" << endl;
	cout << "1. Default Constructor" << endl;
	cout << "2. Parametrized Constructor" << endl;
	cout << "3. Copy Constructor" << endl;
	cout << "4. Copy Assignment Operator" << endl;
	cout << "5. Add Two Matrices Together" << endl;
	cout << "6. Subtract a Matrix from Another" << endl;
	cout << "7. Multiply a Matrix with Another" << endl;
	cout << "8. Print matrixObjectsVec" << endl;
	cout << "9. Copy the Matrices to results.csv" << endl;
	cout << "10. Exit" << endl;
	cout << endl;
}



int main()
{
	int choice;

	vector<Matrix> matrixObjectsVec; // used for copy constructor and copy assignment operator 
	vector<string> matrixObjectsNameVec; 

	while (true)
	{
		mainMenuOptions();
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		if (choice == 1) // WORKS
		{
			Matrix DefaultMatrix;
			cout << "---Default Matrix Created---" << endl;
			DefaultMatrix.printMatrix();
			matrixObjectsVec.push_back(DefaultMatrix);
			matrixObjectsNameVec.push_back(DefaultMatrix.getMatrixName());
		}

		else if (choice == 2) //WORKS
		{
			int r, c;

			int numParaMatricesCreated = 1;

			while (numParaMatricesCreated != 4)
			{
				cout << "Enter the row and column dimensions of the matrix you want to make:" << endl;
				cout << "Enter a positive integer for the row dimension: ";
				// prompting a positive integer input until user does so
				while (true)
				{
					cin >> r;
					if (r <= 0)
					{
						cout << "Please enter a positive non-zero integer for the row dimension: " << endl;
					}
					else
					{
						break;
					}
				}
				cout << endl;
				cout << "Enter a positive integer for the column dimension: ";
				// prompting a positive integer input until user does so
				while (true)
				{
					cin >> c;
					if (c <= 0)
					{
						cout << "Please enter a positive non-zero integer for the column dimension: " << endl;
					}
					else
					{
						break;
					}
				}
				cout << endl;

				string paraMatName = "matrix" + to_string(numParaMatricesCreated + 1); // concatenate to get matrix name 

				// Create the ParameterizedMatrix object
				Matrix ParameterizedMatrix(r, c, paraMatName);
				
				// Populating Parameterized Matrix 
				int userParaMatrixCellInput;
				for (int i = 0; i < r; i++)
				{
					for (int j = 0; j < c; j++)
					{
						cout << "matrix" << numParaMatricesCreated + 1 << "(" << i << "," << j << "): ";
						cin >> userParaMatrixCellInput;
						cout << endl;
						ParameterizedMatrix.setCellVal(i, j, userParaMatrixCellInput);
					}
				}
				ParameterizedMatrix.printMatrix();
				cout << ParameterizedMatrix.getMatrixName() << endl;
				matrixObjectsVec.push_back(ParameterizedMatrix);
				matrixObjectsNameVec.push_back(ParameterizedMatrix.getMatrixName());
				++numParaMatricesCreated;
			}
			cout << endl;
		}

		// Copy constructor
		else if (choice == 3)
		{
			int copyConstructorNum;
			cout << "Enter the matrix number (1-4) you want to copy into a new matrix to be created: ";
			while (true)
			{
				cin >> copyConstructorNum;
				if (copyConstructorNum > 4 || copyConstructorNum < 1)
				{
					cout << "Please enter a matrix number between 1 and 4: ";
				}
				else
				{
					// copy constructor code
					Matrix matrixToCopy(matrixObjectsVec.at(copyConstructorNum - 1));

					cout << "Copied matrix:" << endl;
					matrixToCopy.setMatrixName("matrix5");
					matrixToCopy.printMatrix();
					cout << endl;
					break;
				}
			}
			cout << endl;
		}

		// Copy assignment operator
		else if (choice == 4)
		{
			int copyAssignmentNum;
			int mainMenuValue;
			cout << "Before continuing, go back to the main menu and use option 8 to see which index value the matrix you want to copy has.\n";
			while (true)
			{
				cout << "Enter 0 to go back to the main menu if you do not know the index value. Otherwise, enter -1 to continue: ";
				cin >> mainMenuValue;
				if (mainMenuValue != 0 && mainMenuValue != -1)
				{
					cout << "Please enter 0 or -1." << endl;
				}
				else if (mainMenuValue == 0)
				{
					break;
				}
				else if (mainMenuValue == -1)
				{
					while (true)
					{
						cout << "Enter the index value of the matrix number(1-5) you want to copy into another matrix: ";
						cin >> copyAssignmentNum;
						if (copyAssignmentNum > matrixObjectsVec.size() || copyAssignmentNum < 0)
						{
							cout << "Please enter a valid index value for the matrix number you want to copy into another matrix (1-5)." << endl;
						}
						else
						{
							Matrix matrix6(matrixObjectsVec.at(copyAssignmentNum));
							matrix6.setMatrixName("matrix6");
							matrixObjectsVec.push_back(matrix6);
							matrixObjectsNameVec.push_back("matrix6");
							matrix6.printMatrix();
							break;
						}
					}
				}
			}
		}

		// Matrix Addition
		else if (choice == 5) // WORKS
		{

			cout << "You will create two matrices to do matrix operations on." << endl;
			Matrix matrix_a = userPopulateMatrixA();
			matrix_a.printMatrix();
			Matrix matrix_b = userPopulateMatrixB();
			matrix_b.printMatrix();

			Matrix sum = matrixAddition(matrix_a, matrix_b);
			sum.printMatrix();
			cout << endl;

			// add appropriate data to the vectors
			matrixObjectsVec.push_back(sum);
			matrixObjectsNameVec.push_back("After Matrix Addition Operation"); //*****

			// code to continue while loop even after incorrect dimensions are given
		}
		// Matrix Subtraction
		else if (choice == 6) // WORKS
		{
			cout << "You will create two matrices to do matrix operations on." << endl;
			Matrix matrix_a = userPopulateMatrixA();
			matrix_a.printMatrix();
			Matrix matrix_b = userPopulateMatrixB();
			matrix_b.printMatrix();

			Matrix difference = matrixSubtraction(matrix_a, matrix_b);
			difference.printMatrix();
			cout << endl;

			// add appropriate data to the vectors
			matrixObjectsVec.push_back(difference);
			matrixObjectsNameVec.push_back("After Matrix Subtraction Operation"); //*****

			// code to continue while loop even after incorrect dimensions are given
		}
		// Matrix multiplication
		else if (choice == 7) // WORKS
		{
			cout << "You will create two matrices to do matrix operations on." << endl;
			Matrix matrix_a = userPopulateMatrixA();
			matrix_a.printMatrix();
			Matrix matrix_b = userPopulateMatrixB();
			matrix_b.printMatrix();

			Matrix product = matrixMultiplication(matrix_a, matrix_b);
			product.printMatrix();
			cout << endl;

			// add appropriate data to the vectors
			matrixObjectsVec.push_back(product);
			matrixObjectsNameVec.push_back("After Matrix Multiplication Operation"); //*****

			// code to continue while loop even after incorrect dimensions are given
		}
		else if (choice == 8)
		{
			for (int i = 0; i < matrixObjectsVec.size(); i++)
			{
				cout << "Element " << i << ", " + matrixObjectsNameVec.at(i) <<":" << endl; 
				matrixObjectsVec.at(i).printMatrix();
			}
		}
		else if (choice == 9) // WORKS
		{
			saveToCSV(matrixObjectsVec, matrixObjectsNameVec); // WORKS
			cout << "Matrices copied to results.csv" << endl;
			cout << endl;
		}
		else if (choice == 10) // WORKS
		{
			cout << "Exiting program. Goodbye." << endl;
			matrixObjectsVec.clear(); // empties out matrixObjectsVec once program is exited to free up memory
			matrixObjectsNameVec.clear();
			break;
		}
		else
		{
			cout << "Please enter a valid number for one of the options." << endl;
		}
	}
	

	return 0;
}

/*
Sources:

Making sense of dynamic 2D arrays: https://www.youtube.com/watch?v=mGl9LO-je3o
Matrix multiplication: https://www.geeksforgeeks.org/cpp-matrix-multiplication/
File management: https://www.geeksforgeeks.org/csv-file-management-using-c/
Prompting user for appropriate input until they do so: https://stackoverflow.com/questions/41475922/prompt-user-input-until-correct-c
Emptying a vector: https://www.techiedelight.com/delete-vector-free-memory-cpp/
*/


//***** = tiny bug that needs modification later but nothing that is program breaking