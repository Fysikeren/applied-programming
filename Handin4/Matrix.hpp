#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include <cmath>
#include <cassert>
#include <vector>
#include "Vector.hpp"

template <class T>
class Matrix
{
private:
  std::vector<T> mData; // entries of matrix
  int mNumRows, mNumCols; // dimensions
  bool isRowMajor;
public:
  Matrix(int numRows, int numCols, bool rowMajor);
  ~Matrix();
  
  int GetNumberOfRows() const;
  int GetNumberOfColumns() const;

  T& operator()(int i, int j); // one-based indexing

  Matrix& operator=(const Matrix& otherMatrix); // overloaded assignment operator
  Matrix operator+() const; // unary +
  Matrix operator-() const; // unary -
  Matrix operator+(const Matrix& m1) const; // binary +
  Matrix operator-(const Matrix& m1) const; // binary -
  Matrix operator*(T a) const; // scalar multiplication

  T CalculateDeterminant() const;

  // declare vector multiplication friendship:
  template <class U>
  friend Vector<U> operator*(const Matrix<U>& m, 
                        const Vector<U>& v);
  template <class U>
  friend Vector<U> operator*(const Vector<U>& v, 
                        const Matrix<U>& m);

  // new public functions in Matrix.hpp
  std::vector<T> getData() const;
  bool getOrder() const;
};

// Constructor for vector of a given length
// Allocates memory, and initialises entries
// to zero
template <class T>
Matrix<T>::Matrix(int numRows, int numCols, bool rowMajor)
{
  assert(numRows > 0);
  assert(numCols > 0);
  mNumRows = numRows;
  mNumCols = numCols;
  isRowMajor = rowMajor;

  mData.assign(mNumRows*mNumCols,0);
}

// Overwritten destructor to correctly free memory
template <class T>
Matrix<T>::~Matrix()
{
}

// Method to get number of rows of matrix
template <class T>
int Matrix<T>::GetNumberOfRows() const
{
  return mNumRows;
}

// Method to get number of columns of matrix
template <class T>
int Matrix<T>::GetNumberOfColumns() const
{
  return mNumCols;
}

// Overloading the round brackets
// Note that this uses `one-based' indexing,
// and a check on the validity of the index
template <class T>
T& Matrix<T>::operator()(int i, int j)
{
  assert(i > 0);
  assert(i < mNumRows+1);
  assert(j > 0);
  assert(j < mNumCols+1);

  if (isRowMajor) {
    return mData[(i-1)*mNumCols+j-1];
  }

  return mData[(j-1)*mNumRows+i-1];
}

// Overloading the assignment operator
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& otherMatrix)
{
  assert(mNumRows = otherMatrix.mNumRows);
  assert(mNumCols = otherMatrix.mNumCols);

  mData = otherMatrix.mData;
  isRowMajor = otherMatrix.isRowMajor;

  return *this;
}

// Overloading the unary + operator
template <class T>
Matrix<T> Matrix<T>::operator+() const
{
  Matrix<T> mat(mNumRows, mNumCols, isRowMajor);

  for (int i=0; i<mNumRows*mNumCols; i++)
  {
    mat.mData[i] = mData[i];
  }

  return mat;
}

// Overloading the unary - operator
template <class T>
Matrix<T> Matrix<T>::operator-() const
{
  Matrix<T> mat(mNumRows, mNumCols, isRowMajor);

  for (int i=0; i<mNumRows*mNumCols; i++)
  {
    mat.mData[i] = -mData[i];
  }

  return mat;
}

// Overloading the binary + operator
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix& m1) const
{
  assert(mNumRows == m1.mNumRows);
  assert(mNumCols == m1.mNumCols);
  Matrix<T> mat(mNumRows, mNumCols, isRowMajor);

  for (int i=0; i<mNumRows*mNumCols; i++)
  {
    mat.mData[i] = mData[i] + m1.mData[i];
  }

  return mat;
}

