#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
#include <cmath>

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
  ComplexNumber **matrix = AllocateMatrixMemory();

  for (int n = 0; n<=nMax; n++) {
    MatrixPower(matrix, A, n);
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        res[i][j] = res[i][j] + matrix[i][j];
      }
    }
  }

  FreeMatrixMemory(matrix);
}

// Function to print the contents of a matrix
void printMatrix(ComplexNumber **A, int rows, int cols)
{
  for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++){
      std::cout << A[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << std::endl;
}

// Function to multiply two matrices
void Multiply(ComplexNumber **res, ComplexNumber **A, ComplexNumber **B) {
  ComplexNumber entry;

  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      entry = 0;
      for (int k=0; k<3; k++) {
        entry = entry + A[i][k]*B[k][j];
      }
      res[i][j] = entry;
    }
  }
}

// Function to calculate the nth power of a matrix and divide it by n
void MatrixPower(ComplexNumber **res, ComplexNumber **A, int nMax) {
  if (nMax == 0) {
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        res[i][j] = ComplexNumber();
      }
      res[i][i] = ComplexNumber(1,0);
    }
  }
  else if (nMax == 1) {
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        res[i][j] = A[i][j];
      }
    }
  }
  else {
    ComplexNumber **matrix = AllocateMatrixMemory();
  
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        res[i][j] = A[i][j];
      }
    }

    for (int n = 2; n<=nMax; n++) {
      for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
          matrix[i][j] = res[i][j]*ComplexNumber(1/(double)n,0);
        }
      }

      Multiply(res, A, matrix);
    }

    FreeMatrixMemory(matrix);
  }
}