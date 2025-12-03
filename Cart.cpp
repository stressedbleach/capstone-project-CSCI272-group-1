#include "Cart.h"
#include "Menu.h"

bool inputValidation() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    } else {
        return true;
    }
    return false;
}

void Cart::addOrRemove() {
    int choice {0};

do {
    cout << "Enter [1] to add item to cart,"
         << "Enter [2] to remove item from cart.\n"
         << "Choice: ";
    cin >> choice;
    cin.ignore(1000, '\n');

    if (!inputValidation() || choice != 1 && choice != 2) {
        cout << "Invalid. Please enter integer (1 or 2).";
    }

    } while (!inputValidation() || choice != 1 && choice != 2); 

    if (choice == 1) {
        bool validItem;

        do {
            string item;
            cout << "Please choose item from menu: ";
            getline(cin, item);

            validItem = addItem(item);

            if (!validItem) {
                int retryChoice {0};
                cout << "Item not on menu.\n";
                  
                do {
                    cout << "Would you like to try again?\n"
                         << "Enter [1] to try again, enter [2] to exit.";
                    cin >> retryChoice;
                    cin.ignore(1000, '\n');

                    if (!inputValidation() || retryChoice != 1 && retryChoice != 2) {
                        cout << "Invalid. Please enter integer (1 or 2).";
                    } else if (retryChoice == 2) {
                        cout << "Exiting...";
                        cout << "Done!";
                        break;
                    }
                } while (!inputValidation() || (retryChoice != 1 && retryChoice != 2));
                     
            }

        } while (!validItem);

    } else {
        bool validItem;
        
        do {
            string item;
            cout << "Please choose item from menu: ";
            getline(cin, item);

            validItem = removeItem(item);

            if (!validItem) {
                int retryChoice {0};
                cout << "Item not on menu.\n"
                     << "Would you like to try again?\n"
                     << "Enter [1] to try again, enter [2] to exit.";
                cin >> retryChoice;
                cin.ignore(1000, '\n');
                if (!inputValidation() || (retryChoice != 1 && retryChoice != 2)) {
                    cout << "Invalid. Please enter integer (1 or 2).";
                } else if (retryChoice == 2) {
                    cout << "Exiting...";
                    cout << "Done!";
                    break;
                }
            }
        } while (!validItem);

    }

}

bool Cart::addItem(const string& item) {
    bool itemTrue = false;
    vector<string> menuVec;

    for (const auto& item : menu) {
        menuVec.push_back(item.first);
    }
    
    for (auto i {0}; i < menuVec.size(); ++i) {
        if (item == menuVec.at(i)) {
            cartItems.push_back(item);
            cout << item << " added to cart.\n";
            return true;
        } else {
            return false;
        }
    }

}

bool Cart::removeItem(const string& item) {
    auto it = find(cartItems.begin(), cartItems.end(), item);
    if (it != cartItems.end()) {
        cartItems.erase(it);
        cout << "Item removed from cart.\n";
        return true;
    } else {
        cout << "Item not in cart\n";
        return false;
    }

    return false;    
}

ostream& operator<<(ostream& out, const Cart& other) {
    cout << "Current Cart: ";
        for (const auto& cart : other.cartItems) {
            out << cart << '\n'; 
    }

    return out;
}

ofstream& operator<<(ofstream& transactionFile, const Cart& other) {
    if (!transactionFile.is_open()) {
        cerr << "File could not be opened. Please try again." << '\n';
        return transactionFile;
    } else {
        transactionFile << "=====Transaction History=====" << '\n';
        for (const auto& cart : other.cartItems) {
            transactionFile << cart << '\n';
        }
    }

    return transactionFile;
}