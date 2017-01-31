#include "2_6.h"
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {
  double x_final = newton_Raphson(0.0, 1e-3);
  
  cout << "x_final = " << x_final << endl;
  double x_naught = 0.0, x_prev, x_next = x_naught;
  // double xx[100];

  // for (int i=0;i<100;i++) {
    // x_next = x_prev - (exp(x_prev) + pow(x_prev,3.0) - 5)/(exp(x_prev) + 3*pow(x_prev,2.0));
    // xx[i] = x_next;
    // cout << xx[i] << endl;
    // x_prev = x_next;
  // }

  double epsilon = 1e-30;
  do {
    x_prev = x_next;
    x_next = x_prev - (exp(x_prev) + pow(x_prev,3.0) - 5)/(exp(x_prev) + 3*pow(x_prev,2.0));
    cout << "x_next - x_prev = " << fabs(x_next - x_prev) << endl;
  } while (fabs(x_next - x_prev) > epsilon);

  cout << "x_next = " << x_next << endl;

  return 0;
}