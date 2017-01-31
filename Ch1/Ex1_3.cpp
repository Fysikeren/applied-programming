#include <iostream>
#include <cmath>

int main() {
	double array1[3] = {5.0, 1.0, 2.0};
	double array2[3] = {3.0, 2.0, 1.0};

  double scalarprod = array1[0]*array2[0] + array1[1]*array2[1] + array1[2]*array2[2];
  std::cout << "The scalar product is " << scalarprod << "." << std::endl;

  double norm1 = sqrt(array1[0]*array1[0] + array1[1]*array1[1] + array1[2]*array1[2]);
  std::cout << "The norm of the first array is " << norm1 << "." << std::endl;

  double norm2 = sqrt(array2[0]*array2[0] + array2[1]*array2[1] + array2[2]*array2[2]);
  std::cout << "The norm of the second array is " << norm2 << "." << std::endl;

  return 0;
}