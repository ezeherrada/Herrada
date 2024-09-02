#include <iostream>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

void listFiles() {
    std::string path = fs::current_path().string();
    std::cout << "Listing files in: " << path << "\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path().filename().string() << "\n";
    }
}

void createDirectory() {
    std::string dirName;
    std::cout << "Enter the name of the directory to create: ";
    std::cin >> dirName;

    try {
        if (fs::create_directory(dirName)) {
            std::cout << "Directory created successfully.\n";
        } else {
            std::cout << "Failed to create directory. It may already exist.\n";
        }
    } catch (fs::filesystem_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void changeDirectory() {
    std::string path;
    std::cout << "Enter the path of the directory to change to: ";
    std::cin >> path;

    try {
        fs::current_path(path);
        std::cout << "Directory changed to: " << fs::current_path().string() << "\n";
    } catch (fs::filesystem_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    int choice;

    do {
        clearScreen();
        std::cout << "Directory Management System\n";
        std::cout << "1. List files in current directory\n";
        std::cout << "2. Create a new directory\n";
        std::cout << "3. Change current directory\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            listFiles();
            break;
        case 2:
            createDirectory();
            break;
        case 3:
            changeDirectory();
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        if (choice != 4) {
            std::cout << "Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (choice != 4);

    return 0;
}
