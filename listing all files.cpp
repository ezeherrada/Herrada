#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>

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
    if (choice == 1) {
      cout << "LIST FILE DETAIL" << endl;
      cout << "1. List All Files" << endl;
      cout << "2. List of Extension Files" << endl;
      cout << "3. List of Name Wise" << endl;
      cout << "Enter the Number: ";
      cin >> choice;
      if (choice == 1) {
        // List All Files
        vector<string> files;
        for (const auto &entry : directory_iterator(currentDirectory)) {
          if (is_regular_file(entry)) {
            files.push_back(entry.path().filename().string());
          }
        }
        cout << "List of All(*) Files" << endl;
        for (const auto &file : files) {
          cout << file << endl;
        }
        cout << "(continues...)" << endl;
        cout << "Total Files: " << files.size() << endl;
      } else if (choice == 2) {
        // List of Extension Files
        vector<string> files;
        for (const auto &entry : directory_iterator(currentDirectory)) {
          if (is_regular_file(entry)) {
            files.push_back(entry.path().filename().string());
          }
        }
        sort(files.begin(), files.end(), [](const string &a, const string &b) {
          return a.substr(a.find_last_of('.') + 1) < b.substr(b.find_last_of('.') + 1);
        });
        cout << "List of Extension Files" << endl;
        for (const auto &file : files) {
          cout << file << endl;
        }
        cout << "(continues...)" << endl;
        cout << "Total Files: " << files.size() << endl;
      } else if (choice == 3) {
        // List of Name Wise
        vector<string> files;
        for (const auto &entry : directory_iterator(currentDirectory)) {
          if (is_regular_file(entry)) {
            files.push_back(entry.path().filename().string());
          }
        }
        sort(files.begin(), files.end());
        cout << "List of Name Wise" << endl;
        for (const auto &file : files) {
          cout << file << endl;
        }
        cout << "(continues...)" << endl;
        cout << "Total Files: " << files.size() << endl;
      } else {
        cout << "Invalid Choice" << endl;
      }
    } else if (choice == 2) {
      // To Create New Directory
      cout << "Enter the Directory Name: ";
      string directoryName;
      cin >> directoryName;
      if (create_directory(currentDirectory + "\\" + directoryName)) {
        cout << "Directory created successfully." << endl;
      } else {
        cout << "Failed to create directory." << endl;
      }
    } else if (choice == 3) {
      // To Change the Working Directory
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