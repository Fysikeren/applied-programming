#include <cmath>
#include "5_4.h"

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