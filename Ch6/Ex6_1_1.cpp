#include "ComplexNumber.hpp"

int main() {
  ComplexNumber z1(4.0, 3.0);

  std::cout << "z1 = " << z1 << "\n";
  std::cout << "Re{z1} = " << z1.GetRealPart() << "\n";
  std::cout << "Im{z1} = " << z1.GetImaginaryPart() << std::endl;

  std::cout << "z1 = " << z1 << "\n";
  std::cout << "Re{z1} = " << RealPart(z1) << "\n";
  std::cout << "Im{z1} = " << ImaginaryPart(z1) << std::endl;

  return 0;
}