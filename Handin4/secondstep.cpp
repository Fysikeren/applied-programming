#include "Vector.hpp"
#include "Matrix.hpp"
using namespace std;

int main(int argc,char const* argv[])
{
  cout << "Testing vectors:" << endl;
  Vector<float> v(2);
  v(1) = 3.14;
  cout << v(1) << "=" << v[0] << "=" << v.Read(0) << endl;
  cout << v.GetSize() << endl;

  Vector<float> u(2);
  u = -v;
  cout << u(1) << "=" << u[0] << "=" << u.Read(0) << endl;
  cout << u(2) << "=" << u[1] << "=" << u.Read(1) << endl;
  cout << u.GetSize() << endl;

  Vector<float> w(2);
  w = u - v + v;
  cout << w(1) << "=" << w[0] << "=" << w.Read(0) << endl;
  cout << w(2) << "=" << w[1] << "=" << w.Read(1) << endl;
  cout << w.GetSize() << endl;

  Vector<float> x(2);
  float a = 10;
  x = u*a;
  cout << x(1) << "=" << x[0] << "=" << x.Read(0) << endl;
  cout << x(2) << "=" << x[1] << "=" << x.Read(1) << endl;
  cout << x.GetSize() << endl;

  x(2) = a;
  cout << x.CalculateNorm() << endl;

  Vector<float> y(2);
  // y = Vector(v);

  cout << length(v) << endl;

  // Vector v(2);
  // v(1) = 3.51;

  cout << "\nTesting matrices:" << endl;
  Matrix<float> m(2,2,0);
  m(1,1) = 31;
  m(1,2) = 23;
  m(2,2) = 13;
  cout << m(1,1) << " " << m(1,2) << endl;
  cout << m(2,1) << " " << m(2,2) << endl;
  cout << m.GetNumberOfRows() << " " << m.GetNumberOfColumns() << endl;
  // << "=" << v[0] << "=" << v.Read(0) << endl;

  Matrix<float> n(2,2,0);
  n = m;
  cout << n(1,1) << " " << n(1,2) << endl;
  cout << n(2,1) << " " << n(2,2) << endl;

  Matrix<float> l(2,2,0);
  l = +m;
  cout << l(1,1) << " " << l(1,2) << endl;
  cout << l(2,1) << " " << l(2,2) << endl;

  Matrix<float> o(2,2,0);
  o = -m;
  cout << o(1,1) << " " << o(1,2) << endl;
  cout << o(2,1) << " " << o(2,2) << endl;

  l = l + m;
  cout << l(1,1) << " " << l(1,2) << endl;
  cout << l(2,1) << " " << l(2,2) << endl;

  o = l - m;
  cout << o(1,1) << " " << o(1,2) << endl;
  cout << o(2,1) << " " << o(2,2) << endl;

  o = l*a;
  cout << o(1,1) << " " << o(1,2) << endl;
  cout << o(2,1) << " " << o(2,2) << endl;

  cout << m.CalculateDeterminant() << endl;
  cout << n.CalculateDeterminant() << endl;
  cout << l.CalculateDeterminant() << endl;
  cout << o.CalculateDeterminant() << endl;

  w = v*m;
  cout << w(1) << "=" << w[0] << "=" << w.Read(0) << endl;
  cout << w(2) << "=" << w[1] << "=" << w.Read(1) << endl;

  w = m*v;
  cout << w(1) << "=" << w[0] << "=" << w.Read(0) << endl;
  cout << w(2) << "=" << w[1] << "=" << w.Read(1) << endl;

  return 0;
}