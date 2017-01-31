#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhdStudent.hpp"
#include <iostream>
using namespace std;

int main() {
  Student newStudent;

  cout << "The student is called " << newStudent.name << endl;
  cout << "The student has tuition fees of " << newStudent.tuition_fees << endl;
  cout << "The student owes " << newStudent.GetLibraryFines() << " in library fines." << endl;
  cout << "In total, the student owes " << newStudent.MoneyOwed() << endl;

  newStudent.name = "Test";
  newStudent.tuition_fees = 20e3;
  newStudent.SetLibraryFines(20);

  cout << "\n";
  cout << "The student is called " << newStudent.name << endl;
  cout << "The student has tuition fees of " << newStudent.tuition_fees << endl;
  cout << "The student owes " << newStudent.GetLibraryFines() << " in library fines." << endl;
  cout << "In total, the student owes " << newStudent.MoneyOwed() << endl;

  Student secondStudent = Student("Other", 15, 25e3);

  cout << "\n";
  cout << "The student is called " << secondStudent.name << endl;
  cout << "The student has tuition fees of " << secondStudent.tuition_fees << endl;
  cout << "The student owes " << secondStudent.GetLibraryFines() << " in library fines." << endl;
  cout << "In total, the student owes " << secondStudent.MoneyOwed() << endl;

  GraduateStudent newGraduateStudent;

  cout << "\n";
  cout << "The graduate student is called " << newGraduateStudent.name << endl;
  cout << "The graduate student has tuition fees of " << newGraduateStudent.tuition_fees << endl;
  cout << "The graduate student owes " << newGraduateStudent.GetLibraryFines() << " in library fines." << endl;
  cout << "In total, the graduate student owes " << newGraduateStudent.MoneyOwed() << endl;
  cout << "Is the graduate student full time? " << newGraduateStudent.fullTime << endl;

  newGraduateStudent.name = "Test";
  newGraduateStudent.tuition_fees = 20e3;
  newGraduateStudent.SetLibraryFines(20);
  newGraduateStudent.fullTime = false;

  cout << "\n";
  cout << "The graduate student is called " << newGraduateStudent.name << endl;
  cout << "The graduate student has tuition fees of " << newGraduateStudent.tuition_fees << endl;
  cout << "The graduate student owes " << newGraduateStudent.GetLibraryFines() << " in library fines." << endl;
  cout << "In total, the graduate student owes " << newGraduateStudent.MoneyOwed() << endl;
  cout << "Is the graduate student full time? " << newGraduateStudent.fullTime << endl;

  newGraduateStudent = GraduateStudent("Other", 26, 35e3, false);

  cout << "\n";
  cout << "The graduate student is called " << newGraduateStudent.name << endl;
  cout << "The graduate student has tuition fees of " << newGraduateStudent.tuition_fees << endl;
  cout << "The graduate student owes " << newGraduateStudent.GetLibraryFines() << " in library fines." << endl;
  cout << "In total, the graduate student owes " << newGraduateStudent.MoneyOwed() << endl;
  cout << "Is the graduate student full time? " << newGraduateStudent.fullTime << endl;

  PhdStudent newPhdStudent = PhdStudent("Other", 30, 15e3, false);

  cout << "\n";
  cout << "The PhD student is called " << newPhdStudent.name << endl;
  cout << "The PhD student has tuition fees of " << newPhdStudent.tuition_fees << endl;
  cout << "The PhD student owes " << newPhdStudent.GetLibraryFines() << " in library fines." << endl;
  cout << "In total, the PhD student owes " << newPhdStudent.MoneyOwed() << endl;
  cout << "Is the PhD student full time? " << newPhdStudent.fullTime << endl;

  Student* me = new GraduateStudent("Mathias", 35, 3e3, false);

  cout << "\n";
  cout << "My name is " << me->name << endl;
  cout << "I owe " << me->GetLibraryFines() << " in library fines." << endl;
  cout << "I've accomulated " << me->tuition_fees << " in tuition fees." << endl;
  cout << "I owe " << me->MoneyOwed() << " in total." << endl;
  // cout << "Am I a full time student? " << me->fullTime << endl;

  return 0;
}