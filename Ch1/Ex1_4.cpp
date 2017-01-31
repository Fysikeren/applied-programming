#include <iostream>
#include <cmath>

int main() {
  double matrixA[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
  double matrixB[2][2] = {{5.5, 4.2}, {1.9, 9.4}};

  // std::cout << "Matrix A =\n" << matrixA[0][0] << " " << matrixA[0][1] << "\n" << matrixA[1][0] << " " << matrixA[1][1] << std::endl;
  // std::cout << "Matrix B =\n" << matrixB[0][0] << " " << matrixB[0][1] << "\n" << matrixB[1][0] << " " << matrixB[1][1] << std::endl;

  double matrixC[2][2];

  matrixC[0][0] = matrixA[0][0] + matrixB[0][0];
  matrixC[0][1] = matrixA[0][1] + matrixB[0][1];
  matrixC[1][0] = matrixA[1][0] + matrixB[1][0];
  matrixC[1][1] = matrixA[1][1] + matrixB[1][1];

  std::cout << "Matrix C =\n" << matrixC[0][0] << " " << matrixC[0][1] << "\n" << matrixC[1][0] << " " << matrixC[1][1] << std::endl;

  double matrixD[2][2];

  matrixD[0][0] = matrixA[0][0]*matrixB[0][0] + matrixA[0][1]*matrixB[1][0];
  matrixD[0][1] = matrixA[0][0]*matrixB[0][1] + matrixA[0][1]*matrixB[1][1];
  matrixD[1][0] = matrixA[1][0]*matrixB[0][0] + matrixA[1][1]*matrixB[1][0];
  matrixD[1][1] = matrixA[1][0]*matrixB[0][1] + matrixA[1][1]*matrixB[1][1];

  std::cout << "Matrix D =\n" << matrixD[0][0] << " " << matrixD[0][1] << "\n" << matrixD[1][0] << " " << matrixD[1][1] << std::endl;

  return 0;
}