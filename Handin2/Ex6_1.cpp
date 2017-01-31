#include "ComplexNumber.hpp"

int main() {
  ComplexNumber z1(4.0, 3.0);

  std::cout << "z1 = " << z1 << "\n";
  std::cout << "Reading by method:\n";
  std::cout << "Re{z1} = " << z1.GetRealPart() << "\n";
  std::cout << "Im{z1} = " << z1.GetImaginaryPart() << std::endl;
  std::cout << "Reading by friend function:\n";
  std::cout << "Re{z1} = " << RealPart(z1) << "\n";
  std::cout << "Im{z1} = " << ImaginaryPart(z1) << std::endl;

  ComplexNumber z2(z1);
  std::cout << "z2 = " << z2 << "\n";

  ComplexNumber z3(5);
  std::cout << "z3 = " << z3 << "\n";

  ComplexNumber z4 = z1.CalculateConjugate();
  std::cout << "z4 = " << z4 << "\n";

  z4.SetConjugate();
  std::cout << "z4 = " << z4 << "\n";

  std::cout << "z1*z4 = " << z1*z4 << "\n";
  std::cout << "z1*z3 = " << z1*z3 << "\n";
  std::cout << "z1*z4_conj = " << z1*z4.CalculateConjugate() << "\n";

  return 0;
}