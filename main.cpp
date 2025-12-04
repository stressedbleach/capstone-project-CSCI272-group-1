// main file - executable code ONLY
// Simridhi Sharma

#include "account.h"
#include <iostream>
using namespace std;

<<<<<<< HEAD
void displayMainMenu() {
    cout << "====Welcome to Our Food Delivery Serivce!====\n";
    cout << "\n\n"
        
    cout << "Would You Like To: ";
    cout << "1. Create An Account\n";
    cout << "2. Login to Account\n";
    cout << "3. Exit\n";
    cout << "\n";
        
    cout << "Choice: ";
}

void userMenu() {
    cout << "====User Menu====\n";
    cout << "\n\n"
        
    cout << "Would You Like To: ";
    cout << "1. View Restaurant Menu\n";
    cout << "2. Add/Remove Items from Your Cart\n";
    cout << "3. Logout from Account\n";
    cout << "4. Logout\n"
    cout << "\n";
        
    cout << "Choice: ";
}

int main(){
    //create accountmanager with file name for storing accounts
=======
int main() {
>>>>>>> ba09d79 (changed and moved functions around since main.cpp cannot have "business logic")
    AccountManager manager("userAccounts.txt");

    char choice;
    cout << "Do you have an account? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        manager.handleLogin();  // move login logic into a function
    } else {
        manager.handleAccountCreation();  // move account creation logic into a function
    }

    return 0;
<<<<<<< HEAD

=======
>>>>>>> ba09d79 (changed and moved functions around since main.cpp cannot have "business logic")
}
