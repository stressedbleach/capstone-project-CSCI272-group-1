#ifndef ALCOHOLADDON_H
#define ALCOHOLADDON_H

#include <string>
#include <vector>
using namespace std;

class AlcoholAddOn {
	
private:
// list of drink names 
	vector <string> drinks;
// list of drink prices (same order as the names)
	vector <double> prices;
// price of drink that the user picked
	double selectedPrice;
	
public:
// sets up the drink list and starting values
	AlcoholAddOn();
	// shows the alcohol menu to the user
	void displayDrinkMenu() const;
   // saves the user's drink choice
	void selectDrink(int choice);
   // Gives the price of the drink the user picked
	double getSelectedPrice() const;
   // Gives the price of the drink based on the choice number
	double getDrinkPrice(int choice);
   // Shows the message confirming the user's purchase
	void confirmPurchase() const;
};

#endif

