#ifndef ALCOHOLADDON_H
#define ALCOHOLADDON_H

#include <string>
#include <vector>
using namespace std;

class AlcoholAddOn {
	
private:
	vector <string> drinks;
	vector <double> prices;
	double selectedPrice;
	
public:
	AlcoholAddOn();
	
	void displayDrinkMenu() const;
	void selectDrink(int choice);
	double getSelectedPrice() const;
	double getDrinkPrice(int choice);
	
	void confirmPurchase() const;
};

#endif
