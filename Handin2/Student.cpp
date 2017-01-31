#include "Student.hpp"
#include <cmath>

Student::Student() {
  name = "name";
  library_fines = 0.0;
  tuition_fees = 0.0;
}

Student::Student(std::string name, double fines, double fees) {
  this->name = name;
  library_fines = fines;
  tuition_fees = fees;
}

double Student::MoneyOwed() const {
  return tuition_fees + library_fines;
}

void Student::SetLibraryFines(double amount) {
  if (amount >= 0.0) {
    library_fines = amount;
  }
}

double Student::GetLibraryFines() const {
  return library_fines;
}