
// DeliveryPerson.h

#ifndef DELIVERYPERSON_H
#define DELIVERYPERSON_H

#include <string>
using namespace std;

class DeliveryPerson {

    private:
        string name;
        string carModel;
        string licensePlate;
        int deliveryTime;

    public:
    DeliveryPerson(); // Default Constructor
    DeliveryPerson(string n, string car, string lplate, int dtime);

    // Setters
    void setName(const string& n);
    void setCarModel(const string&car);
    void setLicensePlate(const string& lplate);
    void setDeliveryTime(int dtime);

    // Getters
    string getName() const;
    string getCarModel() const;
    string getLicensePlate() const;
    int getDeliveryTime() const;

    void displayDeliveryInfo() const;
};

#endif // DELIVERYPERSON_H