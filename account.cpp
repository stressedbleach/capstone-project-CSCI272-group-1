#include "account.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Account class implementation
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

// AccountManager implementation
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

// Returns true if the username is found in the file, false otherwise
bool AccountManager::accountExists(const string& username) {
    auto accounts = loadAccounts();
    for (const auto& acc : accounts) {
        if (acc.getUsername() == username) {
            return true;  // account exists
        }
    }
    return false;  // account does not exist
}

// Returns true if both username and password match, false otherwise
bool AccountManager::login(const string& username, const string& password) {
    auto accounts = loadAccounts();
    for (const auto& acc : accounts) {
        if (acc.getUsername() == username && acc.getPassword() == password) {
            return true;  // login successful
        }
    }
    return false;  // login failed
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
