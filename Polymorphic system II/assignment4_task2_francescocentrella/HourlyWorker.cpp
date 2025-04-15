//
//  HourlyWorker.cpp
//  assignment4_task2_francescocentrella
//
//  Created by Francesco Centrella on 02/04/25.
//

#include <iostream>
#include <stdexcept>
#include "HourlyWorker.h" // SalariedEmployee class definition
using namespace std;

// constructor
HourlyWorker::HourlyWorker( const string &first,
   const string &last, const string &ssn, double w, double h)
   : Employee( first, last, ssn )
{
    setWage(w);
    setHours(h);
} // end SalariedEmployee constructor

// set salary
void HourlyWorker::setWage( double w )
{
   if ( w >= 0.0 )
       wage = w;
   else
      throw invalid_argument( "Wage must be >= 0.0" );
} // end function setWeeklySalary

// return salary
double HourlyWorker::getWage() const
{
   return wage;
} // end function getWeeklySalary

void HourlyWorker::setHours( double h )
{
    if ( h >= 0.0 )
        hours = h;
   else
      throw invalid_argument( "Hours must be >= 0.0" );
} // end function setWeeklySalary

// return salary
double HourlyWorker::getHours() const
{
    return hours;
} // end function getWeeklySalary

// calculate earnings;
// override pure virtual function earnings in Employee
double HourlyWorker::earnings() const
{
    if(hours > 40){
        return ((wage * 40) + ((wage * 1.5) * (hours - 40)));
    }
    else {
        return (wage * hours);
    }
} // end function earnings


void HourlyWorker::print() const
{
   cout << "salaried employee: ";
   Employee::print(); // reuse abstract base-class print function
    cout << "\nwage: " << wage;
    cout << "\nhours: " << hours;
} // end function print
