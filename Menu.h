#ifndef RESTAURANT_MENU_H
#define RESTAURANT_MENU_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

// restaurant class (created by - )
class Restaurant {
    protected:
    string RestaurantName;
    double RestaurantsRating;

    public:
    // Restaurant constructor
    Restaurant(string n, double rating = 0) : RestaurantName(n), RestaurantsRating(rating) {}
    // decontructor
    ~Restaurant(){};

    // print restaurant name and rating
    void printInfo();

    //get Restaurants name
    string getName() const;

    //show menu
    void showMenu(const vector<Restaurant>& restaurant);
};

// MenuDisplay class (created by -)
class MenuDisplay : public Restaurant {
protected:
    // map for storing menu items
    map<string, double> menu {};

public:
    
    /* functions to (respectively): 
        - display all menu items with prices
        - display specific item given a name
        - read menu data from file and puts it into map
    */
    void displayWholeMenu() const;
    void displayItem(const string& itemName) const;
    void fileReader(const string& file);
    
    map<string, double> getMenu(const map<string, double>& menu) {
        return menu;
    }

    // destructor
    ~MenuDisplay() = default;

    friend class Cart;
    
};

#endif // RESTAURANT_MENU_H
