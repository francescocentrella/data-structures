// Define member functions of class DateType.
// This is file DateType.cpp.

#include "DateType.h" // gain access to specification of class
#include <iostream>
using namespace std;

//The first constructor method to initialize a DateType object
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
DateType::DateType()
{
  year = 2000;
  month = 1;
  day = 1;
}


//The second constructor method to initialize a DateType object
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
DateType::DateType(int newMonth, int newDay, int newYear)
{
    year = newYear;
    month = newMonth;
    day = newDay;
    if (!IsValidDate(month, day, year))
    {
        cout << "Invalid date.";
        year = 2000;
        month = 1;
        day = 1;
    }
}


//A method to set a new date for the DateType object.
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//   do not change the date stored in the object and then return false.
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
//   and then return true.
bool DateType::SetDate(int newMonth, int newDay, int newYear)
{
    if(IsValidDate(newMonth, newDay, newYear))
    {
        year = newYear;
        month = newMonth;
        day = newDay;
        return true;
    }
    return false;
}

int DateType::MonthIs()
// Accessor function for data member month.
{
  return month;
}

int DateType::YearIs()
// Accessor function for data member year.
{
  return year;
}


int DateType::DayIs()
// Accessor function for data member day.
{
    return day;
}


void DateType::ReadDate()
{
	cout << endl 
		 << "Read in the information of a date: " ;
    bool validdate = false;
		 
    while(!validdate)
    {
        cout << endl << "The month is: ";
        cin >> month;
        cout << endl << "The day is: ";
        cin >> day;
        cout << endl << "The year is: ";
        cin >> year;
        if(IsValidDate(month, day, year))
        {
            validdate = true;
        }
    }
}

void DateType::PrintDate()
{
	//Implement your code here
    cout << month << "/" << day << "/" << year << endl;
}


int DateType::ComparedTo(DateType aDate)
// Pre: Self and aDate have been initialized.
// Post: return
//  LESS, if self comes before aDate.
//  EQUAL, if self is the same as aDate.
//  GREATER, if self comes after aDate.
{
    if(year > aDate.year)
    {
        return GREATER;
    }
    else if(year < aDate.year)
    {
        return LESS;
    }
    else
    {
        if(month > aDate.month)
        {
            return GREATER;
        }
        else if(month < aDate.month)
        {
            return LESS;
        }
        else
        {
            if(day > aDate.day)
            {
                return GREATER;
            }
            else if(day < aDate.day)
            {
                return LESS;
            }
        }
    }
    
    return EQUAL;
}

int DateType::ComparedCentury(DateType aDate)
// Pre: Self and aDate have been initialized.
// Post: return
//	LESS, if the object itSelf comes before the century of aDate.
//	EQUAL, if the object itSelf is in the same century as aDate.
//	GREATER, if the object itSelf comes after the century of aDate.
{
    int temp_year1 = (year / 100) + 1;
    int temp_year2 = (aDate.year / 100) + 1;
    
    if(temp_year1 > temp_year2)
    {
        return GREATER;
    }
    else if (temp_year1 < temp_year2)
    {
        return LESS;
    }
    
    return EQUAL;
}


void DateType::AdvanceDays(int NumDays)
{
    if (NumDays < 0)
    {
        DateType::BackDays(abs(NumDays));
    }
    else
    {
        for(int i = 0; i < NumDays; i++)
        {
            if (day < 28)
            {
                day++;
            }
            else if (day == 28)
            {
                if (month == 2)
                {
                    if (year % 400 == 0 || year % 4 == 0)
                    {
                        day++;
                    }
                    else
                    {
                        day = 1;
                        month++;
                    }
                }
                else
                {
                    day++;
                }
            }
            else if (day == 29)
            {
                if (month == 2)
                {
                    day = 1;
                    month++;
                }
                else
                {
                    day++;
                }
            }
            else if (day == 30)
            {
                if(month == 4 || month == 6 || month == 9 || month == 11)
                {
                    day = 1;
                    month++;
                }
                else
                {
                    day++;
                }
            }
            else
            {
                day = 1;
                if(month == 12)
                {
                    month = 1;
                    year++;
                }
                else
                {
                    month++;
                }
            }
        }
    }
}

void DateType::BackDays(int NumDays)
{
    if (NumDays < 0)
    {
        DateType::AdvanceDays(abs(NumDays));
    }
    for(int i = 0; i < NumDays; i++)
    {
        if (day > 1)
        {
            day--;
        }
        else
        {
            if (month == 3)
            {
                if(year % 400 != 0 && year % 4 != 0)
                {
                    day = 28;
                    month--;
                }
                else
                {
                    day = 29;
                    month--;
                }
            }
            else if(month == 5 || month == 7 || month == 10 || month == 12)
            {
                day = 30;
                month--;
            }
            else
            {
                if (month == 1)
                {
                    day = 31;
                    month = 12;
                    year--;
                }
                else
                {
                    day = 31;
                    month--;
                }
            }
        }
    }
}

bool DateType::IsValidDate(int newMonth, int newDay, int newYear)
{
    if (newDay < 1 || newDay > 31 || newMonth < 1 || newMonth > 12 || newYear < 0)
    {
        return false;
    }
    if (newMonth == 2)
    {
        if(newYear % 400 == 0 || newYear % 4 == 0)
        {
            if (newDay > 29)
            {
                return false;
            }
        }
        else
        {
            if (newDay > 28)
            {
                return false;
            }
        }
    }
    else if(newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11)
    {
        if (newDay > 30)
        {
            return false;
        }
    }
    return true;
}
