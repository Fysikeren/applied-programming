#include <iostream>

int main()
{
  int A, B;

  std::cout << "This program multiplies two intergers.\n";
  std::cout << "Please enter the first interger: ";
  std::cin >> A;
  std::cout << "Please enter the second interger: ";
  std::cin >> B;
  std::cout << "The product of those integers is " << A*B << "." << std::endl;

  return 0;
}