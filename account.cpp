#include "account.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// -------------------- Account class implementation --------------------

Account::Account() {}

Account::Account(const string& name,
                 const string& dob,
                 const string& cardInfo,
                 const string& username,
                 const string& password)
    : name(name), dob(dob), cardInfo(cardInfo), username(username), password(password) {}

string Account::getName() const { return name; }
string Account::getDob() const { return dob; }
string Account::getCardInfo() const { return cardInfo; }
string Account::getUsername() const { return username; }
string Account::getPassword() const { return password; }

// -------------------- AccountManager implementation --------------------

AccountManager::AccountManager(const string& filename) : filename(filename) {}

vector<Account> AccountManager::loadAccounts() {
    vector<Account> accounts;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, dob, cardInfo, username, password;
        getline(ss, name, ',');
        getline(ss, dob, ',');
        getline(ss, cardInfo, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        accounts.emplace_back(name, dob, cardInfo, username, password);
    }
    return accounts;
}

bool AccountManager::accountExists(const string& username) {
    auto accounts = loadAccounts();
    for (const auto& acc : accounts) {
        if (acc.getUsername() == username) {
            return true;
        }
    }
    return false;
}

bool AccountManager::login(const string& username, const string& password) {
    auto accounts = loadAccounts();
    for (const auto& acc : accounts) {
        if (acc.getUsername() == username && acc.getPassword() == password) {
            return true;
        }
    }
    return false;
}

void AccountManager::createAccount(const Account& account) {
    if (accountExists(account.getUsername())) {
        cout << "Username already exists. Try another.\n";
        return;
    }
    saveAccount(account);
    cout << "Account created successfully!\n";
}

void AccountManager::saveAccount(const Account& account) {
    ofstream file(filename, ios::app);
    file << account.getName() << ","
         << account.getDob() << ","
         << account.getCardInfo() << ","
         << account.getUsername() << ","
         << account.getPassword() << "\n";
}

// -------------------- NEW FUNCTIONS --------------------

// Handles login flow with retry option
void AccountManager::handleLogin() {
    string username, password;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (login(username, password)) {
            cout << "Login successful!\n";
            loggedIn = true;
        } else {
            char retry;
            cout << "Invalid credentials. Try again? (y/n): ";
            cin >> retry;
            if (retry != 'y' && retry != 'Y') {
                cout << "Exiting login.\n";
                break;
            }
        }
    }
}

// Handles account creation prompts and saving
void AccountManager::handleAccountCreation() {
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
    getline(cin, password);

    Account newAcc(name, dob, cardInfo, username, password);
    createAccount(newAcc);
}
