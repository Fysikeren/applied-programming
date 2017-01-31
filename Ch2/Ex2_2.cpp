#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	double p = 4, q = 4, x, y = 4;
  int j = 10;

  // Part 1:
  if ((p >= q) || (j != 10)) {x = 5;}
  else {x = 0;}
  cout << x << endl;

  // Part 2:
  if ((y >= q) && (j == 20)) {x = 5;}
  else {x = p;}
  cout << x << endl;

  // Part 3:
  if (p > q) {x = 0;}
  else if ((p <= q) && (j == 10)) {x = 1;}
  else {x = 2;}
  cout << x << endl;

	return 0;
}