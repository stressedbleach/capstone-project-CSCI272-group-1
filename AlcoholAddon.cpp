#include "AlcoholAddOn.h"
#include <iostream>
// Sets up the drink names when the object is created
AlcoholAddOn::AlcoholAddOn() {
    drinks = {"Wolverine Wine", "LeHenny", "67 Quila"};
    prices = {14.99, 22.49, 11.25};
}
// Shows the alcohol menu to the user
void AlcoholAddOn::displayDrinkMenu() {
    cout << "\n=== Alcohol Add-On Menu ===\n";
    // Lists each drink with its price
    for (int i = 0; i < drinks.size(); i++) {
        cout << i + 1 << ". " << drinks[i]
             << " - $" << prices[i] << endl;
    }
    // Option if the user does not want alcohol
    cout << "0. No Alcohol for Me Man\n";
    cout << "Choose an option: ";
}
// Gives the price of the drink the user picked
// If the choice is not valid, returns 0
double AlcoholAddOn::getDrinkPrice(int choice) {
    if (choice <= 0 || choice > prices.size()) {
        return 0.0;
    }
    return prices[choice - 1];
}
// Gives the name of the drink the user picked
// If the choice is not valid, it returns a message
string AlcoholAddOn::getDrinkName(int choice) {
    if (choice <= 0 || choice > drinks.size()) {
        return "No Drink Selected";
    }
    return drinks[choice - 1];

}
