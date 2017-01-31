ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	clang++ -std=c++11 -c -O ComplexNumber.cpp

tester.o : tester.cpp ComplexNumber.hpp
	clang++ -std=c++11 -c -O tester.cpp

tester : ComplexNumber.o tester.o
	clang++ -std=c++11 -O -o tester ComplexNumber.o tester.o

Ex6_1_1.o : Ex6_1_1.cpp ComplexNumber.hpp
	clang++ -std=c++11 -c -O Ex6_1_1.cpp

Ex6_1_1 : ComplexNumber.o Ex6_1_1.o
	clang++ -std=c++11 -O -o Ex6_1_1 ComplexNumber.o Ex6_1_1.o