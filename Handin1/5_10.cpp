#include <cmath>
#include "5_10.h"

void guassian_elimination(double **A, double *b, double *u, int n) {
  Pivoter(A,b,n);
  MakeTriangular(A,b,n);
  NormaliseTriangle(A,b,n);
  FindSolution(A,b,u,n);
}

// Function to actually find the solution from the normalised upper triangular matrix
void FindSolution(double **A, double *b, double *u, int length) {
  for (int i=length-1; i>=0; i--) {
    double sum = 0;
    for (int j=i+1; j<length; j++) {
      sum += A[i][j]*u[j];
    }
    u[i] = b[i]-sum;
  }
}

// Function to normalise an upper triangualar matrix, A, along with its vector, b, so all diagonal entries are 1
void NormaliseTriangle(double **A, double *b, int length) {
  double temp;

  for (int i=0; i<length; i++) {
    temp = A[i][i];
    for (int j=i; j<length; j++) {
      A[i][j] /= temp;
    }
    b[i] /= temp;
  }
}

// Function to make the pivoted matrix, A, into an upper triangular matrix, along with its vector, b 
void MakeTriangular(double **A, double *b, int length) {
  for (int i=0; i<length; i++) {
    for (int j=i+1; j<length; j++) {
      double factor = A[j][i]/A[i][i];
    
      b[j] -= factor*b[i];
      for (int k=0; k<length; k++) {
        A[j][k] -= factor*A[i][k];
      }
    }
  }
}

// Function to pivot matrix
void Pivoter(double **A, double *b, int length) {
  for (int i=0; i<length; i++) {
    int maxrow = FindMax(A, length, i);
    SwapRows(A, b, length, i, maxrow);
  }
}

// Function to swap the rows 'step' and 'row' in the matrix 'A'
void SwapRows(double **A, double* b, int length, int step, int row) {
  
  // First we swap the relevant rows of the matrix, A
  double* tempA = new double [length];
  for (int i=0; i<length; i++) {
    tempA[i] = A[step][i];
    A[step][i] = A[row][i];
    A[row][i] = tempA[i];
  }
  delete[] tempA;

  // And then we swap the relevant entries of the vector, b
  double tempB = b[step];
  b[step] = b[row];
  b[row] = tempB;
}

// Finds the row number of the maximum entry in column 'col'
int FindMax(double **A, int length, int step) {
  int row = 0;
  double TheMax = 0.0;

  for (int i=step; i<length; i++) {
    if (fabs(A[i][step] - TheMax) > 0.0) {
      row = i;
    }
  }

  return row;
}

// Function to allocate memory for a matrix dynamically
double** AllocateMatrixMemory(int numRows, int numCols) {
  double** matrix;
  matrix = new double * [numRows];

  for (int i=0; i<numRows; i++) {
    matrix[i] = new double [numCols];
  }
  return matrix;
}

// Function to free memory of a matrix
void FreeMatrixMemory(int numRows, double** matrix) {
  for (int i=0; i<numRows; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

// Function to print the contents of a matrix
void MyPrinter(double** matrix, int numRows, int numCols) {
  for (int i=0; i<numRows; i++) {
    for (int j=0; j<numCols; j++){
    }
  }
}

// Function to print the contents of a vector
void MyPrinter(double* A, int length) {
  for (int i=0; i<length; i++) {
  }

}