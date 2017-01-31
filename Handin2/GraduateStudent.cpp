#include "GraduateStudent.hpp"
#include <cmath>

GraduateStudent::GraduateStudent() : Student() {
  fullTime = true;
}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime) : Student(name, fines, fees) {
  this->fullTime = fullTime;
}

double GraduateStudent::MoneyOwed() const {
  return this->GetLibraryFines();
}