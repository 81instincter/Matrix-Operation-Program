// Matrix Operations Program
// Interactive terminal application that demonstrates a full-featured Matrix class
// with dynamic memory management, the Rule of Three, and classic linear-algebra
// operations (addition, subtraction, multiplication). Results can be exported
// to CSV for further analysis.

#include "matrix.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

// ---------------------------------------------------------------------------
// Free functions – matrix arithmetic
// ---------------------------------------------------------------------------

// Returns true and writes the result into `out on success.
// Returns false (and leaves out untouched) when dimensions are incompatible.
bool matrixAddition(const Matrix& a, const Matrix& b, Matrix& out)
{
    if (a.getRowVal() != b.getRowVal() || a.getColumnVal() != b.getColumnVal()) {
        std::cout << "Unable to perform matrix addition: dimensions do not match.\n";
        return false;
    }

    out = Matrix(a.getRowVal(), a.getColumnVal(), "SumMatrix");
    for (int i = 0; i < a.getRowVal(); ++i) {
        for (int j = 0; j < a.getColumnVal(); ++j) {
            out.setCellVal(i, j, a.getCellVal(i, j) + b.getCellVal(i, j));
        }
    }
    std::cout << "Matrix addition completed successfully.\n";
    return true;
}

bool matrixSubtraction(const Matrix& a, const Matrix& b, Matrix& out)
{
    if (a.getRowVal() != b.getRowVal() || a.getColumnVal() != b.getColumnVal()) {
        std::cout << "Unable to perform matrix subtraction: dimensions do not match.\n";
        return false;
    }

    out = Matrix(a.getRowVal(), a.getColumnVal(), "DifferenceMatrix");
    for (int i = 0; i < a.getRowVal(); ++i) {
        for (int j = 0; j < a.getColumnVal(); ++j) {
            out.setCellVal(i, j, a.getCellVal(i, j) - b.getCellVal(i, j));
        }
    }
    std::cout << "Matrix subtraction completed successfully.\n";
    return true;
}

bool matrixMultiplication(const Matrix& a, const Matrix& b, Matrix& out)
{
    // Classic rule: columns of A must equal rows of B
    if (a.getColumnVal() != b.getRowVal()) {
        std::cout << "Unable to perform matrix multiplication: "
                  << "columns of first matrix must equal rows of second.\n";
        return false;
    }

    out = Matrix(a.getRowVal(), b.getColumnVal(), "ProductMatrix");
    for (int i = 0; i < a.getRowVal(); ++i) {
        for (int j = 0; j < b.getColumnVal(); ++j) {
            int sum = 0;
            for (int k = 0; k < a.getColumnVal(); ++k) {
                sum += a.getCellVal(i, k) * b.getCellVal(k, j);
            }
            out.setCellVal(i, j, sum);
        }
    }
    std::cout << "Matrix multiplication completed successfully.\n";
    return true;
}

// ---------------------------------------------------------------------------
// Helpers for interactive input
// ---------------------------------------------------------------------------

// Read a positive integer; re-prompt until the user supplies one.
int readPositiveInt(const std::string& prompt)
{
    int value = 0;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value > 0) {
            return value;
        }
        std::cout << "Please enter a positive non-zero integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Build a matrix by asking the user for dimensions and every cell value.
Matrix userPopulateMatrix(const std::string& label)
{
    std::cout << "\n--- " << label << " ---\n";
    int rows = readPositiveInt("Enter row dimension: ");
    int cols = readPositiveInt("Enter column dimension: ");

    Matrix m(rows, cols, label);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int val = 0;
            std::cout << label << "(" << i << "," << j << "): ";
            std::cin >> val;
            m.setCellVal(i, j, val);
        }
    }
    return m;
}

// Write every stored matrix into results.csv (one matrix after another).
void saveToCSV(const std::vector<Matrix>& matrices,
               const std::vector<std::string>& names)
{
    std::ofstream fout("results.csv");
    if (!fout.is_open()) {
        std::cerr << "Error: could not open results.csv for writing.\n";
        return;
    }

    for (std::size_t e = 0; e < matrices.size(); ++e) {
        fout << names[e] << '\n';
        for (int r = 0; r < matrices[e].getRowVal(); ++r) {
            for (int c = 0; c < matrices[e].getColumnVal(); ++c) {
                fout << matrices[e].getCellVal(r, c);
                if (c + 1 < matrices[e].getColumnVal()) {
                    fout << ',';
                }
            }
            fout << '\n';
        }
        fout << '\n';
    }
    std::cout << "Matrices successfully written to results.csv\n";
}

void printMainMenu()
{
    std::cout << "\n========== Matrix Operations ==========\n"
              << " 1. Create matrix  (default constructor)\n"
              << " 2. Create matrix  (parameterized constructor)\n"
              << " 3. Copy constructor demo\n"
              << " 4. Copy-assignment operator demo\n"
              << " 5. Add two matrices\n"
              << " 6. Subtract two matrices\n"
              << " 7. Multiply two matrices\n"
              << " 8. Print all stored matrices\n"
              << " 9. Export all matrices to results.csv\n"
              << "10. Exit\n"
              << "=======================================\n"
              << "Enter your choice: ";
}

// ---------------------------------------------------------------------------
// Main driver
// ---------------------------------------------------------------------------

