
#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include <string> // C++ standard string class
#include "Employee.h" // Employee class definition


class HourlyWorker : public Employee {
public:
   HourlyWorker( const std::string &, const std::string &,
      const std::string &, double = 0.0 , double = 0.0);
   virtual ~HourlyWorker() { } // virtual destructor

   void setWage( double ); // set weekly salary
   double getWage() const; // return weekly salary
    void setHours (double);
    double getHours () const;
    

   // keyword virtual signals intent to override
   virtual double earnings() const override; // calculate earnings
   virtual void print() const override; // print object
private:
   double wage;
    double hours;
};

#endif
