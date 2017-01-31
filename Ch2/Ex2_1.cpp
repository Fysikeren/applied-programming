#include <iostream>
using namespace std;

int main() {
  double x = 20, y = 20, z;

  /* 1) Explanation of the following code fragment:
  It looks at the variables x and y. If x is the largest OR x is smaller than 5.0, then the variable z is set equal to 4.0. If neigther of these requirements are met, z is set equal to 2.0. */
  if ((x > y) || (x < 5.0)) {
    z = 4.0;
  }
  else {
    z = 2.0;
  }

  /* 2) What would happen in specific circunstances?
  If x is 10.0 and y is -1.0, z becomes 4.0
  If x is 10.0 and y is 20.0, z becomes 2.0
  If x is  0.0 and y is 20.0, z becomes 4.0 */

  cout << z << endl;

  // 3) I then modify the code:
  if ((x >= y) || (x < 5.0)) {
    z = 4.0;
  }
  else {
    z = 2.0;
  }

  cout << z << endl;

  return 0;
}