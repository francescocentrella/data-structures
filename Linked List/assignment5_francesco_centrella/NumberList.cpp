// Implementation file for the NumberList class
#include <iostream>  // For cout
#include "NumberList.h"
using namespace std;

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************

void NumberList::appendNode(double num)
{
   ListNode *newNode;  // To point to a new node
   ListNode *nodePtr;  // To move through the list

   // Allocate a new node and store num there.
   newNode = new ListNode;
   newNode->value = num;
   newNode->next = nullptr;

   // If there are no nodes in the list
   // make newNode the first node.
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end.
   {
      // Initialize nodePtr to head of list.
      nodePtr = head;

      // Find the last node in the list.
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node.
      nodePtr->next = newNode;
   }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void NumberList::displayList() const
{
    cout << "This linked list currently has ";
    cout << size();
    cout << " nodes :" << endl;



   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      cout << nodePtr->value << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
}


//*****************************************************************************************
//Dynamically create a new ListNode structure and store Val in the value field in it.
//Assuming the current list is sorted, this member function insert the ListNode structure 
//  into the linked list to maintain a sorted linked list.
//In other words, the values in the ListNode structure in the list are in ascending order.
//*****************************************************************************************

void NumberList::insertNode(double num)
{
   ListNode *newNode;					// A new node
   ListNode *nodePtr;					// To traverse the list
   ListNode *previousNode = nullptr;	// The previous node

   // Allocate a new node and store num there.
   newNode = new ListNode;
   newNode->value = num;
   
   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to nullptr.
      previousNode = nullptr;

      // Skip all nodes whose value is less than num.
      while (nodePtr != nullptr && nodePtr->value < num)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void NumberList::deleteNode(double num)
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode=nullptr;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;
   
   // Determine if the first node is the one.
   if (head->value == num)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is 
      // not equal to num.
      while (nodePtr != nullptr && nodePtr->value != num)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list, 
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr != nullptr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}




//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

NumberList::~NumberList()
{ 
    ListNode* nodePtr;   // To traverse the list
    ListNode* nextNode;  // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}


//******************************************************                                      *
// This clearList function deletes every node in the list.   
// The implementation here is essentially the same 
//   as the code the destructor execept that
// head must be set to nullprt to indicate an empty list
//**************************************************
void NumberList::clearList()
{
    ListNode* nodePtr;   // To traverse the list
    ListNode* nextNode;  // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }

    // set head to nullprt to indicate an empty list
    head = nullptr;

}

//******************************************************                                      *
// This size member function 
//   return the number of elements in the linked list.   
//**************************************************
int NumberList::size() const
{
    //initialize a pointer to ListNode and size
    ListNode *nodePtr;
    int size = 0;
    
    //if there is not a head return 0
    if(!head)
    {
        return size;
    }
    //if there is a head count how many nodes
    else
    {
        nodePtr = head;
        while(nodePtr != nullptr){
            size++;
            nodePtr = nodePtr->next;
        }
    }
    // return the final size
    return size;
}

//**************************************************
//Dynamically create a new ListNode structure and 
//  store Val in the Value field in it.
//Then insert the ListNode structure as 
//  the first node in the linked list.
//**************************************************
void NumberList::insertInFront(double Val)
{
    ListNode *nodePtr;
    
    //create a new node and store the value
    nodePtr = new ListNode();
    nodePtr->value = Val;
    nodePtr->next = nullptr;
    
    //if there is not any nodes put it as first
    if(!head) {
        head = nodePtr;
    }
    // if there is have the new first node point to the head and set the head as nodePtr
    else {
        nodePtr->next = head;
        head = nodePtr;
    }
}
