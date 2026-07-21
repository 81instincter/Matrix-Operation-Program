# Matrix Operations

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

Interactive terminal-based **matrix calculator** written in modern C++.  
Originally developed as the end-of-semester project for **COP3014 (Programming II)** at the University of West Florida (Fall 2024).

The program showcases a complete `Matrix` class that owns a dynamically allocated 2-D array, implements the **Rule of Three**, and supports the three fundamental matrix operations used throughout linear algebra and computer graphics.

---

## Features

| Feature | Description |
|---------|-------------|
| **Default constructor** | Instantly creates a 3×3 matrix filled with ones |
| **Parameterized constructor** | User-defined dimensions and name |
| **Deep copy constructor** | Safe duplication of any matrix (independent memory) |
| **Copy-assignment operator** | Correct handling of self-assignment and resource transfer |
| **Matrix addition** | Element-wise sum (identical dimensions required) |
| **Matrix subtraction** | Element-wise difference |
| **Matrix multiplication** | Classic row-by-column product (columns of A = rows of B) |
| **CSV export** | All stored matrices written to `results.csv` for Excel / Python analysis |
| **Interactive menu** | Clean terminal UI with input validation |

---

## Project Structure

```
Matrix-Operations/
├── main.cpp          # Driver + interactive menu + arithmetic free functions
├── matrix.h          # Matrix class declaration (public API)
├── matrix.cpp        # Matrix class implementation (dynamic memory, Rule of Three)
├── Makefile          # One-command build & run
├── .gitignore
├── LICENSE
└── README.md
```

---

## Building & Running

### Prerequisites
- A C++17- compiler (`g++` ≥ 7 or `clang++`)
- `make` (optional but recommended)

### Quick start

```bash
# Clone (or download) the repository
git clone https://github.com/<your-username>/Matrix-Operations.git
cd Matrix-Operations

# Build
make

# Run the interactive program
make run
# or simply
./matrix-ops
```

### Clean build artifacts
```bash
make clean
```

---

## Sample Session

```
========== Matrix Operations ==========
 1. Create matrix  (default constructor)
 2. Create matrix  (parameterized constructor)
 3. Copy constructor demo
 4. Copy-assignment operator demo
 5. Add two matrices
 6. Subtract two matrices
 7. Multiply two matrices
 8. Print all stored matrices
 9. Export all matrices to results.csv
10. Exit
=======================================
Enter your choice: 7

--- MatrixA ---
Enter row dimension: 2
Enter column dimension: 3
MatrixA(0,0): 1
MatrixA(0,1): 2
MatrixA(0,2): 3
MatrixA(1,0): 4
MatrixA(1,1): 5
MatrixA(1,2): 6
MatrixA (2×3)
1 2 3
4 5 6

--- MatrixB ---
Enter row dimension: 3
Enter column dimension: 2
MatrixB(0,0): 7
MatrixB(0,1): 8
MatrixB(1,0): 9
MatrixB(1,1): 10
MatrixB(2,0): 11
MatrixB(2,1): 12
MatrixB (3×2)
7 8
9 10
11 12

Matrix multiplication completed successfully.
ProductMatrix (2×2)
58 64
139 154
```

The resulting matrices can be exported at any time with option **9**:

```csv
After Matrix Multiplication
58,64
139,154
```

---

## Technical Highlights (for recruiters)

- **Dynamic memory management** – raw `new[]` / `delete[]` with careful ownership (pre-smart-pointer teaching style)
- **Rule of Three** fully implemented: copy constructor, copy-assignment, destructor
- **Const-correctness** on all accessors
- **Input validation** that never crashes on bad user data
- **Separation of concerns**: arithmetic free functions vs. class methods vs. I/O
- **CSV serialization** for interoperability with data-science tools
- Clean, modern C++17 style with member-initializer lists and range-based loops where appropriate

---

## Known Limitations (honest self-assessment)

- Matrices store only `int` values (no floating-point / template version yet)
- No move semantics (Rule of Five) – intentionally kept to the Rule of Three taught in the course
- Single-threaded interactive UI only

These would be natural next steps for a production-grade linear-algebra library.

---

## License

This project is released under the [MIT License](LICENSE).  
Feel free to use it as a reference or starting point for your own matrix library.
