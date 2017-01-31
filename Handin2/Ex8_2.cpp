// From Pitt-Francis and Whiteley, sec. 8.2, pp. 133f.
// Extended with a test of my solution of Exercise 8.2.
#include <iostream>
// #include "Exercise82.hpp"
using namespace std;

template<class T> T GetMaximum(T number1, T number2);
template<class T> T CalcAbs(T val);

int main(int argc, char * argv[])
{
  cout << GetMaximum<int>(10, -2) << "\n";
  cout << GetMaximum<double>(-4.6, 3.5) << "\n";

  cout << "CalcAbs(" << 10 << ") = " << CalcAbs<int>(10) << "\n";
  cout << "CalcAbs(" << -2 << ") = " << CalcAbs<int>(-2) << "\n";
  cout << "CalcAbs(" << -4.6 << ") = " << CalcAbs<double>(-4.6) << "\n";
  cout << "CalcAbs(" << 3.5 << ") = " << CalcAbs<double>(3.5) << "\n";

  int a = -10;
  double b = -10.0;
  cout << "a = " << a << ", CalcAbs(a) = " << CalcAbs(a) << endl;
  cout << "b = " << b << ", CalcAbs(b) = " << CalcAbs(b) << endl;

  int c = -0;
  double d = -0.0;
  cout << "c = " << c << ", CalcAbs(c) = " << CalcAbs(c) << endl;
  cout << "d = " << d << ", CalcAbs(d) = " << CalcAbs(d) << endl;

  cout << (-10<0) << endl;
  cout << (-4.6<0) << endl;

  return 0;
}

template<class T> T GetMaximum(T number1, T number2)
{
  T result;

  if (number1 > number2)
  {
    result = number1;
  }
  else
  {
    // number1 <= number2
    result = number2;
  }

  return result;
}

template<class T>
T CalcAbs(T val) {
  if (val > 0) {
    return val;
  }
  else {
    // if (val <= 0)
    return -val;
  }
}