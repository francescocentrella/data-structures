//
//  PieceWorker.hpp
//  assignment4_task2_francescocentrella
//
//  Created by Francesco Centrella on 02/04/25.
//

#ifndef PieceWorker_hpp
#define PieceWorker_hpp

#include <string> // C++ standard string class
#include "Employee.h" // Employee class definition

class PieceWorker : public Employee {
public:
   PieceWorker( const std::string &, const std::string &,
      const std::string &, double = 0.0 , double = 0.0);
   virtual ~PieceWorker() { } // virtual destructor

   void setWage( double ); // set weekly salary
   double getWage() const; // return weekly salary
    void setPieces (double);
    double getPieces () const;
    

   // keyword virtual signals intent to override
   virtual double earnings() const override; // calculate earnings
   virtual void print() const override; // print object
private:
   double wage;
    double pieces;
};
#endif
