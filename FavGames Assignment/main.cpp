#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*
for your assignment:
    create a favgames program.
    use functions for functionality:
        add
        show
        remove
        edit
        load previous list from file using functions
        save list to file using functions

*/

// global array
string favGames[100];
// index keeps track of list length and where to add next item in the array
int index = 0;

void add() {
  string input;
  cout << "What game would you like to add?\n";
  cin >> input;
  //getline(cin, input);
  favGames[index++] = input;
}

void show() {
  cout << "Your Favorite Games: \n";
  for (int i = 0; i < index; i++) {
    cout << favGames[i] << "\n";
    if (favGames[i] == "") {
      // skip empty lines
      continue;
    } // end of if line
  }   // end of for line
}

// MY VERSION:
/* void remove() {
  string input;
  cout << "What game would you like to remove? \n";
  cin >> input;
  for (int i = 0; i < index; i++) {
    if (input == favGames[i]) {
      index--;
      cout << "Done!\n";
      break;
    } // end of if statement
    if (i + 1 == index) {
      cout << "I could not find that game in the list.\n";
    }
  } // end of for loop
} */

// CORRECTED VERSION:
void remove() {
  cout << "What do you want to remove?\n";
  string input;
  cin >> input;

  for (int i = 0; i < index; i++) {
    if (input == favGames[i]) {
      cout << "Removing...\n";
      favGames[i] = ""; // favGames is equal to nothing
      break;
    }
  }
}

void clear(){
  index=0;
}

void edit() {
  string input;
  cout << "What game do you want to replace? \n";
  cin >> input;
  for (int i = 0; i < index; i++) {
    if (input == favGames[i]) {
      cout << "Found it!\n";
      cout << "What would you like to change it to?\n";
      cin >> input;
      favGames[i] = input;
      break;
    } // end of if statement
    if (i + 1 == index) {
      cout << "I could not find that game in the list.\n";
    }
  } // end of for loop
}

// MY VERSION:
/* void load() {
  string line;
  ifstream save("favegames.txt");

  // check to see if the file is open
  if (save.is_open()) {
    while (getline(save, line)) {
      cout << line << "\n";
    }
  } else {
    cout << "File could not be loaded.\n";
  }
} */

// CORRECTED LOAD FUNCTION:
void load() {
  // open the file
  ifstream file("data.txt");
  string line; // keeps track of every line that's coming in

  // will run as long as there are lines in the txt file
  if (file.is_open()) {
    while (getline(file, line)) {
      favGames[index++] = line;
    }
  }
  file.close();
}

// MY VERSION:
/* void save() {
  ofstream file;
  file.open("favegames.txt");
  // use a for loop to write all of the array lines to the file
  for (int i = 0; i < index; i++) {
    file << favGames[i] << "\n";
  }
  // close the file
  file.close();
  cout << "done!\n";
} */

// CORRECTED SAVE FUNCTION:
void save() {
  // create and open the ofstream file
  ofstream file("data.txt");

  // for each array element, write a line to the file
  if (file.is_open()) {
    for (int i = 0; i < index; i++) {
      file << favGames[i] << "/n";
    }
  }
  file.close();
}

int main() {
  // load the code from the file at the beginning
  load();

  while (true) {
    cout << "Do what?\n";
    string input;
    cin >> input;
   // getline(cin, input); // getline(from, to)

    if (input == "add") {
      add();
    }
    if (input == "show") {
      show();
    }
    if (input == "remove") {
      remove();
    }
    if (input == "edit") {
      edit();
    }
  if (input == "save"){
    save ();
  }
    if (input == "clear"){
      clear ();
    }
    if (input == "quit") {
      break;
    }
  } // end of while loop
}