// Overloading the binary - operator
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix& m1) const
{
  assert(mNumRows == m1.mNumRows);
  assert(mNumCols == m1.mNumCols);
  Matrix<T> mat(mNumRows, mNumCols, isRowMajor);

  for (int i=0; i<mNumRows*mNumCols; i++)
  {
    mat.mData[i] = mData[i] - m1.mData[i];
  }

  return mat;
}

// Overloading scalar multiplication
template <class T>
Matrix<T> Matrix<T>::operator*(T a) const
{
  Matrix<T> mat(mNumRows, mNumCols, isRowMajor);

  for (int i=0; i<mNumRows*mNumCols; i++)
  {
    mat.mData[i] = a*mData[i];
  }

  return mat;
}

// Calculate determinant of square matrix recursively
template <class T>
T Matrix<T>::CalculateDeterminant() const
{
  assert(mNumRows == mNumCols);
  T determinant = 0.0;

  if (mNumRows == 1)
  {
    determinant = mData[0];
  }
  else
  {
    // More than one entry of matrix
    for (int i_outer=0; i_outer<mNumRows; i_outer++)
    {
      Matrix sub_matrix(mNumRows-1, mNumRows-1, 1);
      for (int i=0; i<mNumRows-1; i++)
      {
         for (int j=0; j<i_outer; j++)
         {
            // sub_matrix(i+1,j+1) = mData[i+1][j];
            sub_matrix(i+1,j+1) = mData[(i+1)*mNumCols+j];
         }
         for (int j=i_outer; j<mNumRows-1; j++)
         {
            // sub_matrix(i+1,j+1) = mData[i+1][j+1];
            sub_matrix(i+1,j+1) = mData[(i+1)*mNumCols+j+1];
         }
      }
      T sub_matrix_determinant = 
               sub_matrix.CalculateDeterminant();

      determinant += pow(-1.0, i_outer)*
               // mData[0][i_outer]*sub_matrix_determinant;
               mData[i_outer]*sub_matrix_determinant;
    }
  }
  return determinant;
}

// Overloading matrix multiplied by a vector
template <class T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
  int original_vector_size = v.GetSize();
  assert(m.GetNumberOfColumns() == original_vector_size);
  int new_vector_length = m.GetNumberOfRows();
  Vector<T> new_vector(new_vector_length);

  if (m.getOrder())
  {
  for (int i=0; i<new_vector_length; i++)
  {
    for (int j=0; j<original_vector_size; j++)
    {
      // new_vector[i] += m.mData[i][j]*v.Read(j);
      new_vector[i] += m.mData[i*m.mNumCols+j]*v.Read(j);
    }
  }

  return new_vector;
  }

  for (int i=0; i<new_vector_length; i++)
  {
    for (int j=0; j<original_vector_size; j++)
    {
      // new_vector[i] += m.mData[i][j]*v.Read(j);
      new_vector[i] += m.mData[j*m.mNumRows+i]*v.Read(j);
    }
  }

  return new_vector;
}

// Overloading vector multiplied by a matrix
template <class T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
  int original_vector_size = v.GetSize();
  assert(m.GetNumberOfRows() == original_vector_size);
  int new_vector_length = m.GetNumberOfColumns();
  Vector<T> new_vector(new_vector_length);

  if (m.getOrder())
  {
     for (int i=0; i<new_vector_length; i++)
     {
       for (int j=0; j<original_vector_size; j++)
       {
         // new_vector[i] += v.Read(j)*m.mData[j][i];
         new_vector[i] += v.Read(j)*m.mData[j*m.mNumCols+i];
       }
     }

     return new_vector;
  }

  for (int i=0; i<new_vector_length; i++)
  {
    for (int j=0; j<original_vector_size; j++)
    {
      // new_vector[i] += v.Read(j)*m.mData[j][i];
      new_vector[i] += v.Read(j)*m.mData[i*m.mNumRows+j];
    }
  }

  return new_vector;
}

// Method returning the vector containing the data
template <class T>
std::vector<T> Matrix<T>::getData() const
{
   return mData;
}

// Method returning the order of the matrix.
// 0 = column major, 1 = rowmajor.
template <class T>
bool Matrix<T>::getOrder() const
{
   return isRowMajor;
}

#endif
