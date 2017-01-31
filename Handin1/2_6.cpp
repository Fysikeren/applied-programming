#include "2_6.h"
#include <iostream>
#include <cmath>

double newton_Raphson(double initialGuess, double epsilon) {
  double x_prev, x_next = initialGuess;

  do {
    x_prev = x_next;
    x_next = x_prev - (exp(x_prev) + pow(x_prev,3.0) - 5)/(exp(x_prev) + 3*pow(x_prev,2.0));
  } while (fabs(x_next - x_prev) > epsilon);

  return x_next;
}