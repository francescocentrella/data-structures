// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
   // Declare a structure for the nodes
   struct ListNode
   {
      double value;           // The value in this node
      struct ListNode *next;  // To point to the next node
   }; 

   ListNode *head;            // List head pointer

public:
   // Constructor
   NumberList()
      { head = nullptr; }
      
   // Destructor
   ~NumberList();
      
   // Linked list operations
   
   //**************************************************
   // appendNode appends a node containing the        *
   // value pased into num, to the end of the list.   *
   //**************************************************
   void appendNode(double val);


   //*****************************************************************************************
   //Dynamically create a new ListNode structure and store Val in the value field in it.
   //Assuming the current list is sorted, this member function insert the ListNode structure 
   //  into the linked list to maintain a sorted linked list.
   //In other words, the values in the ListNode structure in the list are in ascending order.
   //*****************************************************************************************
   void insertNode(double val);

   //**************************************************
   // The deleteNode function searches for a node     *
   // with num as its value. The node, if found, is   *
   // deleted from the list and from memory.          *
   //**************************************************
   void deleteNode(double val);

   //**************************************************
   // displayList shows the value                     *
   // stored in each node of the linked list          *
   //**************************************************
   void displayList() const;

   //***********************************************
   //The following are additonal functions 
   //    not present in the textbook
   //***********************************************
   
   //***********************************************
   //Clear up the linked list to make it an empty list.
   //***********************************************
   void clearList();

   //***********************************************
   //Return the number of elements in the linked list.   
   //***********************************************
   int size() const;

   //***********************************************
   //Dynamically create a new ListNode structure and store Val in the Value field in it.
   //Then insert the ListNode structure as the first node in the linked list.
   //***********************************************
   void insertInFront(double Val);


};
#endif