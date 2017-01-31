// A small program for rolling dice.

#include <iostream>
using namespace std;

int diceRoller(int attackerTroops, int defenderTroops);
void throw3v2(int *attackerTroops, int *defenderTroops);

int main() {
  int redTroops = 5;
  int blueTroops = 6;

  throw3v2(&redTroops, &blueTroops);

  diceRoller(redTroops,blueTroops);
   
  return 0;
}

int diceRoller(int attackerTroops, int defenderTroops) {
  cout << "attackerTroops = " << attackerTroops << endl;
  cout << "defenderTroops = " << defenderTroops << endl;

  return 5;
}

void throw3v2(int *attackerTroops, int *defenderTroops) {
  *attackerTroops += 1;
  *defenderTroops -= 1;
}