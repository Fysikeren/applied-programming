#include <iostream>
using namespace std;

int main() {
  double *x, *y;

  for (int j=0;j<1e9;j++) {
    x = new double [3];
    y = new double [3];
    for (int i = 0;i<3;i++) {
      x[i] = i;
      y[i] = i*i;
    }
    // cout << x[1]*y[1] + x[2]*y[2] + x[3]*y[3] << endl;
    delete x;
    delete y;
  }

	return 0;
}