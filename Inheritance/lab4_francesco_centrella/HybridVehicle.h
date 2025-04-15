#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H
#include "Automobile.h"
#include <string>

class HybridVehicle : public Automobile
{
private:
    double battery_capacity;
    double fuel_efficiency;
public:
    HybridVehicle() : Automobile()
    {battery_capacity = 0;
        fuel_efficiency = 0;}
    
    HybridVehicle(string carMake, int carModel, int carMilage, double carPrice,
                  double h_battery_capacity, double h_fuel_efficiency) :
    Automobile(carMake, carModel, carMilage, carPrice)
    {battery_capacity = h_battery_capacity;
        fuel_efficiency = h_fuel_efficiency;}
    
    
    void displayHybridDetails(){
        cout << getMake() << " " << getModel() << " with " << battery_capacity << " capacity, " << getMileage()
        << " miles, and " << fuel_efficiency << " of fuel capacity. Price: $" << getPrice() << endl;
    }
    
    void displayHybridSpecs(){
        displaySpecs();
        cout << "Battery Capacity: " << getBattery() << "%\n";
        cout << "Fuel Efficiency: " << getFuel() << "\n";
    }
    
    double getBattery()
    {return battery_capacity;}
    double getFuel()
    {return fuel_efficiency;}
};
#endif
