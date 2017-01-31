#include "Matrix2x2.hpp"

int main() {
  std::cout << 5 << std::endl;

  Matrix2x2 FirstMatrix(2.0,3.0,2.0,1.0);
  FirstMatrix.Print();

  Matrix2x2 SecondMatrix(FirstMatrix);
  SecondMatrix.Print();

  std::cout << SecondMatrix.CalcDeterminant() << std::endl;

  Matrix2x2 ThirdMatrix = SecondMatrix.CalcInverse();
  ThirdMatrix.Print();

  Matrix2x2 FourthMatrix = FirstMatrix;
  FourthMatrix.Print();

  Matrix2x2 FifthMatrix = -ThirdMatrix;
  FifthMatrix.Print();

  Matrix2x2 SixthMatrix = SecondMatrix + ThirdMatrix;
  SixthMatrix.Print();

  Matrix2x2 SeventhMatrix = SecondMatrix - ThirdMatrix;
  SeventhMatrix.Print();

  SeventhMatrix.MultScalar(5.0);
  SeventhMatrix.Print();

  return 0;
}