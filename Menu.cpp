#include "Menu.h"

// function to print restaurant name and rating
void Restaurant::printInfo() {
    cout << "Restaurant Name: " << RestaurantName << ", Rating: " << RestaurantsRating << endl;
}

// function to print restaurant
string Restaurant::getName() const {
    return RestaurantName;
}

// function to display the whole menu of choosen restaurant
void MenuDisplay::displayWholeMenu() const {
    cout << RestaurantName << "Menu: \n";
    for (const auto& item : menu) {
        cout << item.first << ": $" << fixed << setprecision(2) << item.second << '.' << "\n";
    }
    cout << RestaurantName << "Rating: " << RestaurantsRating << "/5\n";
}

// menu to display specific item
void MenuDisplay::displayItem(const string& itemName) const {
    cout << RestaurantName << "Menu: \n";

    // finds the item, creates auto variable for consistency using given itemName
    auto it = menu.find(itemName);
    // displays item if item is in menu
    if (it != menu.end()) {
        // it variable points to key and value respectively
        cout << it->first << ": $" << fixed << setprecision(2) << it->second << '\n';
    }
}

// function to input menu from file into map
void MenuDisplay::fileReader(const string& file) {
    // ifstream object with string variable
    ifstream menuFile(file);
    string item;

    // loops through the menu until eof
    while (getline(menuFile, item)) {
        // declares istringstream object and puts the item string into it
        istringstream wholeMenu(item);
        
        string itemName;
        string itemPrice;

        //  puts the stringstream objects into itemName and itemPrice respectively
        getline(wholeMenu, itemName, '|');
        getline(wholeMenu, itemPrice);

        // converts the price to a double variable
        double price = stod(itemPrice);
        // puts the objects into menu
        menu.insert({itemName, price});
    }

    // closes the file
    menuFile.close();
}



