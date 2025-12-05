#include "AlcoholAddOn.h"
#include <iostream>

AlcoholAddOn::AlcoholAddOn() {
    drinks = {"Wolverine Wine", "LeHenny", "67 Quila"};
    prices = {14.99, 22.49, 11.25};
}

void AlcoholAddOn::displayDrinkMenu() {
    cout << "\n=== Alcohol Add-On Menu ===\n";
    for (int i = 0; i < drinks.size(); i++) {
        cout << i + 1 << ". " << drinks[i]
             << " - $" << prices[i] << endl;
    }
    cout << "0. No Alcohol for Me Man\n";
    cout << "Choose an option: ";
}

double AlcoholAddOn::getDrinkPrice(int choice) {
    if (choice <= 0 || choice > prices.size()) {
        return 0.0;
    }
    return prices[choice - 1];
}

string AlcoholAddOn::getDrinkName(int choice) {
    if (choice <= 0 || choice > drinks.size()) {
        return "No Drink Selected";
    }
    return drinks[choice - 1];
}