// Matrix Operations Program
// Demonstrates C++ classes, dynamic memory allocation, the Rule of Three,
// and fundamental matrix algebra operations.

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>

class Matrix {
private:
    int rowVal;
    int columnVal;
    std::string matrixName;
    int** matrix;               // Dynamically allocated 2-D array

    void allocateMemory();
    void deallocateMemory();

public:
    // --- Constructors & Destructor (Rule of Three) ---
    Matrix();                                           // Default: 3×3 named "matrix1", filled with 1s
    Matrix(int r, int c, const std::string& mName);     // Parameterized constructor
    Matrix(const Matrix& other);                        // Deep-copy constructor
    Matrix& operator=(const Matrix& other);             // Deep-copy assignment
    ~Matrix();                                          // Destructor – frees dynamic memory

    // --- Accessors ---
    int getCellVal(int r, int c) const;
    int getRowVal() const;
    int getColumnVal() const;
    std::string getMatrixName() const;

    // --- Mutators ---
    void setMatrixName(const std::string& mName);
    void setCellVal(int r, int c, int val);

    // --- Utilities ---
    void printMatrix() const;
    void defaultPopulation();                           // Fill every cell with 1
};

#endif // MATRIX_H
