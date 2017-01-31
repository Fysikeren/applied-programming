#include <iostream>
#include <cassert>
using namespace std;

double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);
void PrintMatrix(double** matrix, int numRows, int numCols);

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);

int main() {
  int L = 3, M = 2, N = 4;

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

  double** C = AllocateMatrixMemory(L, N);
  for (int i=0; i<L; i++) {
    for (int j=0; j<N; j++){
      C[i][j]  = i*j;
    }
  }
  PrintMatrix(C, L, N);
  cout << "\n";

  Multiply(C, A, B, L, M, M, N);
  PrintMatrix(C, L, N);

  FreeMatrixMemory(L, A);
  FreeMatrixMemory(M, B);
  FreeMatrixMemory(L, C);

  return 0;
}

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