#include "Menu.h"

void Restaurant::printInfo() {
    cout << "Restaurant Name: " << RestaurantName << ", Rating: " << RestaurantsRating << endl;
}

string Restaurant::getName() const {
    return RestaurantName;
}

void Restaurant::showMenu(const vector<Restaurant>& restaurant){
    cout << "Select a Restaurant by number:\n";
    for (size_t i = 0; i < restaurant.size(); ++i) {
        cout << i + 1 << "." << restaurant[i].getName() << endl;
        }
}

void MenuDisplay::displayWholeMenu() const {
    cout << RestaurantName << "Menu: \n";
    for (const auto& item : menu) {
        cout << item.first << ": $" << fixed << setprecision(2) << item.second << '.' << "\n";
    }
    cout << RestaurantName << "Rating: " << RestaurantsRating << "/5\n";
}

void MenuDisplay::displayItem(const string& itemName) const {
    cout << RestaurantName << "Menu: \n";

    auto it = menu.find(itemName);
    if (it != menu.end()) {
        cout << it->first << ": $" << fixed << setprecision(2) << it->second << '\n';
    }
}

void MenuDisplay::fileReader(const string& file) {
    ifstream menuFile(file);
    string item;

    while (getline(menuFile, item)) {
        istringstream wholeMenu(item);
        
        string itemName;
        string itemPrice;

        getline(wholeMenu, itemName, '|');
        getline(wholeMenu, itemPrice);

        double price = stod(itemPrice);
        menu.insert({itemName, price});
    }

    menuFile.close();
}

