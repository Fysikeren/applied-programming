#include <iostream>
#include <cassert>
using namespace std;

double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);
void PrintMatrix(double** matrix, int numRows, int numCols);

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols);
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows);
void Multiply(double **res, double scalar, double **B, int BRows, int BCols);
void Multiply(double **res, double **B, double scalar, int BRows, int BCols);

int main() {
  int L = 3, M = 2, N = 5;

  cout << "Multiply a vector and a matrix" << endl;

  double** A = AllocateMatrixMemory(L, M);
  for (int i=0; i<L; i++) {
    for (int j=0; j<M; j++){
      A[i][j]  = i;
    }
  }
  PrintMatrix(A, L, M);
  cout << "\n";

  double** B = AllocateMatrixMemory(M, N);
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++){
      B[i][j]  = j;
    }
  }
  PrintMatrix(B, M, N);
  cout << "\n";

  double* a = new double [N];
  for (int i=0; i<N; i++) {
    a[i] = i;
    cout << a[i] << " ";
  }
  cout << "\n";

  double* b = new double [M];
  Multiply(b, a, B, N, M, N);
  for (int i=0; i<M; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
  
  cout << "Multiply a scalar and a matrix" << endl;

  double** resA = AllocateMatrixMemory(L, M);
  Multiply(resA, 2.0, A, L, M);
  PrintMatrix(A, L, M);
  PrintMatrix(resA, L, M);

  double** resB = AllocateMatrixMemory(M, N);
  Multiply(resB, B, 3.5, M, N);
  PrintMatrix(B, M, N);
  PrintMatrix(resB, M, N);

  FreeMatrixMemory(L, A);
  FreeMatrixMemory(M, B);
  delete[] a;
  delete[] b;
  FreeMatrixMemory(L, resA);
  FreeMatrixMemory(M, resB);

  return 0;
}

// Function to multiply two matrices, A and B
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

  assert(ACols == BCols);

  for (int i=0; i<BRows; i++) {
    entry = 0;
    for (int j=0; j<ACols; j++) {
      entry += B[i][j]*A[j];
    }
    res[i] = entry;
  }
}

// Function to multiply a matrix, A, and a vector, B
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows) {}

// Function to multiply a scalar and a matrix, B
void Multiply(double **res, double scalar, double **B, int BRows, int BCols) {
  for (int i=0; i<BRows; i++) {
    for (int j=0; j<BCols; j++) {
      res[i][j] = scalar*B[i][j];
    }
  }
}

// Function to multiply a matrix, B, and a scalar
void Multiply(double **res, double **B, double scalar, int BRows, int BCols) {
  Multiply(res, scalar, B, BRows, BCols);
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
void PrintMatrix(double** matrix, int numRows, int numCols) {
  for (int i=0; i<numRows; i++) {
    for (int j=0; j<numCols; j++){
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }

}