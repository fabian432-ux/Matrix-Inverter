# Matrix Inversion Utility

## Description
A C program that calculates the inverse of a square matrix using the Gauss-Jordan elimination algorithm. The program creates an augmented matrix $[A | I]$ and applies elementary row operations to transform the left side into an identity matrix, leaving the inverted matrix on the right. 

## Features
* **Input Validation:** Verifies that the input matrix is square ($N \times N$).
* **Singularity Checks:** Automatically checks for basic conditions that make a matrix non-invertible, including:
    * Rows or columns filled entirely with zeros.
    * Two identical rows or two identical columns.
* **Partial Pivoting:** Detects zeros on the principal diagonal and swaps rows to allow the calculation to continue.
* **Gauss-Jordan Elimination:** Performs both forward and backward elimination phases, followed by row normalization.
* **Floating-Point Precision:** Uses `float` data types to handle decimal values and fractional results.

## How to Compile and Run

### Prerequisites
You need a C compiler installed on your system (such as GCC).

### Compilation
Open your terminal and run the following command. The `-lm` flag is required on some systems to link the math library (`<math.h>`).
```bash
gcc main.c -o matrix_inverter -lm
