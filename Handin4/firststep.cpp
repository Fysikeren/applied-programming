#include "Matrix.hpp"
using namespace std;

int main() {
  // Matrix<int>m(2,2); // columnmajor
  Matrix<int>m(2,2,0); // columnmajor
  m(2,1) = 1337;

  // Matrix<int>m2(2,2); // rowmajor
  Matrix<int>m2(2,2,1); // rowmajor
  m2(2,1) = 1337;

  cout << m.GetNumberOfColumns() << ' ' << m.GetNumberOfColumns() << endl;
  for (int i=1; i<3; i++) {
    for (int j=1; j<3; j++) {
      cout << "m(" << i << "," << j << ") = " << m(i,j) << endl;
    }
  }
  cout << "m.getOrder() = " << m.getOrder() << endl;

  cout << m2.GetNumberOfColumns() << ' ' << m2.GetNumberOfColumns() << endl;

  for (int i=1; i<3; i++) {
    for (int j=1; j<3; j++) {
      cout << "m2(" << i << "," << j << ") = " << m2(i,j) << endl;
    }
  }
  cout << "m2.getOrder() = " << m2.getOrder() << endl;

  assert(m.getOrder()==0);
  assert(m2.getOrder()==1);

  vector<int> g = m.getData();
  cout << g[2] << endl;
  vector<int> h = m.getData();
  cout << h[1] << endl;

  cout << "m.getData()[1] = " << m.getData()[1] << endl;

  assert(m.getData()[1]==m(2,1));
  assert(m(2,1)==1337);
  assert(m.getData()[1]==1337);

  cout << "m2.getData()[2] = " << m2.getData()[2] << endl;

  assert(m2.getData()[2]==m2(2,1));
  assert(m2(2,1)==1337);
  assert(m2.getData()[2]==1337);

  m2 = m;

  for (int i=1; i<3; i++) {
    for (int j=1; j<3; j++) {
      cout << "m2(" << i << "," << j << ") = " << m2(i,j) << endl;
    }
  }
  cout << "m2.getOrder() = " << m2.getOrder() << endl;

  return 0;
}