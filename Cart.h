#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
#include "Menu.h"
// cart class
class Cart : public MenuDisplay {
    private:
        // vector for storing cart items
        vector<string> cartItems {};
    public:
        // default constructor
        Cart() = default;

        /* functions that (respectively):
            - allows user to choose between adding or removing items
            - adds item
            - removes item
        */
        void addOrRemove();
        bool addItem(const string& item);
        bool removeItem(const string& item);

        /* friend functions that (respectively):
            - print out the current cart using ostream operator overloading
            - save the final transaction to a file using ofstream operator overloading
        */
        friend ostream& operator<<(ostream& out, const Cart& other);
        friend ofstream& operator<<(ofstream& out, const Cart& other);
        
};

#define // TRANSACTION_H
