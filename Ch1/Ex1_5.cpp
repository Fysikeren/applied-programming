#include <iostream>
#include <string>

using namespace std;

int main() {
  string firstname;
  string lastname;

  cout << "Please write your given name:" << endl;
  cin >> firstname;

  cout << "Please write your family name:" << endl;
  cin >> lastname;

  cout << "Your full name is " << firstname << " " << lastname << "." << endl;

  return 0;
}