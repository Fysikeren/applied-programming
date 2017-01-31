#include <iostream>
using namespace std;

int main() {
  double **A, **B, **C;

  for (int k=0; k<1e9; k++) {
    A = new double* [2];
    B = new double* [2];
    for (int i=0; i<2; i++) {
      A[i] = new double [2];
      B[i] = new double [2];
      for (int j=0; j<2; j++) {
        A[i][j] = i*j;
        B[i][j] = (i+1)*(j+1);
      }
    }
    
    C = new double* [2];
    for (int i=0; i<2; i++) {
      C[i] = new double [2];
      for (int j=0; j<2; j++) {
        C[i][j] = A[i][j] + B[i][j];
      }
    }
    // cout << "C =" << "\n(" << C[0][0] << " " << C[0][1] << "\n " << C[1][0] << " " << C[1][1] << ")" << endl;

    for (int i=0; i<2; i++) {
      delete[] A[i];
      delete[] B[i];
      delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
  }

	return 0;
}