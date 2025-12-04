#include "Cart.h"
#include "Menu.h"

// tests for vaid input
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

// menu for adding and removing form cart
void Cart::addOrRemove() {
    int choice {0};

    // loops if conditions are not met
do {
    // allows user to enter one or two
    cout << "Enter [1] to add item to cart,"
         << "Enter [2] to remove item from cart.\n"
         << "Choice: ";
    cin >> choice;
    cin.ignore(1000, '\n');

    // message if incorrect data type or integer except 1 or 2 is inputted
    if (!inputValidation() || choice != 1 && choice != 2) {
        cout << "Invalid. Please enter integer (1 or 2).\n";
    }

    } while (!inputValidation() || choice != 1 && choice != 2); 

    // if user choice is 1
    if (choice == 1) {
        bool validItem;

        // loops if conditions are not met
        do {
            // allows to choose from menu
            string item;
            cout << "Please choose item from menu: ";
            getline(cin, item);

            // sets valid item to the return value of the add function
            validItem = addItem(item);

            // if valid item is not found
            if (!validItem) {
                int retryChoice {0};
                cout << "Item not on menu.\n";
                
                // user can choose between one or two
                do {
                    cout << "Would you like to try again?\n"
                         << "Enter [1] to try again, enter [2] to exit.\n";
                    cin >> retryChoice;
                    cin.ignore(1000, '\n');
                    
                    // message if incorrect data type or integer except 1 or 2 is inputted
                    if (!inputValidation() || retryChoice != 1 && retryChoice != 2) {
                        cout << "Invalid. Please enter integer (1 or 2).\n";
                    } else if (retryChoice == 2) {
                        // message if no longer adding to cart, breaking the loop.
                        cout << "No longer adding to cart.\n";
                        break;
                    }
                } while (!inputValidation() || (retryChoice != 1 && retryChoice != 2));
                     
            }

        } while (!validItem);
        
        // if user inputs choice 2
    } else {
        bool validItem;
        
        // loops if conditions are not met
        do {
            // allows to choose from cart
            string item;
            cout << "Please choose item from cart: ";
            getline(cin, item);
            
            // sets valid item to the return value of the remove function
            validItem = removeItem(item);

            // if valid item is not found
            if (!validItem) {
                // user can choose between one or two
                int retryChoice {0};
                cout << "Item not on menu.\n"
                     << "Would you like to try again?\n"
                     << "Enter [1] to try again, enter [2] to exit.";
                cin >> retryChoice;
                cin.ignore(1000, '\n');
                if (!inputValidation() || (retryChoice != 1 && retryChoice != 2)) {
                    cout << "Invalid. Please enter integer (1 or 2).";
                } else if (retryChoice == 2) {
                    // message if no longer adding to cart, breaking the loop.
                    cout << "No longer adding to cart.\n";
                    break;
                }
            }
        } while (!validItem);

    }

}

// function to add items to cart
bool Cart::addItem(const string& item) {
    // vector for menu
    vector<string> menuVec;

    // loop to put all items from menu in vector form
    // (done because it was easier for logic)
    for (const auto& item : menu) {
        menuVec.push_back(item.first);
    }
    
    // serarches through menu via loop (size_t to guarantee it works)
    for (size_t i {0}; i < menuVec.size(); ++i) {
        if (menuVec.at(i) == item) {
            // adds item if found in cart at index
            // returns true if object was found
            cartItems.push_back(item);
            cout << item << " added to cart.\n";
            return true;
        }
    }

    // returns false if item not found in menu
    cout << "Item not in menu.\n";
    return false;
}

// function to remove items from cart
bool Cart::removeItem(const string& item) {
    
    // serarches through cart via loop (size_t to guarantee it works)
    for (size_t i {0}; i < cartItems.size(); ++i) {
        // removes item if found in cart at index
        // returns true if object was found
        if (cartItems.at(i) == item) {
            cartItems.erase(cartItems.begin() + i);
            cout << "Item removed from cart.\n";
            return true;
        }
    }

    // returns false if item not found in cart
    cout << "Item not in cart.\n";
    return false;
}
// function to calculate the sub price
double Cart::getSubPrice()  {
    // loop for calculation
    double subPrice {0.00};
    for (const auto& item : cartItems) {
        auto it = menu.find(item);
        // if not found, subPrice is set to the value-side of the menu item
        if (it != menu.end()) {
            subPrice += it->second;
        }
    }

    // return subPrice
    return subPrice;
}

// function to get the tip from user
double Cart::getTip() {
    double userTip {0.00};
    
    // loops if conditons are not meant
    do {
        cout << "Insert tip amount: ";
        cin >> userTip;
        cin.ignore(1000, '\n');

        // prints message if input is not a double or greater than $0.00
        if (!inputValidation() || userTip < 0.00) {
            cout << "Tip must be a number greater than $0.00.\n";
        }
    } while (!inputValidation() || userTip < 0.00);

    return userTip;
}

// function to calculate the total
double Cart::getTotal() {
    subPrice = getSubPrice();
    tipAmount = getTip();
    totalPrice = ((subPrice + tipAmount) * taxRate) + deliveryFee;

    return totalPrice;
}

// prints the current price values
void Cart::displayPrice() {
    cout << "==== Prices ====\n" << fixed << setprecision(2);
    cout << left << setw(15) << "Sub Price:" << right << setw(10) << '$' << setw(8) << getSubPrice() << '\n';
    cout << left << setw(15) << "Delivery Fee:" << right << setw(10) << '$' << setw(8) << deliveryFee << '\n';
    cout << left << setw(15) << "After Tax:" << right << setw(10) << '$' << setw(8) << taxRate * (getSubPrice() + deliveryFee) << '\n';
    cout << left << setw(15) << "Tip:" << right << setw(10) << '$' << setw(8) << getTip() << '\n';
    cout << "----------------\n";
    cout << left << setw(15) << "Total: $" << right << setw(10) << '$' << setw(8) << getTotal() << '\n';
}
// function to print the current cart
ostream& operator<<(ostream& out, const Cart& other) {
    
    // uses loop and returns the output stream
    cout << "Current Cart: ";
        for (const auto& cart : other.cartItems) {
            out << cart << '\n'; 
    }

    // returns ostream object
    return out;
}

// function to save the final transaction to file
ofstream& operator<<(ofstream& transactionFile, const Cart& other) {
    // returns error if file not open
    if (!transactionFile.is_open()) {
        cerr << "File could not be opened. Please try again." << '\n';
        return transactionFile;
    } else {
        // saves current cart and all items to ofstream object
        transactionFile << "=====Transaction History=====" << '\n';
        for (const auto& cart : other.cartItems) {
            transactionFile << cart << '\n';
        }
    }

    // returns ofstream object
    return transactionFile;
}
