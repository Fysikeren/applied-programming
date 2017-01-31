#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main() {
  int N = 1e5; // Number of grid points.
  assert(N > 1);

  double h = 1/(double)(N-1); // The step size.

  // Opening a file to write to:
  ofstream write_output("xy.dat");
  assert(write_output.is_open());

  // Setting coordinates of first point and printing them to files:
  double x = 0;
  double y = 1;
  write_output << x << "," << y << "\n";

  // Finding the rest of the points:
  for (int i=1;i<N;i++) {
    x += h;
    y -= y*h;
    // y /= (h + 1.0);
    write_output << x << "," << y << "\n";
  }
  
  write_output.close();

  return 0;
}