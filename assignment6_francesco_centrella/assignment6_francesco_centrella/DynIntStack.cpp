#include <iostream>
#include "DynIntStack.h"
using namespace std;

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

DynIntStack::~DynIntStack()
{
   StackNode *nodePtr = nullptr, *nextNode = nullptr;

   // Position nodePtr at the top of the stack.
   nodePtr = top;

   // Traverse the list deleting each node.
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************

void DynIntStack::push(char ch)
{
   StackNode *newNode = nullptr; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   newNode->value = ch;

   // If there are no nodes in the list
   // make newNode the first node.
   if (isEmpty())
   {
      top = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert NewNode before top.
   {
      newNode->next = top;
      top = newNode;
   }
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************

void DynIntStack::pop(char &ch)
{
   StackNode *temp = nullptr; // Temporary pointer

   // First make sure the stack isn't empty.
   if (isEmpty())
   {
      cout << "The stack is empty.\n";
   }
   else  // pop value off top of stack
   {
      ch = top->value;
      temp = top->next;
      delete top;
      top = temp;
   }
}

//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************

bool DynIntStack::isEmpty()
{
   bool status;

   if (!top)
      status = true;
   else
      status = false;

   return status;
}

char DynIntStack::stackTop()
{
    return top->value;
}

int DynIntStack::precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/' || op == '%')
        return 2;
    return 3;
}

string DynIntStack::convertToPostfix(string &infix)
{
    string postfix;
    push('(');
    infix = infix += ')';
    char trash = 'n';
    for(char ch : infix)
    {
        if (isdigit(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
        {
            while (stackTop() == '+' || stackTop() == '-' || stackTop() == '*' || stackTop() == '/' || stackTop() == '^' || stackTop() == '%')
            {
                if(precedence(ch) < precedence(stackTop()) || precedence(ch) == precedence(stackTop()))
                {
                    postfix += stackTop();
                    pop(trash);
                } else {
                    break;
                }
            }
            push(ch);
        }
        else if(ch == ')') {
            while(stackTop() != '(') {
                postfix += stackTop();
                pop(trash);
            }
            pop(trash);
        }
    }
    
    return postfix;
}

