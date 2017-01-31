// Solved by help from http://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream read_file("x_and_y.dat");
  if (!read_file.is_open()) {
    return 1;
  }

  int number_of_rows = 0;

  double dummy1, dummy2, dummy3, dummy4;
  while (read_file >> dummy1 >> dummy2 >> dummy3 >> dummy4) {
    number_of_rows++;
    cout << dummy1 << " " << dummy2 << " " << dummy3 << " " << dummy4 << endl;
    cout << read_file.eof() << endl;
  }

  cout << "Number of rows = " << number_of_rows << endl;

  read_file.close();

  return 0;
}