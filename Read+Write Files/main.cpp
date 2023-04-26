#include <fstream> // includes ifstream (in from a file) and ofstream (out to a file)
#include <iostream>
using namespace std;

int main() {
  cout << "Getting Started\n";

  cout << "Let's save text to a file!\n";

  // create the file variable
  ofstream file;
  // opening the file, specifying filename
  file.open("data.txt");
  // writing text to the file
  file << "This text will be saved into the file \n";

  // let the user decide what to save to the file
  while (true) {
    cout << "What do you want to say?\n";
    string input;
    getline(cin, input);

    if (input == "quit")
      break;
    // add input to file, then start a new line
    file << input << "\n";
  }

  // close the file, so that some other program can use it
  file.close();

  cout << "done!\n";

  cout << "Let's read from our save.txt file\n";
  // create a string variable to hold each line in the file.
  string line;
  // create the file variable
  ifstream save("save.txt");

  // check to see if the file is open
  if (save.is_open()) {
    while (getline(save, line)) {
      cout << line << "\n";
    }
  } else {
    cout << "file could not be loaded.\n";
  }
}