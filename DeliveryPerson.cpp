#include "DeliveryPerson.h"
#include <iostream>
using namespace std;

// Default Constructor
DeliveryPerson::DeliveryPerson() {
    name = "Unknown";
    carModel = "Unknown";
    licensePlate = "Unknown";
    deliveryTime = 0;
}

// Parameterized Constructor
DeliveryPerson::DeliveryPerson(string n, string car, string lplate, int dtime){
name = n;
carModel = car;
licensePlate = lplate;
deliveryTime = dtime;
}


// setters
void DeliveryPerson::setName(const string& n){
    name = n;
}

void DeliveryPerson::setCarModel(const string& car){
    carModel = car;
}

void DeliveryPerson::setLicensePlate(const string& lplate){
    licensePlate = lplate;
}

void DeliveryPerson::setDeliveryTime(int dtime){
    deliveryTime = dtime;
}


//getters
string DeliveryPerson::getName() const{
    return name;
}

string DeliveryPerson::getCarModel() const{
    return carModel;
}

string DeliveryPerson::getLicensePlate() const{
    return licensePlate;
}

int DeliveryPerson::getDeliveryTime() const{
    return deliveryTime;
}

void DeliveryPerson::displayDeliveryInfo() const{
cout << "Delivery Person: " << name 
     << " | Car: " << carModel
     << " | License Plate: " << licensePlate
     << " | Time until delivery: " << deliveryTime << " minutes"
     << endl;
}