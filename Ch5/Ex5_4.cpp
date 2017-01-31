#include <iostream>
#include <cmath>
using namespace std;

double calc_std(double a[], int length);
double calc_mean(double a[], int length);

int main() {
  double mean, standarddev;

  double A[5] = {1,3,2,2,2};
  mean = calc_mean(A, 5);
  cout << "The mean of A is " << mean << "." << endl;
  standarddev = calc_std(A, 5);
  cout << "The standard deviation of A is " << standarddev << "." << endl;

  double B[1] = {5};
  mean = calc_mean(B, 1);
  cout << "The mean of B is " << mean << "." << endl;
  standarddev = calc_std(B, 1);
  cout << "The standard deviation of B is " << standarddev << "." << endl;

  double C[3] = {4,4,4};
  mean = calc_mean(C, 3);
  cout << "The mean of C is " << mean << "." << endl;
  standarddev = calc_std(C, 3);
  cout << "The standard deviation of C is " << standarddev << "." << endl;

  return 0;
}

double calc_mean(double a[], int length) {
  double mean = 0;

  for (int i=0; i<length; i++) {
    mean += a[i];
  }

  mean /= length;

  return mean;
}

double calc_std(double a[], int length) {
  double standarddev;

  if (length == 1) {
    standarddev = 0.0;
  }
  else {
    double mean = calc_mean(a, length);
    double sum = 0;

    for (int i=0; i<length; i++) {
      sum += (a[i] - mean)*(a[i] - mean);
    }

    standarddev = pow(sum/(double)(length-1),1/2.0);
  }
  
  return standarddev;
}