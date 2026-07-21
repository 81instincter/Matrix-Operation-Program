// Matrix Operations Program

#include "matrix.h"

// ---------------------------------------------------------------------------
// Constructors & Destructor
// ---------------------------------------------------------------------------

Matrix::Matrix()
    : rowVal(3), columnVal(3), matrixName("matrix1"), matrix(nullptr)
{
    allocateMemory();
    defaultPopulation();
}

Matrix::Matrix(int r, int c, const std::string& mName)
    : rowVal(r), columnVal(c), matrixName(mName), matrix(nullptr)
{
    allocateMemory();
    defaultPopulation();
}

// Deep-copy constructor (Rule of Three)
Matrix::Matrix(const Matrix& other)
    : rowVal(other.rowVal), columnVal(other.columnVal),
      matrixName(other.matrixName), matrix(nullptr)
{
    allocateMemory();
    for (int i = 0; i < rowVal; ++i) {
        for (int j = 0; j < columnVal; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

// Deep-copy assignment operator (Rule of Three)
Matrix& Matrix::operator=(const Matrix& other)
{
    if (this == &other) {               // Guard against self-assignment
        return *this;
    }

    // Free existing resources
    if (matrix) {
        deallocateMemory();
    }

    rowVal     = other.rowVal;
    columnVal  = other.columnVal;
    matrixName = other.matrixName;

    allocateMemory();
    for (int i = 0; i < rowVal; ++i) {
        for (int j = 0; j < columnVal; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

Matrix::~Matrix()
{
    if (matrix) {
        deallocateMemory();
    }
}

// ---------------------------------------------------------------------------
// Private memory helpers
// ---------------------------------------------------------------------------

void Matrix::allocateMemory()
{
    matrix = new int*[rowVal];
    for (int i = 0; i < rowVal; ++i) {
        matrix[i] = new int[columnVal]();   // zero-initialize
    }
}

void Matrix::deallocateMemory()
{
    for (int i = 0; i < rowVal; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

// ---------------------------------------------------------------------------
// Accessors
// ---------------------------------------------------------------------------

int Matrix::getCellVal(int r, int c) const
{
    if (r < 0 || r >= rowVal || c < 0 || c >= columnVal) {
        std::cerr << "Error: index (" << r << "," << c << ") out of range.\n";
        return 0;
    }
    return matrix[r][c];
}

int Matrix::getRowVal() const
{
    return rowVal;
}

int Matrix::getColumnVal() const
{
    return columnVal;
}

std::string Matrix::getMatrixName() const
{
    return matrixName;
}

// ---------------------------------------------------------------------------
// Mutators
// ---------------------------------------------------------------------------

void Matrix::setMatrixName(const std::string& mName)
{
    matrixName = mName;
}

void Matrix::setCellVal(int r, int c, int val)
{
    if (r < 0 || r >= rowVal || c < 0 || c >= columnVal) {
        std::cerr << "Error: index (" << r << "," << c << ") out of range.\n";
        return;
    }
    matrix[r][c] = val;
}

// ---------------------------------------------------------------------------
// Utilities
// ---------------------------------------------------------------------------

void Matrix::printMatrix() const
{
    std::cout << matrixName << " (" << rowVal << "×" << columnVal << ")\n";
    for (int i = 0; i < rowVal; ++i) {
        for (int j = 0; j < columnVal; ++j) {
            std::cout << matrix[i][j] << (j + 1 < columnVal ? " " : "");
        }
        std::cout << '\n';
    }
}

void Matrix::defaultPopulation()
{
    for (int i = 0; i < rowVal; ++i) {
        for (int j = 0; j < columnVal; ++j) {
            matrix[i][j] = 1;
        }
    }
}
