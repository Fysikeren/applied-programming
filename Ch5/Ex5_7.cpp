#include <cmath>
#include <iostream>
#include <cassert>
using namespace std;

// Function to calculate the p-norm of a vector:
//= [ Sum_i ( |x_i|**p ) ] ** (1/p)
double CalculateNorm(double * x, int vecSize, int p = 2);

int main() {
  double A[5] = {5,4,3,5,6};
  cout << "The default norm is: " << CalculateNorm(A, 5) << endl;
  cout << "The 2-norm is: " << CalculateNorm(A, 5, 2) << endl;
  cout << "The 3-norm is: " << CalculateNorm(A, 5, 3) << endl;
  
  return 0;
}

double CalculateNorm(double * x, int vecSize, int p) {
  double sum = 0.0;
  // Loop over elems x_i of x, incrementing sum by |x_i|**p
  for (int i=0; i<vecSize; i++) {
    double temp = fabs(x[i]);
    sum += pow(temp, p);
  }
  // Return p-th root of sum
  return pow(sum, 1.0/p);
}