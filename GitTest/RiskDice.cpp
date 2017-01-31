// A small program for rolling dice.

#include <iostream>
using namespace std;

int diceRoller(int attackerTroops, int defenderTroops);

int main() {
  cout << diceRoller(5,6) << endl;
   
  return 0;
}

int diceRoller(int attackerTroops, int defenderTroops) {
  cout << "attackerTroops = " << attackerTroops << endl;
  cout << "defenderTroops = " << defenderTroops << endl;

  return 5;
}