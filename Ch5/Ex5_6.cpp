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
  int ACols = 2, ARows = 4, BCols = 5, BRows = 3;

  cout << "Multiply a vector and a matrix" << endl;

  double** A = AllocateMatrixMemory(ARows, ACols);
  for (int i=0; i<ARows; i++) {
    for (int j=0; j<ACols; j++){
      A[i][j]  = i;
    }
  }
  PrintMatrix(A, ARows, ACols);
  cout << "\n";

  double** B = AllocateMatrixMemory(BRows, BCols);
  for (int i=0; i<BRows; i++) {
    for (int j=0; j<BCols; j++){
      B[i][j]  = j;
    }
  }
  PrintMatrix(B, BRows, BCols);
  cout << "\n";

  double* a = new double [ARows];
  for (int i=0; i<ARows; i++) {
    a[i] = i;
    cout << a[i] << " ";
  }
  cout << "\n";

  double* b = new double [ACols];
  Multiply(b, a, A, ARows, ARows, ACols);
  for (int i=0; i<ACols; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";

  double* c = new double [BCols];
  for (int i=0; i<BCols; i++) {
    c[i] = i;
    cout << c[i] << " ";
  }
  cout << "\n";

  double* d = new double [BRows];
//  Multiply(b, a, A, ARows, ARows, ACols);
  Multiply(d, B, c, BRows, BCols, BCols);
  for (int i=0; i<BRows; i++) {
    cout << d[i] << " ";
  }
  cout << "\n";

  FreeMatrixMemory(ACols, A);
  FreeMatrixMemory(BRows, B);
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] d;

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