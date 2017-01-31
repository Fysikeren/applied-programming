// A small program for rolling dice.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int diceRoller(int attackerTroops, int defenderTroops);
void throw3v2(int *attackerTroops, int *defenderTroops);
void throw3v1(int *attackerTroops, int *defenderTroops);
void throw2v2(int *attackerTroops, int *defenderTroops);
void throw2v1(int *attackerTroops, int *defenderTroops);
void throw1v2(int *attackerTroops, int *defenderTroops);
void throw1v1(int *attackerTroops, int *defenderTroops);

int main() {
  srand(time(NULL));

  int redTroops = 15;
  int blueTroops = 15;

  int j = 0;
  for (int i = 0; i < 1e5; ++i)
  {
    j += diceRoller(redTroops,blueTroops);
  }

  cout << "j = " << j << endl;
   
  return 0;
}

int diceRoller(int attackerTroops, int defenderTroops) {
  // cout << "Before:" << endl;
  // cout << "attackerTroops = " << attackerTroops << ", defenderTroops = " << defenderTroops << endl;

  while (attackerTroops > 0 & defenderTroops > 0) {
    if (attackerTroops > 2 & defenderTroops > 1) {
      throw3v2(&attackerTroops, &defenderTroops);
      // cout << "throw3v2" << endl;
    }
    else if (attackerTroops > 2 & defenderTroops == 1) {
      throw3v1(&attackerTroops, &defenderTroops);
      // cout << "throw3v1" << endl;
    }
    else if (attackerTroops == 2 & defenderTroops > 1) {
      throw2v2(&attackerTroops, &defenderTroops);
      // cout << "throw2v2" << endl;
    }
    else if (attackerTroops == 2 & defenderTroops == 1) {
      throw2v1(&attackerTroops, &defenderTroops);
      // cout << "throw2v1" << endl;
    }
    else if (attackerTroops == 1 & defenderTroops > 1) {
      throw1v2(&attackerTroops, &defenderTroops);
      // cout << "throw1v2" << endl;
    }
    else if (attackerTroops == 1 & defenderTroops == 1) {
      throw1v1(&attackerTroops, &defenderTroops);
      // cout << "throw1v1" << endl;
    }
    else {
      defenderTroops = 0;
      cout << "Something went wrong. The 'else' clause was triggered." << endl;
    }
    // cout << "attackerTroops = " << attackerTroops << ", defenderTroops = " << defenderTroops << endl;
  }

  // cout << "After:" << endl;
  // cout << "attackerTroops = " << attackerTroops << ", defenderTroops = " << defenderTroops << endl;

  if (defenderTroops == 0) {return 1;}
  return 0;
}

void throw3v2(int *attackerTroops, int *defenderTroops) {
  throw1v1(attackerTroops, defenderTroops);
}

void throw3v1(int *attackerTroops, int *defenderTroops) {
  throw1v1(attackerTroops, defenderTroops);
}

void throw2v2(int *attackerTroops, int *defenderTroops) {
  int attackerDie1 = rand() % 6;
  int attackerDie2 = rand() % 6;
  int defenderDie1 = rand() % 6;
  int defenderDie2 = rand() % 6;

  if (attackerDie1 > defenderDie1 & attackerDie2 > defenderDie2) {
    *defenderTroops -= 2;
  }
  else if (attackerDie2 > defenderDie1 & attackerDie1 > defenderDie2) {
    *defenderTroops -= 2;
  }
  else {
    *attackerTroops -= 1;
  }
}

void throw2v1(int *attackerTroops, int *defenderTroops) {
  int attackerDie1 = rand() % 6;
  int attackerDie2 = rand() % 6;
  int defenderDie = rand() % 6;

  if (attackerDie1 > defenderDie) {
    *defenderTroops -= 1;
  }
  else if (attackerDie2 > defenderDie) {
    *defenderTroops -= 1;
  }
  else {
    *attackerTroops -= 1;
  }
}

void throw1v2(int *attackerTroops, int *defenderTroops) {
  int attackerDie = rand() % 6;
  int defenderDie1 = rand() % 6;
  int defenderDie2 = rand() % 6;

  if (attackerDie > defenderDie1) {
    *defenderTroops -= 1;
  }
  else if (attackerDie > defenderDie2) {
    *defenderTroops -= 1;
  }
  else {
    *attackerTroops -= 1;
  }
}

void throw1v1(int *attackerTroops, int *defenderTroops) {
  int attackerDie = rand() % 6;
  int defenderDie = rand() % 6;

  if (attackerDie > defenderDie) {
    *defenderTroops -= 1;
  }
  else {
    *attackerTroops -= 1;
  }
}