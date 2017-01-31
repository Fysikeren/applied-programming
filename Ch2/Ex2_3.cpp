#include <iostream>
using namespace std;

int func1() { // Part 1.
  int sum = 0, num = 0;

  cout << "This program calculates the sum of positive integers.\nPlease enter the integers you want summed.\nEntering -1 terminates the summation." << endl;

  do {
    sum += num;
    cin >> num;
  } while (num != -1);

  cout << "The sum is " << sum << "." << endl;

  return 0;
}

int func2() { // Part 2.
  int sum = 0, num = 0;

  cout << "This program calculates the sum of positive integers.\nPlease enter the integers you want summed.\nEntering -1 terminates the summation.\nThe summation terminates automatically of the sum becomes larger than 100." << endl;

  do {
    sum += num;
    if (sum < 100) {cin >> num;}
    else {num = -1;}
  } while (num != -1);

  cout << "The sum is " << sum << "." << endl;

  return 0;
}


int func3() { // Part 2.
  int sum = 0, num = 0;

  cout << "This program calculates the sum of positive integers.\nPlease enter the integers you want summed.\nEntering -1 terminates the summation.\nThe summation terminates automatically of the sum becomes larger than 100.\nIf you make a mistake, you can enter -2. The sum is then reset to 0." << endl;

  do {
    sum += num;
    if (sum < 100) {cin >> num;}
    else {num = -1;}
    if (num == -2) {
      sum = 0;
      num = 0;
    }
  } while (num != -1);

  cout << "The sum is " << sum << "." << endl;

  return 0;
}

int main() {
  func3();

  return 0;
}