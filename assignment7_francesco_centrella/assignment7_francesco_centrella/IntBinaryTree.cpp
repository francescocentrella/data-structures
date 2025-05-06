// Implementation file for the IntBinaryTree class
#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void IntBinaryTree::insert(TreeNode *  &nodePtr, TreeNode * & newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void IntBinaryTree::insertNode(int num)
{
   TreeNode *newNode = nullptr;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = num;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool IntBinaryTree::searchNode(int num)
{
   TreeNode *nodePtr = root;

   //As long as there is a node to examine
   while (nodePtr)
   {
      //Check whether the node contains the value we are searching for
      if (nodePtr->value == num)
         return true;
      //Check whether should go to the left
      else if (num < nodePtr->value)
         nodePtr = nodePtr->left;  //Go to the left
      else // (num > nodePtr->value) must be true
         nodePtr = nodePtr->right; //Go to the right
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void IntBinaryTree::remove(int num)
{
   deleteNode(num, root);
}


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
   //*******************************************************
   //The code from the texbook misses this "if" statement and 
   // crashes when the num to delete is not in the tree
   //*******************************************************
   if (nodePtr == nullptr)
        return;

   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void IntBinaryTree::makeDeletion(TreeNode * & nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr = nullptr;

   if (nodePtr == nullptr) //nullptr: Nothing to delete
     return;
   else if (nodePtr->right == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   else // When the node has two children.
   {
       // Search along the the right subtree 
       //        of the node pointed to by nodePtr.
       TreeNode* parentNodePtr = nodePtr;
       TreeNode* currentNodePtr = nodePtr->right;

       // Keep going to the left as far as it can be
       //    to locate the node that contains 
       //    the minimum of the entire right subtree.
       while (currentNodePtr->left)
       {
           parentNodePtr = currentNodePtr;
           currentNodePtr = currentNodePtr->left;
       }

       //Copy the minimum value of the right subtree to 
       //   overwrite the value to delete 
       //   in the node pointed to by nodePtr;
       //This essentailly remove the value from the tree
       nodePtr->value = currentNodePtr->value;

       //Prepare to delete 
       //  the node containing the minimum of the right subtree
       //  i.e. the node pointed to by currentNodePtr
       //Properly re-wire its parent node to
       // point to the right subtree of the node pointed to by currentNodePtr
       if (parentNodePtr == nodePtr)
           //Case 1: In this case, the node to delete
           //        is the right child of its parent;
           //Therefore, update the "right" pointer of the parent to
           //  point to the right subtree of the node to delete.
           parentNodePtr->right = currentNodePtr->right;
       else
           //Case 2: In this case, the node to delete
           //        is the left child of its parent
           //Therefore, update the "left" pointer of the parent to
           //  point to the right subtree of the node to delete.
           parentNodePtr->left = currentNodePtr->right;

       //Delete the node containing the minimum of the right subtree
       delete currentNodePtr;
   }

   //********************************************
   //* The flawed version in the textbook below, removed 
   //********************************************
   //********************************************
   //   Some subtle flaws in the code from textbook version below
   //       leading to a run-time stack overflow issue 
   //   for doDeletionTestOption menu option in the main function
   //   when  dealing a large number of deletion operations
   //********************************************
   /*
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
   */

}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

//************************************
 //Added for Programming 7
 //************************************
int IntBinaryTree::branchHeight(TreeNode* ptrNode) const
{
    int rightBranch = 0;
    int leftBranch = 0;
    if (ptrNode == nullptr)
        return 0;
    
    leftBranch = branchHeight(ptrNode->left);
    rightBranch = branchHeight(ptrNode->right);
    
    if(rightBranch > leftBranch)
        return (rightBranch + 1);
    return (leftBranch + 1);
}

int IntBinaryTree::branchSize(TreeNode* ptrNode) const
{
    int rightBranch = 0;
    int leftBranch = 0;
    if (ptrNode == nullptr)
        return 0;
    
    leftBranch = branchSize(ptrNode->left);
    rightBranch = branchSize(ptrNode->right);
    
    return (rightBranch + leftBranch + 1);
}
