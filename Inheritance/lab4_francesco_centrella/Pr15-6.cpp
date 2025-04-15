// This program demonstrates the Car, Truck, and SUV
// classes that are derived from the Automobile class.
#include <iostream>
#include <iomanip>
#include "Car.h"
#include "Truck.h"
#include "SUV.h"
#include "HybridVehicle.h"
using namespace std;

int main()
{
    bool on = true;
    char choice;
    string make;
    int model, mileage, doors, passengers;
    double price, batteryCapacity, fuelEfficiency;
    string driveType;
    
    while (on)
    {
        cout << "\nSelect your choice\n";
        cout << "1.Car\n";
        cout << "2.Truck\n";
        cout << "3.SUV\n";
        cout << "4.Hybrid\n";
        cout << "q.To quit\n";
        cin >> choice;
        cout << "\n";
        switch (choice) {
            case '1': {
                cout << "Enter Car details:\n";
                cout << "Make: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                cout << "Mileage: ";
                cin >> mileage;
                cout << "Price: ";
                cin >> price;
                cout << "Doors: ";
                cin >> doors;
                Car car(make, model, mileage, price, doors);
                car.displayCarSpecs();
                break; }
            case '2':{
                cout << "Enter Truck details:\n";
                cout << "Make: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                cout << "Mileage: ";
                cin >> mileage;
                cout << "Price: ";
                cin >> price;
                cout << "DriveType: ";
                cin >> driveType;
                Truck truck(make, model, mileage, price, driveType);
                truck.displayTruckSpecs();
                break; }
            case '3':{
                cout << "Enter SUV details:\n";
                cout << "Make: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                cout << "Mileage: ";
                cin >> mileage;
                cout << "Price: ";
                cin >> price;
                cout << "Number Passengers: ";
                cin >> passengers;
                SUV suv(make, model, mileage, price, passengers);
                suv.displaySUVSpecs();
                break; }
            case '4':{
                cout << "Enter Hybrid details:\n";
                cout << "Make: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                cout << "Mileage: ";
                cin >> mileage;
                cout << "Price: ";
                cin >> price;
                cout << "Battery capacity: ";
                cin >> batteryCapacity;
                cout << "Fuel Efficiency: ";
                cin >> fuelEfficiency;
                HybridVehicle hybrid (make, model, mileage, price, batteryCapacity, fuelEfficiency);
                hybrid.displayHybridSpecs();
                break; }
            case 'q':
            case 'Q': {
                on = false;
                break;
            }
            default:
                cout << "Invalid Input, try again\n";
                break;
        }
    }
    return 0;
}
