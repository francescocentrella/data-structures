#ifndef AUXIL_H
#define AUXIL_H
class Budget;

class AuxiliaryOffice {
private:
    double auxBudget;
public:
    AuxiliaryOffice()
    { auxBudget = 0;}
    double getDivisionBudget() const
    { return auxBudget;}
    void addBudget(double, Budget &);
    void subtractBudget(double, Budget &);
};

#endif
