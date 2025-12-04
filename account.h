#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
using namespace std;

class Account {
private:
    string name;
    string dob;
    string cardInfo;
    string username;
    string password;
public:
    Account();
    Account(const string& name,
            const string& dob,
            const string& cardInfo,
            const string& username,
            const string& password);

    string getName() const;
    string getDob() const;
    string getCardInfo() const;
    string getUsername() const;
    string getPassword() const;
};

class AccountManager {
private:
    string filename;
    vector<Account> loadAccounts();
    void saveAccount(const Account& account);
public:
    AccountManager(const string& filename);

    // Returns true if an account with the given username exists, false otherwise
    bool accountExists(const string& username);

    // Returns true if login credentials match an existing account, false otherwise
    bool login(const string& username, const string& password);

    void createAccount(const Account& account);

    // NEW: high-level functions for main.cpp
    void handleLogin();
    void handleAccountCreation();
};

#endif
