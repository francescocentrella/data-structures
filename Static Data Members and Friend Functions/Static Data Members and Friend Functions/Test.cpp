#include <iostream>
#include <iomanip>
#include "Budget.h"
#include "Auxil.h"
using namespace std;

int main() {
    
    int count;
    int i;
    double mainOfficeRequest;
    const int NUM_DIVISIONS = 4;
    
    cout << "Enter the main office's budget request: ";
    cin >> mainOfficeRequest;
    Budget::mainOffice(mainOfficeRequest);
    
    Budget divisions[NUM_DIVISIONS];
    AuxiliaryOffice auxOffices[4];
    
    for (count = 0; count < NUM_DIVISIONS; count ++) {
        double budgetAmount;
        cout << "Divisions ";
        cout << (count +1) << ": $ ";
        cin >> budgetAmount;
        divisions[count].addBudget(budgetAmount);
        
        cout << "Auxiliary office: $ ";
        cin >> budgetAmount;
        auxOffices[count].addBudget(budgetAmount, divisions[count]);
    }
    
    cout << fixed << showpoint << setprecision(2);
    cout << "\nHere are the division budget requests: \n";
    
    for (count = 0; count < NUM_DIVISIONS; count++) {
        cout << "\tDivisions " << (count + 1) << "\t$ ";
        cout << divisions[count].getDivisionBudget() << endl;
        cout << "\tAuxiliary office:\t$ ";
        cout << auxOffices[count].getDivisionBudget() << endl << endl;
    }
    
    int request;
    
    cout << "Subtract Auxiliary office buget:What Auxiliary office [1-4]? : ";
    cin >> request;
    request++;
    
    double amountToSub;
    
    cout << "Enter the budget cut for that divison's auxiliary office: $ ";
    cin >> amountToSub;
    
    
    auxOffices[request].subtractBudget(amountToSub, divisions[request]);
    
    cout << "\tTotal Budget Requests: \t$ ";
    cout << divisions[0].getCorpBudget() << endl;
    
    return 0;
}


