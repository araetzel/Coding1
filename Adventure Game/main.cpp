#include <cstdlib> // the c standard  library/ for rand()
#include <ctime>   // this is for seeding rand()
#include <iostream>
using namespace std;

int main() {

  // INSTRUCTIONS:
  // ************************
  //  welcome the player
  // set up the game
  //     int health = 10, attack, block, turns = 0
  //     seed the random number generator
  // start the loop
  //     add 1 to turns
  //     start the encounter
  //         randomly generate numbers for attack (range = 0-4) and block (range
  //         = 0-4) if block is greater or equal to attack, successful block
  //         otherwise, subtract attack value from health.
  // keep looping while health is greater than zero and fewer than 4 turns have
  // happened

  // if health is greater than 0, congratulate player
  // otherwise, tell the player they're dead.

  // MY CODE:
  // ************************
  // welcome the player
  cout << "Welcome, fearless adventurer, to the start of your journey!"
       << "\n";

  // setup the game
  int health = 10;
  int attack;
  int block;
  int turns = 0;

  srand(time(0));

  // start the encounter
  cout << "**************\n";
  cout << "Whoa! A very wild orc appears!\n";
  cout << "Can you outlast him in only four turns? \n";
  cout << "*Cue 8-bit battle music* \n";
  cout << "**************\n";

  // start the loop
  do {
    turns += 1; // can also be turns++;
    cout << "Turn " << turns << ":\n";

    // The enemy attacks
    attack = rand() % 4 + 1;
    cout << "The orc attacks! \n";
    cout << "Attack Power: " << attack << "\n";

    // The player attempts to block
    block = rand() % 4 + 1;
    cout << "You quicky try to block the attack! \n";
    cout << "Block Power: " << block << "\n";

    if (block < attack) {
      health -= attack;
      cout << "Ouch! Your health is now at: " << health << "\n";
    }

    else
      cout << "Whew! You are unscathed and continue to fight valiantly.\n"
           << "Current health: " << health << "\n";
    cout << "**************\n";

  }

  while (health > 0 && turns < 4);

  // state player's status

  if (health > 0) {
    cout << "Congrats, you win! \n";
  }

  else
    cout << "Oh no! You are dead! :( \n";
}