#include <iostream>
using namespace std;

void valueprinter(double* number);

int main() {
  double n = 2.0;

  valueprinter(&n);

  return 0;
}

void valueprinter(double* number) {
  cout << *number << endl;
}