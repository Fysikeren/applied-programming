#include "Matrix2x2.hpp"
#include <cmath>
#include <cassert>

// Override default constructor
// Set all entries to zero
Matrix2x2::Matrix2x2() {
  val00 = 0.0; // first row, first column
  val01 = 0.0; // first row, second column
  val10 = 0.0; // second row, first colum
  val11 = 0.0; // second row, second column
}

// Copy constructor
Matrix2x2::Matrix2x2(const Matrix2x2& other) {
  val00 = other.Getval00(); // first row, first column
  val01 = other.Getval01(); // first row, second column
  val10 = other.Getval10(); // second row, first colum
  val11 = other.Getval11(); // second row, second column
}

// Constructor that sets all entries to specific numbers
Matrix2x2::Matrix2x2(double a, double b, double c, double d) {
  val00 = a; // first row, first column
  val01 = b; // first row, second column
  val10 = c; // second row, first colum
  val11 = d; // second row, second column
}

// Calculate the determinant
double Matrix2x2::CalcDeterminant() const {
  return val00*val11 - val01*val10;
}

// Calculate the inverse (if it exists)
Matrix2x2 Matrix2x2::CalcInverse() const {
  double determinant = this->CalcDeterminant();
  assert(determinant != 0.0);

  double a = val11/determinant;
  double b = -val01/determinant;
  double c = -val10/determinant;
  double d = val00/determinant;

  Matrix2x2 inverse = Matrix2x2(a,b,c,d);

  return inverse;
}

// Overloaded assignment operator
Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z) {
  val00 = z.Getval00();
  val01 = z.Getval01();
  val10 = z.Getval10();
  val11 = z.Getval11();

  return *this;
}

// Overloaded unary subtraction operator
Matrix2x2 Matrix2x2::operator-() const {
  Matrix2x2 matrix(-val00,-val01,-val10,-val11);

  return matrix;
}

// Overloaded binary addition operator
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const {
  Matrix2x2 matrix(val00+z.Getval00(), val01+z.Getval01(), val10+z.Getval10(), val11+z.Getval11());

  return matrix;
}

// Overloaded binary subtraction operator
Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const {
  Matrix2x2 matrix(val00-z.Getval00(), val01-z.Getval01(), val10-z.Getval10(), val11-z.Getval11());

  return matrix;
}

// Multiply the matrix by a specified double precision floating point variable
void Matrix2x2::MultScalar(double scalar) {
  val00 *= scalar; // first row, first column
  val01 *= scalar; // first row, second column
  val10 *= scalar; // second row, first colum
  val11 *= scalar; // second row, second column
}

// Print the matrix
void Matrix2x2::Print() const {
  std::cout << val00 << ' ' << val01 << '\n';
  std::cout << val10 << ' ' << val11 << std::endl;
}