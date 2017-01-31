#include <iostream>
using namespace std;

int main() {
  int i = 1, j = 5;
  int *p_i = &i, *p_j = &j, *p_k = new int;

  cout << "i =  " << *p_i << endl;
  cout << "j =  " << *p_j << endl;

  *p_k = *p_i;
  *p_i = *p_j;
  *p_j = *p_k;

  cout << "i =  " << i << endl;
  cout << "j =  " << j << endl;

	return 0;
}