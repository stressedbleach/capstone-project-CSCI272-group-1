// main file - executable code ONLY
// Simridhi Sharma

#include "account.h"
#include <iostream>
using namespace std;

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
    AccountManager manager("userAccounts.txt");

    // ask user if they already have an account
    cout << "Do you have an account? (y/n): \n";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y'){ //Y is added in case they use caps lock!
        //login flow
        string username, password;
        bool loggedIn = false;

        while (!loggedIn){
            cout << "Enter username: " ;
            cin >> username;
            cout << "Enter password: " ;
            cin >> password;

            //check credentials using accountmanager::login
            if (manager.login(username, password)){
                cout << "Login successful!\n";
                loggedIn = true;
            } else {
                cout << "Invalid credentials. Try again? (y/n): " ;
                char retry;
                cin >> retry;
                if (retry != 'y' && retry != 'Y'){
                    cout << "Exiting login.\n";
                    break;
                }
            }
        }
    } else {
        //acount creation flow
        string name, dob, cardInfo, username, password;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter DOB (YYYY-MM-DD): ";
        getline(cin, dob);

        cout << "Enter card info: ";
        getline(cin, cardInfo);

        cout << "Set a username: ";
        getline(cin, username);

        cout << "Set a password: ";
        getline(cin,password);

        //create new account object and save it
        Account newAcc(name, dob, cardInfo, username, password);
        manager.createAccount(newAcc);
    }

    return 0;

}
