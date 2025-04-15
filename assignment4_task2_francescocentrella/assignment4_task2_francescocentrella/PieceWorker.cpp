//
//  PieceWorker.cpp
//  assignment4_task2_francescocentrella
//
//  Created by Francesco Centrella on 02/04/25.
//

#include <iostream>
#include <stdexcept>
#include "PieceWorker.hpp" // SalariedEmployee class definition
using namespace std;

// constructor
PieceWorker::PieceWorker( const string &first,
   const string &last, const string &ssn, double w, double p)
   : Employee( first, last, ssn )
{
    setWage(w);
    setPieces(p);
} // end SalariedEmployee constructor

// set salary
void PieceWorker::setWage( double w )
{
   if ( w >= 0.0 )
       wage = w;
   else
      throw invalid_argument( "Wage must be >= 0.0" );
} // end function setWeeklySalary

// return salary
double PieceWorker::getWage() const
{
   return wage;
} // end function getWeeklySalary

void PieceWorker::setPieces( double p )
{
    if ( p >= 0.0 )
        pieces = p;
   else
      throw invalid_argument( "Hours must be >= 0.0" );
} // end function setWeeklySalary

// return salary
double PieceWorker::getPieces() const
{
    return pieces;
} // end function getWeeklySalary

// calculate earnings;
// override pure virtual function earnings in Employee
double PieceWorker::earnings() const
{
    return wage * pieces;
} // end function earnings


void PieceWorker::print() const
{
   cout << "salaried employee: ";
   Employee::print(); // reuse abstract base-class print function
    cout << "\nwage: " << wage;
    cout << "\npieces: " << pieces;
} // end function print
