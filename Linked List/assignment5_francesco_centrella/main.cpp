// File: main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "NumberList.h"
using namespace std;

int main()
{
  NumberList myList;

  char c;

  cout<< endl << endl
      << "********************************************" << endl
      << "Test A: Working as a \"sorted\" linked list" << endl
      << "********************************************" << endl;

  cout << endl << "Insert 3 by calling myList.InsertNode(3)"  << endl;
  myList.insertNode(3);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();
  cout << endl << "Insert 4 by calling myList.insertNode(4)"  << endl;
  myList.insertNode(4);
  cout << endl << "Display the contents of list" << endl;
  myList.displayList();

  cout << endl << "Enter c to continue" << endl << endl;
  cin >>c;

  cout << endl << "Insert 9 by calling myList.insertNode(9)"  << endl;
  myList.insertNode(9);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();
  cout << endl << "Insert 2 by calling myList.insertNode(2)"  << endl;
  myList.insertNode(2);
  cout << endl << "Display the contents of list" << endl;
  myList.displayList();

  cout << endl << "Enter c to continue" << endl << endl;
  cin >>c;

  cout << endl << "Remove 4 by calling myList.deleteNode(4)"  << endl;
  myList.deleteNode(4);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();
  cout << endl << "Remove 2 by calling myList.deleteNode(2)"  << endl;
  myList.deleteNode(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();

  cout << endl << "Enter c to continue" << endl << endl;
  cin >>c;
  
  cout << "********************************************" << endl
      << " Do 100000 random insertions in a sorted list: myList.insertNode( rand() )  " << endl
      << "********************************************" << endl;
  cout << "Started!!! ";
  for (int i = 0; i < 100000; i++)
      myList.insertNode(rand());
  cout << endl << "Finished!!! ===>  It takes a good amount of time. Why?" << endl
      << "Enter c to continue:" << endl << endl;
  cin >> c;
  
  cout << endl << "Clear the whole list"  << endl;
  myList.clearList();
  cout << "********************************************" << endl
       << " myList.clearList();  " << endl
       << "********************************************" << endl;

  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();

  cout << endl << "Enter c to continue" << endl << endl;
  cin >>c;




  cout<< endl << endl
      << "********************************************" << endl
      << "Test B: Working as a \"unsorted\" linked list" << endl
      << "********************************************" << endl;

  cout << endl << "Insert 3 by calling myList.insertInFront(3)"  << endl;
  myList.insertInFront(3);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();
  cout << endl << "Insert 4 by calling myList.insertInFront(4)"  << endl;
  myList.insertInFront(4);
  cout << endl << "Display the contents of list" << endl;
  myList.displayList();

  cout << endl << "Enter c to continue" << endl << endl;
  cin >>c;

  cout << endl << "Insert 9 by calling myList.insertInFront(9)"  << endl;
  myList.insertInFront(9);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();
  cout << endl << "Insert 2 by calling myList.insertInFront(2)"  << endl;
  myList.insertInFront(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();

  cout << endl << "Insert 2 again by calling myList.insertInFront(2)"  << endl;
  myList.insertInFront(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();

  cout << endl << "Enter c to continue" << endl << endl;
  cin >>c;

  cout << endl << "Remove 4 by calling myList.deleteNode(4)"  << endl;
  myList.deleteNode(4);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();
  cout << endl << "Remove 2 by calling myList.deleteNode(2)"  << endl;
  myList.deleteNode(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();

  cout << endl << "Try to remove 2 again by calling myList.deleteNode(2)"  << endl;
  myList.deleteNode(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.displayList();

  cout << endl << "Enter c to continue" << endl << endl;
  cin >>c;


  cout << "********************************************" << endl
      << " Do 100000 random insertions in an unsorted list: myList.insertInFront( rand() )  " << endl
      << "********************************************" << endl;
  cout << "Started!!! ";
  for (int i = 0; i < 100000; i++)
      myList.insertInFront(rand());
  cout << endl << "Finished!!! ===>  It is so fast. Why?" << endl
      << "Enter c to continue:" << endl << endl;
  cin >> c;

  cout << endl << "Clear the whole list" << endl;
  myList.clearList();
  cout << "********************************************" << endl
      << " myList.clearList();  " << endl
      << "********************************************" << endl;

  cout<< endl << endl
      << "*************************************************************" << endl
      << "This is the end of demonstration. Enter a character to quit" << endl
      << "*************************************************************" << endl;

  char x; cin >>x;


}




