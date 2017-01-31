#ifndef _CALCULATEEXPONENTIAL_
#define _CALCULATEEXPONENTIAL_

#include "ComplexNumber.hpp"

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res);

// non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols);

void Multiply(ComplexNumber **res, ComplexNumber **A, ComplexNumber **B);
void MatrixPower(ComplexNumber **res, ComplexNumber **A, int n);

#endif
