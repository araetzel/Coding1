#include <iostream>
using namespace std;

int main() {
  string faveGames[100];
  int index = 0;

  while (true) {
    cout << "****************************** \n";
    cout << "What would you like you do? \n";
    cout << "\n";
    cout << "- Type 'quit' to quit the program \n";
    cout << "- Type 'add' to add a game \n";
    cout << "- Type 'show' to show your favorite game \n";
    cout << "- Type 'edit' to make changes \n";
    cout << "- Type 'editlast' to make changes to what you just added \n";
    cout << "- Type 'find' to make changes to a specific one\n";
    cout << "- Type 'bulkAdd' to add ten games to the list at once.\n";
    cout << "Answer: ";

    // get input
    string input;
    cin >> input;

    // test the input
    if (input == "quit") {
      cout << "Shutting down... \n";
      break;
    }

    if (input == "add") {
      cout << "What game do you want to add? \n";
      cin >> input;
      faveGames[index] = input;
      index++; // next spot is available in the index
    }          // end of first if statement

    else if (input == "show") {
      cout << "****************************** \n";
      cout << "Here is your list: \n";
      cout << "\n";
      for (int i = 0; i < index; i += 1) {
        cout << faveGames[i] << "\n";
      } // end of else if
    }
    // what if we mess up?
    else if (input == "edit") {
      cout << "What is the number of the name you want to change? \n";
      int numInput;
      cin >> numInput;

      cout << "What would you like to change " << faveGames[numInput]
           << " to?\n";
      cin >> input;
      faveGames[numInput - 1] = input;
    } // end of else if

    else if (input == "editlast") {
      cout << "Your last entry was: " << faveGames[index - 1];
      cin >> input;
      faveGames[index - 1] = input;
    } // end of else if

    // BULK ADD STATEMENT
    else if (input == "bulkAdd") {
      while (input != "quit") {
        cout << "Please type a game to add. Type 'quit' to exit.\n";
        cin >> input;
        faveGames[index] = input;
        index++;
      }
      index --;
    } // end of else if

    else if (input == "find") {
      cout << "What would you like to find?\n";
      cin >> input;

      // use a for statement to look for which one matches
      for (int i = 0; i < index; i++) {
        if (input == faveGames[i]) {
          cout << "Found it!\n";
          cout << "What would you like to change it to?\n";
          cin >> input;
          faveGames[i] = input;
          break;
        }
        if (i + 1 == index) {
          cout << "I could not find that game in the list.\n";
        }
      }
    }

    else {
      cout << "[Error. Command not recognized.]\n\n";
    } // end of final else
  }
}