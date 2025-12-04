// main file - executable code ONLY
// Simridhi Sharma (add your names here)

#include "account.h"
#include <iostream>
using namespace std;

void displayMainMenu() {
    cout << "==== Welcome to Our Food Delivery Service! ====\n";
    cout << "\n";
    cout << "Would You Like To:\n";
    cout << "1. Create An Account\n";
    cout << "2. Login to Account\n";
    cout << "3. Exit\n";
    cout << "\n";
    cout << "Choice: ";
}

void userMenu() {
    cout << "==== User Menu ====\n";
    cout << "\n";
    cout << "Would You Like To:\n";
    cout << "1. View Restaurant Menu\n";
    cout << "2. Add/Remove Items from Your Cart\n";
    cout << "3. Logout from Account\n";
    cout << "4. Exit\n";   
    cout << "\n";
    cout << "Choice: ";
}

int main() {
    // create AccountManager with file name for storing accounts
    AccountManager manager("userAccounts.txt");

    bool running = true;
    while (running) {
        displayMainMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            manager.handleAccountCreation();
        } else if (choice == 2) {
            manager.handleLogin();

            // After login, show user menu
            bool userLoggedIn = true;
            while (userLoggedIn) {
                userMenu();
                int userChoice;
                cin >> userChoice;

                if (userChoice == 1) {
                    cout << "Displaying restaurant menu...\n";
                    // TODO: call your Restaurant/MenuDisplay class here
                } else if (userChoice == 2) {
                    cout << "Add/Remove items from cart...\n";
                    // TODO: implement cart logic here
                } else if (userChoice == 3) {
                    cout << "Logging out...\n";
                    userLoggedIn = false; // return to main menu
                } else if (userChoice == 4) {
                    cout << "Exiting program...\n";
                    userLoggedIn = false;
                    running = false; // exit entire program
                } else {
                    cout << "Invalid choice. Try again.\n";
                }
            }
        } else if (choice == 3) {
            cout << "Exiting program...\n";
            running = false;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
