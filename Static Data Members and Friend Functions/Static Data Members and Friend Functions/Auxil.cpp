#include "Auxil.h"
#include "Budget.h"

void AuxiliaryOffice::addBudget(double b, Budget &div) {
    auxBudget += b;
    div.corpBudget += b;
}

void AuxiliaryOffice::subtractBudget(double b, Budget &div) {
    auxBudget -= b;
    div.corpBudget -= b;
}
