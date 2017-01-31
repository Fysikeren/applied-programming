#include <iostream>
using namespace std;

void valuechanger(double* number);

int main() {
  double n = 2.0;
  cout << "n = " << n << endl;

  valuechanger(&n);
  cout << "n = " << n << endl;

  return 0;
}

void valuechanger(double* number) {
  *number = 3.0;
}