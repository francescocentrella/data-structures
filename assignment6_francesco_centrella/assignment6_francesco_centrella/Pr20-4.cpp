// This program demonstrates the dynamic stack
// class DynIntClass.
#include <iostream>
#include "DynIntStack.h"
using namespace std;

string preproString(const string& str) {
    string processedStr;
    for (char ch : str) {
        if (isalnum(ch)) {
            processedStr += tolower(ch);
        }
    }
    return processedStr;
}

int main()
{
    char choice;
    cout << "Press 1 to check the palindrome checker\n";
    cout << "Press 2 to check the postfix operation\n";
    cin >> choice;
    cin.ignore();
    DynIntStack stack;
    
    if(choice == '1')
    {
        string pol;	// To hold values popped off the stack
        
        cout << "Insert the sequence to check: ";
        getline(cin, pol);
        
        pol = preproString(pol);
        
        for(char ch : pol)
        { stack.push(ch); }
        
        bool isPolindrome = true;
        
        for (char ch : pol)
        {
            char lastCh;
            stack.pop(lastCh);
            if(ch != lastCh) {
                isPolindrome = false;
                break;
            }
        }
        
        if(isPolindrome) {
            cout << "It is a Polindrome\n";
        }
        else {
            cout << "it is not a Polindrome\n";
        }
    }
    
    
    if (choice == '2')
    {
        string infix;
        
        cout << "Enter your mathematical operation: ";
        getline(cin, infix);
        
        string postfix = stack.convertToPostfix(infix);
        for (char ch : postfix)
        {
            cout << ch << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
