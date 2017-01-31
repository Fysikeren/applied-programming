#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
  double A[2][2] = {{4.0,10.0},{1.0,1.0}};
  double Ainv[2][2];

  double det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
  cout << "The determinant of A is " << det << "." << endl;

  assert(fabs(det - 0.0) > 1.0e-8);

  Ainv[0][0] =  A[1][1]/det;
  Ainv[1][1] =  A[0][0]/det;
  Ainv[0][1] = -A[1][0]/det;
  Ainv[1][0] = -A[0][1]/det;
  cout << "The inverse of A is:\nAinv = (" << Ainv[0][0] << " " << Ainv[0][1] << "\n " << "        " << Ainv[1][0] << " " << Ainv[1][1] << ")" << endl;

  return 0;
}