int main()
{
    std::vector<Matrix>      matrixObjects;
    std::vector<std::string> matrixNames;

    int choice = 0;
    while (true) {
        printMainMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number 1-10.\n";
            continue;
        }

        switch (choice) {
        // -----------------------------------------------------------------
        // 1. Default constructor
        // -----------------------------------------------------------------
        case 1: {
            Matrix m;                       // 3×3 filled with 1s
            std::cout << "\n--- Default Matrix Created ---\n";
            m.printMatrix();
            matrixObjects.push_back(m);
            matrixNames.push_back(m.getMatrixName());
            break;
        }

        // -----------------------------------------------------------------
        // 2. Parameterized constructor (create up to 3 custom matrices)
        // -----------------------------------------------------------------
        case 2: {
            for (int n = 0; n < 3; ++n) {
                std::string name = "matrix" + std::to_string(n + 2);
                int rows = readPositiveInt("\nEnter row dimension: ");
                int cols = readPositiveInt("Enter column dimension: ");

                Matrix m(rows, cols, name);
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        int val = 0;
                        std::cout << name << "(" << i << "," << j << "): ";
                        std::cin >> val;
                        m.setCellVal(i, j, val);
                    }
                }
                m.printMatrix();
                matrixObjects.push_back(m);
                matrixNames.push_back(name);
            }
            break;
        }

        // -----------------------------------------------------------------
        // 3. Copy constructor demo
        // -----------------------------------------------------------------
        case 3: {
            if (matrixObjects.empty()) {
                std::cout << "No matrices stored yet. Create one first (option 1 or 2).\n";
                break;
            }
            std::cout << "Stored matrices (0-based index):\n";
            for (std::size_t i = 0; i < matrixObjects.size(); ++i) {
                std::cout << "  [" << i << "] " << matrixNames[i] << '\n';
            }
            int idx = 0;
            std::cout << "Enter index of matrix to copy: ";
            std::cin >> idx;
            if (idx < 0 || static_cast<std::size_t>(idx) >= matrixObjects.size()) {
                std::cout << "Invalid index.\n";
                break;
            }

            Matrix copy(matrixObjects[idx]);          // invokes copy ctor
            copy.setMatrixName(matrixNames[idx] + "_copy");
            std::cout << "\nCopied matrix:\n";
            copy.printMatrix();

            matrixObjects.push_back(copy);
            matrixNames.push_back(copy.getMatrixName());
            break;
        }

        // -----------------------------------------------------------------
        // 4. Copy-assignment operator demo
        // -----------------------------------------------------------------
        case 4: {
            if (matrixObjects.empty()) {
                std::cout << "No matrices stored yet. Create one first (option 1 or 2).\n";
                break;
            }
            std::cout << "Stored matrices (0-based index):\n";
            for (std::size_t i = 0; i < matrixObjects.size(); ++i) {
                std::cout << "  [" << i << "] " << matrixNames[i] << '\n';
            }
            int idx = 0;
            std::cout << "Enter index of matrix to assign-from: ";
            std::cin >> idx;
            if (idx < 0 || static_cast<std::size_t>(idx) >= matrixObjects.size()) {
                std::cout << "Invalid index.\n";
                break;
            }

            Matrix assigned;                              // default 3×3
            assigned = matrixObjects[idx];                // invokes operator=
            assigned.setMatrixName(matrixNames[idx] + "_assigned");
            std::cout << "\nAssigned matrix:\n";
            assigned.printMatrix();

            matrixObjects.push_back(assigned);
            matrixNames.push_back(assigned.getMatrixName());
            break;
        }

        // -----------------------------------------------------------------
        // 5 / 6 / 7. Arithmetic operations
        // -----------------------------------------------------------------
        case 5:
        case 6:
        case 7: {
            Matrix a = userPopulateMatrix("MatrixA");
            a.printMatrix();
            Matrix b = userPopulateMatrix("MatrixB");
            b.printMatrix();

            Matrix result;
            bool ok = false;
            std::string opName;

            if (choice == 5) {
                ok = matrixAddition(a, b, result);
                opName = "After Matrix Addition";
            } else if (choice == 6) {
                ok = matrixSubtraction(a, b, result);
                opName = "After Matrix Subtraction";
            } else {
                ok = matrixMultiplication(a, b, result);
                opName = "After Matrix Multiplication";
            }

            if (ok) {
                result.printMatrix();
                // Only store a result when the operation actually succeeded
                matrixObjects.push_back(result);
                matrixNames.push_back(opName);
            }
            break;
        }

        // -----------------------------------------------------------------
        // 8. Print everything currently stored
        // -----------------------------------------------------------------
        case 8: {
            if (matrixObjects.empty()) {
                std::cout << "No matrices stored yet.\n";
                break;
            }
            std::cout << "\n--- Stored Matrices ---\n";
            for (std::size_t i = 0; i < matrixObjects.size(); ++i) {
                std::cout << "\n[" << i << "] " << matrixNames[i] << ":\n";
                matrixObjects[i].printMatrix();
            }
            break;
        }

        // -----------------------------------------------------------------
        // 9. Export to CSV
        // -----------------------------------------------------------------
        case 9: {
            if (matrixObjects.empty()) {
                std::cout << "Nothing to export.\n";
                break;
            }
            saveToCSV(matrixObjects, matrixNames);
            break;
        }

        // -----------------------------------------------------------------
        // 10. Exit
        // -----------------------------------------------------------------
        case 10: {
            std::cout << "Exiting program. Goodbye!\n";
            matrixObjects.clear();
            matrixNames.clear();
            return 0;
        }

        default:
            std::cout << "Please enter a valid option (1-10).\n";
            break;
        }
    }
}