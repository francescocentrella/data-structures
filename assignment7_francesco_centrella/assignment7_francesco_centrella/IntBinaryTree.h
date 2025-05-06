// Specification file for the IntBinaryTree class
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

#include <iostream>
using namespace std;

class IntBinaryTree
{
private:
   struct TreeNode
   {
      int value;         // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   TreeNode *root;       // Pointer to the root node
   
   // Private member functions
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(int, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;

   //************************************
   //Added for Programming 7
   //************************************
   int branchHeight(TreeNode* ptrNode) const;
   int branchSize(TreeNode* ptrNode) const;

public:
   // Constructor
   IntBinaryTree()
      { root = nullptr; }
      
   // Destructor
   ~IntBinaryTree()
      { destroySubTree(root); }

      
   // Binary tree operations
   void insertNode(int);
   bool searchNode(int);
   void remove(int);
   
   //Tree trversal: In Order
   void displayInOrder() const
      {  displayInOrder(root); }
      
   //Tree trversal: Pre Order
   void displayPreOrder() const
      {  displayPreOrder(root); }
      
   //Tree trversal: Post Order
   void displayPostOrder() const
      {  displayPostOrder(root); }

   //************************************
   //Added for Programming 7
   //************************************

   // Clear (empty) the tree
   void clear()
   {
       destroySubTree(root);
       root = nullptr;
   }

   //height of the tree
   int height( ) const
   {
       //Replace the following with your own code
       branchHeight(root);
       return 0;
   }

   //size of the tree
   int size() const
   {
       //Replace the following with your own code
       branchSize(root);
       return 0;
   }


};
#endif
