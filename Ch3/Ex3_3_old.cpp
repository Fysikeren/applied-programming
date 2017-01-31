#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {
  int N = 1e4; // Number of grid points.
  assert(N > 1);
//  cout << "Please enter the number of grid points, N:" << endl;
//  cin >> N;

  double h = 1/(double)(N-1); // The step size.
  // double x[N], y[N]; // Arrays for storing the solution.

  // Opening a file to write to:
  ofstream write_output("xy.dat");
  assert(write_output.is_open());
  // write_output.setf(ios::scientific);
  // write_output.setf(ios::showpos);
  // write_output.precision(13);

  // Setting first entry in the arrays and printing them to files:
  // x[0] = 0;
  // y[0] = 1;
  double x, x_old = 0;
  double y, y_old = 1;
  write_output << x_old << "," << y_old << "\n";
  // write_output << x[0] << "," << y[0] << "\n";
  // write_output << x[0] << "," << y[0] << "," <<  exp(-x[0]) << "\n";

  for (int i=1;i<N;i++) {
    // x[i] = i*h;
    // y[i] = y[i-1] / (h+1.0);
    // y[i] = y[i-1] - h*y[i-1];
    // write_output << x[i] << "," << y[i] << "\n";
    // write_output << x[i] << "," << y[i] << "," <<  exp(-x[i]) << "\n";
    x = i*h;
    y = y_old*(1 - h);
    write_output << x << "," << y << "\n";
    y_old = y;
  }
  
  write_output.close();

  return 0;
}