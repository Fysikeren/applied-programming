#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF
#include <cmath>
#include <iostream>
#include <cassert>

template <class T>
class Vector
{
private:
   T* mData; // data stored in vector
   int mSize; // size of vector
public:
   Vector(const Vector& otherVector);
   Vector(int size);
   ~Vector();

   int GetSize() const;

   T& operator[](int i); // zero-based indexing
   T Read(int i) const; // read-only zero-based indexing 
   T& operator()(int i); // one-based indexing

   Vector& operator=(const Vector& otherVector); // assignment
   Vector operator+() const; // unary +
   Vector operator-() const; // unary -
   Vector operator+(const Vector& v1) const; // binary +
   Vector operator-(const Vector& v1) const; // binary -

   Vector operator*(T a) const; // scalar multiplication
   T CalculateNorm(int p=2) const; // p-norm method

   template <class U>
   friend int length(const Vector<U>& v); // declare length function as a friend
};

// Overridden copy constructor
// Allocates memory for new vector, and copies
// entries of other vector into it
template <class T>
Vector<T>::Vector(const Vector& otherVector)
{
   mSize = otherVector.GetSize();
   mData = new T [mSize];
   for (int i=0; i<mSize; i++)
   {
      mData[i] = otherVector.mData[i];
   }
}

// Constructor for vector of a given size
// Allocates memory, and initialises entries
// to zero
template <class T>
Vector<T>::Vector(int size)
{
   assert(size > 0);
   mSize = size;
   mData = new T [mSize];
   for (int i=0; i<mSize; i++)
   {
      mData[i] = 0.0;
   }
}

// Overridden destructor to correctly free memory
template <class T>
Vector<T>::~Vector()
{
   delete[] mData;
}

// Method to get the size of a vector
template <class T>
int Vector<T>::GetSize() const
{
   return mSize;
}

// Overloading square brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
template <class T>
T& Vector<T>::operator[](int i)
{
   assert(i > -1);
   assert(i < mSize);
   return mData[i];
}

// Read-only variant of []
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
template <class T>
T Vector<T>::Read(int i) const
{
   assert(i > -1);
   assert(i < mSize);
   return mData[i];
}

// Overloading round brackets
// Note that this uses `one-based' indexing,
// and a check on the validity of the index
template <class T>
T& Vector<T>::operator()(int i)
{
   assert(i > 0);
   assert(i < mSize+1);
   return mData[i-1];
}

// Overloading the assignment operator
template <class T>
Vector<T>& Vector<T>::operator=(const Vector& otherVector)
{
   assert(mSize == otherVector.mSize);
   for (int i=0; i<mSize; i++)
   {
      mData[i] = otherVector.mData[i];
   }
   return *this;
}

// Overloading the unary + operator
template <class T>
Vector<T> Vector<T>::operator+() const
{
   Vector v(mSize);
   for (int i=0; i<mSize; i++)
   {
      v[i] = mData[i];
   }
   return v;
}

// Overloading the unary - operator
template <class T>
Vector<T> Vector<T>::operator-() const
{
   Vector v(mSize);
   for (int i=0; i<mSize; i++)
   {
      v[i] = -mData[i];
   }
   return v;
}

// Overloading the binary + operator
template <class T>
Vector<T> Vector<T>::operator+(const Vector& v1) const
{
   assert(mSize == v1.mSize);
   Vector v(mSize);
   for (int i=0; i<mSize; i++)
   {
      v[i] = mData[i] + v1.mData[i];
   }
   return v;
}

// Overloading the binary - operator
template <class T>
Vector<T> Vector<T>::operator-(const Vector& v1) const
{
   assert(mSize == v1.mSize);
   Vector v(mSize);
   for (int i=0; i<mSize; i++)
   {
      v[i] = mData[i] - v1.mData[i];
   }
   return v;
}

// Overloading scalar multiplication
template <class T>
Vector<T> Vector<T>::operator*(T a) const
{
   Vector<T> v(mSize);
   for (int i=0; i<mSize; i++)
   {
      v[i] = a*mData[i];
   }
   return v;
}

// Method to calculate norm (with default value p=2)
// corresponding to the Euclidean norm
template <class T>
T Vector<T>::CalculateNorm(int p) const
{
   T norm_val, sum = 0.0;
   for (int i=0; i<mSize; i++)
   {
      sum += pow(std::abs(mData[i]), p);
   }
   norm_val = pow(sum, 1.0/((T)(p)));
   return norm_val;
}

// MATLAB style friend to get the size of a vector
template <class T>
int length(const Vector<T>& v)
{
   return v.mSize;
}

#endif
