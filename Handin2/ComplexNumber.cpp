#include "ComplexNumber.hpp"
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
   mRealPart = 0.0;
   mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
   mRealPart = x;
   mImaginaryPart = y;
}

// Copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
   mRealPart = z.GetRealPart();
   mImaginaryPart = z.GetImaginaryPart();
}

// Constructor that sets complex number z = real + 0i
ComplexNumber::ComplexNumber(double real)
{
   mRealPart = real;
   mImaginaryPart = 0;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
   return sqrt(mRealPart*mRealPart+
               mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
   return atan2(mImaginaryPart, mRealPart);
}

// Method for returning the real part of a
// complex number
double ComplexNumber::GetRealPart() const
{
   return mRealPart;
}

// Method for returning the imaginary part of a
// complex number
double ComplexNumber::GetImaginaryPart() const
{
   return mImaginaryPart;
}

// Friend function for returning the real part of a
// complex number
double RealPart(const ComplexNumber& z)
{
   return z.GetRealPart();
}

// Friend function for returning the imaginary part of a
// complex number
double ImaginaryPart(const ComplexNumber& z)
{
   return z.GetImaginaryPart();
}

// Method for returning the complex conjugate of a complex number
ComplexNumber ComplexNumber::CalculateConjugate() const
{
   ComplexNumber z(mRealPart, -1*mImaginaryPart); 
   return z; 
}

// Method for setting a complex number equal to its conjugate
void ComplexNumber::SetConjugate()
{
   mImaginaryPart = -1*mImaginaryPart;
}

// Method for raising complex number to the power n
// using De Moivre's theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
   double modulus = CalculateModulus();
   double argument = CalculateArgument();
   double mod_of_result = pow(modulus, n);
   double arg_of_result = argument*n;
   double real_part = mod_of_result*cos(arg_of_result);
   double imag_part = mod_of_result*sin(arg_of_result);
   ComplexNumber z(real_part, imag_part); 
   return z; 
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::
               operator=(const ComplexNumber& z)
{
   mRealPart = z.mRealPart;
   mImaginaryPart = z.mImaginaryPart;
   return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
   ComplexNumber w;
   w.mRealPart = -mRealPart;
   w.mImaginaryPart = -mImaginaryPart;
   return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::
              operator+(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart + z.mRealPart;
   w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
   return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::
              operator-(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart - z.mRealPart;
   w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
   return w;
}

// Overloading the binary * operator
ComplexNumber ComplexNumber::
              operator*(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart*z.mRealPart - mImaginaryPart*z.mImaginaryPart;
   w.mImaginaryPart = mRealPart*z.mImaginaryPart + mImaginaryPart*z.mRealPart;
   return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output, 
                         const ComplexNumber& z)
{
   // Format as "(a + bi)" or as "(a - bi)"
   output << "(" << z.mRealPart << " ";
   if (z.mImaginaryPart >= 0.0)
   {
      output << "+ " << z.mImaginaryPart << "i)";
   }
   else
   {
      // z.mImaginaryPart < 0.0
      // Replace + with minus sign 
      output << "- " << -z.mImaginaryPart << "i)";
   }

   return output;
}

// Function to allocate memory for a matrix dynamically
ComplexNumber** AllocateMatrixMemory() {
  ComplexNumber** matrix;
  matrix = new ComplexNumber * [3];

  for (int i=0; i<3; i++) {
    matrix[i] = new ComplexNumber [3];
  }
  return matrix;
}

// Function to free memory of a matrix
void FreeMatrixMemory(ComplexNumber** matrix) {
  for (int i=0; i<3; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}
