#include <cassert>
#include "5_6.h"

// Function to multiply two matrices
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols) {
  double entry;

  assert(ACols == BRows);

  for (int i=0; i<ARows; i++) {
    for (int j=0; j<BCols; j++) {
      entry = 0;
      for (int k=0; k<ACols; k++) {
        entry += A[i][k]*B[k][j];
      }
      res[i][j] = entry;
    }
  }
}

// Function to multiply a vector, A, and a matrix, B
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols) {
  double entry;

  assert(ACols == BRows);

  for (int i=0; i<BCols; i++) {
    entry = 0.0;
    for (int j=0; j<ACols; j++) {
      entry += A[j]*B[j][i];
    }
    res[i] = entry;
  }  
}

// Function to multiply a matrix, A, and a vector, B
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows) {
  double entry;

  assert(ACols == BRows);

  for (int i=0; i<ARows; i++) {
    entry = 0.0;
    for (int j=0; j<ACols; j++) {
      entry += A[i][j]*B[j];
    }
    res[i] = entry;
  }
}

// Function to multiply a scalar and a matrix, B
void Multiply(double **res, double scalar, double **B, int BRows, int BCols) {
  for (int i=0; i<BRows; i++) {
    for (int j=0; j<BCols; j++) {
      res[i][j] = scalar*B[i][j];
    }
  }
}

void Multiply(double **res, double **B, double scalar, int BRows, int BCols) {
  Multiply(res, scalar, B, BRows, BCols);
}