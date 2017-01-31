#include <iostream>
using namespace std;

int main() {
  int i = 5;
  int* p_j = &i;
  cout << "i = " << i << endl;

  *p_j = *p_j*5;
  cout << "i = " << i << endl;

  int *p_k;
  p_k = new int;
  *p_k = i;
  cout << "*p_k = " << *p_k << endl;
  cout << "i = " << i << endl;
  delete p_k;

  cout << "*p_k = " << *p_k << endl;
  cout << "i = " << i << endl;

	return 0;
}