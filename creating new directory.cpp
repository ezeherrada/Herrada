#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

int main() {
  string currentDirectory = "C:\\Users\\UserName\\Documents";
  cout << "MAIN MENU" << endl;
  cout << "1. To Display List of Files" << endl;
  cout << "2. To Create New Directory" << endl;
  cout << "3. To Change the Working Directory" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter the Number: ";
  int choice;
  cin >> choice;

  while (choice != 4) {
    if (choice == 3) {
      cout << "Current Directory: " << currentDirectory << endl;
      cout << "Change Directory" << endl;
      cout << "1. Step by Step Backward" << endl;
      cout << "2. Goto Root Directory" << endl;
      cout << "3. Forward Directory" << endl;
      cout << "Enter the Number: ";
      cin >> choice;
      if (choice == 1) {
        // Step by Step Backward
        path p(currentDirectory);
        if (p.has_parent_path()) {
          currentDirectory = p.parent_path().string();
          cout << "Current Directory: " << currentDirectory << endl;
        } else {
          cout << "Already at the root directory." << endl;
        }
      } else if (choice == 2) {
        // Goto Root Directory
        currentDirectory = "C:\\";
        cout << "Current Directory: " << currentDirectory << endl;
      } else if (choice == 3) {
        // Forward Directory
        cout << "Please enter the Directory Name: ";
        string directoryName;
        cin >> directoryName;
        currentDirectory += "\\" + directoryName;
        if (exists(currentDirectory)) {
          cout << "Current Directory: " << currentDirectory << endl;
        } else {
          cout << "Directory does not exist." << endl;
        }
      } else {
        cout << "Invalid Choice" << endl;
      }
    } else {
      cout << "Invalid Choice" << endl;
    }
    cout << "MAIN MENU" << endl;
    cout << "1. To Display List of Files" << endl;
    cout << "2. To Create New Directory" << endl;
    cout << "3. To Change the Working Directory" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter the Number: ";
    cin >> choice;
  }
  cout << "Exiting..." << endl;
  return 0;
}