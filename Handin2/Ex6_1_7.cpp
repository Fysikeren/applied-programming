#include "CalculateExponential.hpp"

int main() {
  ComplexNumber** A = AllocateMatrixMemory();

  A[0][0] = ComplexNumber(1,2); A[0][1] = ComplexNumber(2,1); A[0][2] = ComplexNumber(3,3);
  A[1][0] = ComplexNumber(0,1); A[1][1] = ComplexNumber(1,6); A[1][2] = ComplexNumber(4,0);
  A[2][0] = ComplexNumber(5,6); A[2][1] = ComplexNumber(6,5); A[2][2] = ComplexNumber(0,2);

  std::cout << "Initially, A = " << std::endl;
  printMatrix(A,3,3);

  ComplexNumber** res = AllocateMatrixMemory();
  std::cout << "Initially, res = " << std::endl;
  printMatrix(res,3,3);

  int nMax = 50;
  std::cout << "nMax = " << nMax << "\n" << std::endl;
  CalculateExponential(A, nMax, res);
  // MatrixPower(res,A,nMax);

  std::cout << "After exponentiation, A = " << std::endl;
  printMatrix(A,3,3);

  std::cout << "After exponentiation, res = " << std::endl;
  printMatrix(res,3,3);

  FreeMatrixMemory(A);
  FreeMatrixMemory(res);

  ComplexNumber** B = AllocateMatrixMemory();

  B[0][0] = ComplexNumber(2,3); B[0][1] = ComplexNumber(0,0); B[0][2] = ComplexNumber(0,0);
  B[1][0] = ComplexNumber(0,0); B[1][1] = ComplexNumber(4,5); B[1][2] = ComplexNumber(0,0);
  B[2][0] = ComplexNumber(0,0); B[2][1] = ComplexNumber(0,0); B[2][2] = ComplexNumber(6,7);

  std::cout << "Initially, B = " << std::endl;
  printMatrix(B,3,3);

  res = AllocateMatrixMemory();
  std::cout << "Initially, res = " << std::endl;
  printMatrix(res,3,3);

  std::cout << "nMax = " << nMax << "\n" << std::endl;
  CalculateExponential(B, nMax, res);

  std::cout << "After exponentiation, B = " << std::endl;
  printMatrix(B,3,3);

  std::cout << "After exponentiation, res = " << std::endl;
  printMatrix(res,3,3);

  FreeMatrixMemory(B);
  FreeMatrixMemory(res);

  return 0;
}