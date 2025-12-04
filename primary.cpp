#include "Restaurant.h"

// No need to redefine the constructor here if it's already in the header
// No need to redefine printInfo() here either

int main() {
   // List of Restaurant
   vector<Restaurant>restaurant ={
     Restaurant("Onii-Chan Burgers", 5.0),
     Restaurant ("Moe Lezzor's Bakery" , 3.4),
     Restaurant ("Raising Brain Tenders", 4.5), 
     Restaurant("Brown Blaze Pizza", 3.9), 
     Restaurant(" Slurpies Spot" , 2.9) 
   };
   
  // menu to select the Restaurant 
  showMenu(restaurant); 
  
  
   int choice; 
   cout << "Enter your choice: "; 
   cin >> choice; 
   
while (cin.fail() || choice < 1 || choice > restaurant.size()) {
       cin.clear(); // cllear error
       cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the bad iinptut 
      cout << "Invlaid choice. Try again: "; 
	   cin >> choice; 
   }
   
   // show info for the selected restaurant
   
   cout << "\nYou selected: \n"; 
   restaurant[choice - 1].printInfo(); 
   return 0 ;
   
    // Wait before returning to menu
        cout << "\nPress ENTER to go back to the menu...";
        cin.ignore();
        cin.get();
    }

