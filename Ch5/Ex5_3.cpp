#include <iostream>
using namespace std;

void swapwithpointers(double* n, double* m);
void swapwithreferences(double& n, double& m);

int main() {
  double n = 2.0, m = 3.0;
  cout << "n = " << n << " m = " << m << endl;

  swapwithpointers(&n, &m);
  cout << "n = " << n << " m = " << m << endl;

  swapwithreferences(n, m);
  cout << "n = " << n << " m = " << m << endl;

  return 0;
}

void swapwithpointers(double* n, double* m) {
  double *l = new double;

  *l = *n;
  *n = *m;
  *m = *l;

  delete l;
}

void swapwithreferences(double& n, double& m) {
  double l;

  l = n;
  n = m;
  m = l;
}