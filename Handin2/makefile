all : Ex6_1 Ex6_1_7 Ex6_2 Ex7_1 Ex8_2 Ex9_1

ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	clang++ -std=c++11 -c -O ComplexNumber.cpp

CalculateExponential.o : CalculateExponential.cpp CalculateExponential.hpp
	clang++ -std=c++11 -c -O CalculateExponential.cpp

Ex6_1.o : Ex6_1.cpp ComplexNumber.hpp
	clang++ -std=c++11 -c -O Ex6_1.cpp

Ex6_1 : ComplexNumber.o Ex6_1.o
	clang++ -std=c++11 -O -o Ex6_1 ComplexNumber.o Ex6_1.o

Ex6_1_7.o : Ex6_1_7.cpp ComplexNumber.hpp CalculateExponential.hpp
	clang++ -std=c++11 -c -O Ex6_1_7.cpp

Ex6_1_7 : ComplexNumber.o CalculateExponential.o Ex6_1_7.o
	clang++ -std=c++11 -O -o Ex6_1_7 ComplexNumber.o CalculateExponential.o Ex6_1_7.o

Matrix2x2.o : Matrix2x2.cpp Matrix2x2.hpp
	clang++ -std=c++11 -c -O Matrix2x2.cpp

Ex6_2.o : Ex6_2.cpp Matrix2x2.hpp
	clang++ -std=c++11 -c -O Ex6_2.cpp

Ex6_2 : Matrix2x2.o Ex6_2.o
	clang++ -std=c++11 -O -o Ex6_2 Matrix2x2.o Ex6_2.o

Student.o : Student.cpp Student.hpp
	clang++ -std=c++11 -c -O Student.cpp

GraduateStudent.o : GraduateStudent.cpp GraduateStudent.hpp
	clang++ -std=c++11 -c -O GraduateStudent.cpp

PhdStudent.o : PhdStudent.cpp PhdStudent.hpp
	clang++ -std=c++11 -c -O PhdStudent.cpp

Ex7_1.o : Ex7_1.cpp Student.hpp GraduateStudent.hpp PhdStudent.hpp
	clang++ -std=c++11 -c -O Ex7_1.cpp

Ex7_1 : Student.o GraduateStudent.o PhdStudent.o Ex7_1.o
	clang++ -std=c++11 -O -o Ex7_1 Student.o GraduateStudent.o PhdStudent.o Ex7_1.o

Ex8_2 : Ex8_2.cpp Exercise82.hpp
	clang++ -std=c++11 -o Ex8_2 Ex8_2.cpp

Exception.o : Exception.cpp Exception.hpp
	clang++ -std=c++11 -c -O Exception.cpp

OutOfRangeException.o : OutOfRangeException.cpp OutOfRangeException.hpp
	clang++ -std=c++11 -c -O OutOfRangeException.cpp

FileNotOpenException.o : FileNotOpenException.cpp FileNotOpenException.hpp
	clang++ -std=c++11 -c -O FileNotOpenException.cpp

Ex9_1.o : Ex9_1.cpp Exception.cpp OutOfRangeException.cpp FileNotOpenException.cpp
	clang++ -std=c++11 -c -O Ex9_1.cpp

Ex9_1 : Ex9_1.o Exception.o OutOfRangeException.o FileNotOpenException.o
	clang++ -std=c++11 -O -o Ex9_1 Exception.o OutOfRangeException.o FileNotOpenException.o Ex9_1.o