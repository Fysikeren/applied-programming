#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

void solve3by3(double **A, double *b, double *u);
void guassian_elimination(double **A, double *b, double *u, int n);

void Pivoter(double **A, double *b, int length);
int FindMax(double **A, int length, int step);
void SwapRows(double **A, double* b, int length, int step, int row);
void MakeTriangular(double **A, double *b, int length);
void NormaliseTriangle(double **A, double *b, int length);
void FindSolution(double **A, double *b, double *u, int n);

double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);
void MyPrinter(double** matrix, int numRows, int numCols);
void MyPrinter(double* A, int length);

int main() {
  int MatSize = 3;
  // int MatSize = 4;
  // int MatSize = 1;

  cout << "Initilising matrix and vectors:" << endl;
  double** A = AllocateMatrixMemory(MatSize, MatSize);
  A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
  A[1][0] = 0; A[1][1] = 1; A[1][2] = 4;
  A[2][0] = 5; A[2][1] = 6; A[2][2] = 0;
  // A[0][0] = 2; A[0][1] = 3; A[0][2] = 1; A[0][3] = 5;
  // A[1][0] = 1; A[1][1] = 0; A[1][2] = 3; A[1][3] = 1;
  // A[2][0] = 0; A[2][1] = 2; A[2][2] = -3; A[2][3] = 2;
  // A[3][0] = 0; A[3][1] = 2; A[3][2] = 3; A[3][3] = 1;
  // A[0][0] = 9;
  cout << "A = " << endl;
  MyPrinter(A, MatSize, MatSize);

  double* b = new double [MatSize];
  b[0] = 14; b[1] = 14; b[2] = 17;
  // b[0] = 1; b[1] = 2; b[2] = 3;
  // b[0] = 1; b[1] = 2; b[2] = 3; b[3] = 4;
  // b[0] = 5;
  cout << "b = " << endl;
  MyPrinter(b, MatSize);

  double* u = new double [MatSize];
  cout << "u = " << endl;
  MyPrinter(u, MatSize);

  cout << "Using gaussian elimination:" << endl;
  // guassian_elimination(A, b, u, MatSize);
  solve3by3(A, b, u);

  cout << "A = " << endl;
  MyPrinter(A, MatSize, MatSize);
  cout << "b = " << endl;
  MyPrinter(b, MatSize);
  cout << "u = " << endl;
  MyPrinter(u, MatSize);

  FreeMatrixMemory(MatSize, A);
  delete[] b;
  delete[] u;
}

void solve3by3(double **A, double *b, double *u) {
  guassian_elimination(A, b, u, 3);
}

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
      cout << "i = " << i << " j = " << j << endl;
      cout << "sum = " << sum << endl;
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
      // cout << "Factor = " << factor << endl;
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
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

// Function to print the contents of a vector
void MyPrinter(double* A, int length) {
  for (int i=0; i<length; i++) {
    cout << A[i] << " ";
  }
  cout << "\n\n";

}