#ifndef RESTAURANTS_H
#define RESTAURANTS_H

#include <string>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Menu item class
class MenuItem {
public:
    string itemName;
    double price;
    MenuItem(string n, double p) : itemName(n), price(p) {}
};

// Restaurant class
class Restaurant {
protected:
    string RestaurantName;
    double RestaurantsRating;

public:
    vector<MenuItem> menu;

    Restaurant(string n, double rating = 0)
        : RestaurantName(n), RestaurantsRating(rating) {}

    ~Restaurant() {}

    // Add item to menu
    void addItem(string name, double price) {
        menu.push_back(MenuItem(name, price));
    }

    // Show restaurant info
    void printInfo() {
        cout << "Restaurant Name: " << RestaurantName
             << ", Rating: " << RestaurantsRating << endl;
    }

    // Show menu
    void showMenuItems() const {
        cout << "\n--- Menu for " << RestaurantName << " ---\n";
        for (size_t i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i].itemName
                 << " - $" << menu[i].price << endl;
        }
        cout << endl;
    }

    string getName() const {
        return RestaurantName;
    }
};

// Order class 
class Order {
private:
    vector<MenuItem> selectedItems;

public:
    // Add item user selects
    void addItem(const MenuItem& item) {
        selectedItems.push_back(item);
    }

    // Remove item user selected
    void removeItem(int index) {
        if (index >= 0 && index < (int)selectedItems.size()) {
            selectedItems.erase(selectedItems.begin() + index);
        }
    }

    // Show current order + total price
    void showOrder() const {
        cout << "\n--- Your Order ---\n";

        if (selectedItems.empty()) {
            cout << "No items selected yet.\n";
            return;
        }

        double total = 0;

        for (int i = 0; i < selectedItems.size(); i++) {
            cout << i + 1 << ". "
                 << selectedItems[i].itemName
                 << " - $" << selectedItems[i].price << endl;

            total += selectedItems[i].price;
        }

        cout << "Total Price: $" << total << endl;
    }

    int size() const {
        return selectedItems.size();
    }
};

//  list of restaurants
void showMenu(const vector<Restaurant>& restaurant) {
    cout << "Select a Restaurant by number:\n";
    for (size_t i = 0; i < restaurant.size(); ++i) {
        cout << i + 1 << ". " << restaurant[i].getName() << endl;
    }
}

#endif