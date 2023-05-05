#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int health = 30;
int totalTreasure = 0;

// Create the following functions:
/*
Story
- return type is void */

void Story() {
  cout << "You wake up. It's time to go check out that cave where the rumored "
          "treasure awaits!\n";
}

/*
AskYesNo
- One string argument named "question"
- return type is bool */

bool AskYesNo(string question) {
  cout << question << "(y/n) ";
  string input;
  cin >> input;

  while (true) {
    if (input == "y") {
      return true;
    } else if (input == "n") {
      return false;
    } else {
      cout << "Invalid answer. Please try again.\n";
    }
  }
}

/*
RollDie
- one int parameter named "sides" with a default value of 6
- return type is int */

int rollDie(int sides = 6) {
  int roll = rand() % sides + 1;
  return roll;
}

/*
Ending
- return type is void */

void Ending() {
  cout << "Your adventure has ended and you return home with " << totalTreasure
       << " treasure.\n";
}

/*
Adventure
- return type is void or bool
- calls rollDie for attack, block, & treasure
- tells the player their health after the encounter */

void Adventure() {
  int attack = rollDie();
  int block = rollDie();

  cout << "Block = " << block << " , Attack = " << attack << "\n";

  if (block < attack) {
    health -= attack;
    cout << "You barely manage to escape, leaving the treasure behind.\n";
  } // end of if statement
  else {
    cout << "You are able to get past the enemy and take the loot!\n";
    cout << "You gain " << rollDie() << " treasure.\n";
    totalTreasure = totalTreasure + rollDie();
  } // end of else
  cout << "Your health is at " << health << " and your total treasure is at "
       << totalTreasure << ".\n";
}

/*
Main (default)
- calls story,
- has a loop for adventure,
- checks for health
- calls ending */

/* The game should run as follows:
- The player is told a story prompting them to seek treasure on an
adventure.
- The player is asked if they would like to go adventuring.
   - If the player says yes, numbers for an enemy attack, their own block,
and an amount of treasure are randomly generated.
     - If the player's block is higher than the enemy attack, they have
successfully blocked and they receive the treasure.
     - However, if the attack is higher, that number is subtracted from
their health and they do not get the treasure.
     - The player is then told their health and amount of totalTreasure and
asked if they would like to adventure again.
     - They can continue to adventure as long as their health is greater
than zero, at which point the ending is run and they are told that they are
dead.
   - If they instead quit before their health is zero, they are told how
much health they have and how much treasure they ended up with. */

int main() {

  srand(time(0));

  Story();

  while (AskYesNo("Do you want to go adventuring?") == true && health > 0) {
    Adventure();
  }

  if (health < 0) {
    cout << "Oh no! You have died. You have lost all your treasure.\n";
  } else {
    Ending();
  }
}
