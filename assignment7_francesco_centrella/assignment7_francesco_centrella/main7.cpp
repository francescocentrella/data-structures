

// This program demonstrates the BinaryTree class template.
// It builds a binary tree with 5 nodes.
#include <iostream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

// Create a binary search tree for manual exploration
IntBinaryTree myTree;

// Create a binary search tree for 
//        the automatic efficiency/height testing purpose
IntBinaryTree myTestingTree;


//The amount of random testing data for the data structures
int testScale_n=40000;


void doChooseEmptyContainerOption()
{
	myTree.clear();
}

void doDisplayDataOption()
{
	cout << myTree.size() << " nodes in the myTree" << endl;
	cout << "************************************************" << endl;
	cout << " List of values: by the PreOrder traversal:" << endl;
	myTree.displayPreOrder();
	cout << "************************************************" << endl;
	cout << " List of values: by the InOrder traversal:" << endl;
	myTree.displayInOrder();
	cout << "************************************************" << endl;

}

void doInsertDataOption()
{
	int data;
	cout << "Enter the data (integer) to insert:";
	cin >> data;
	myTree.insertNode(data);
}

void doDeleteDataOption()
{
	int data;
	cout << "Enter the data (integer) to delete:";
	cin >> data;
	myTree.remove(data);
}

void doSearchDataOption()
{
	int data;
	cout << "Enter the data (integer) to search for:";
	cin >> data;
	if ( myTree.searchNode(data) )
		cout << "Yes. " << data << " found in the tree.";
	else
		cout << "No. " << data << " not found in the tree.";
}


void doInsertionTestOption()
{
	myTestingTree.clear();

	cout << "Start " << testScale_n << " insertions \n ..." << endl;
	for (int i = 0; i < testScale_n; i++)
	{
		int data;
		data = rand();
		//if (i%100 == 0)	cout << ".";
		myTestingTree.insertNode(data);
	}
	cout << myTestingTree.height() << endl;
	cout << "Finished" << endl;
}

void doDeletionTestOption()
{
	myTestingTree.clear();

	cout << "1. Start " << testScale_n << " random insertions \n ..." << endl;
	for (int i = 0; i < testScale_n; i++)
	{
		int data = rand();
		myTestingTree.insertNode(data);
	}
	cout << "1. Finished" << endl;

	cout << "2. Start " << testScale_n << " random deletions \n ..." << endl;
	for (int i = 0; i < testScale_n; i++)
	{
		int data = rand();
		myTestingTree.remove(data);
	}
	cout << "2. Finished" << endl;
}

void doSearchTestOption()
{
	myTestingTree.clear();

	cout << "1. Start " << testScale_n << " random insertions \n ..." << endl;
	for (int i = 0; i < testScale_n; i++)
	{
		int data = rand();
		myTestingTree.insertNode(data);
	}
	cout << "1. Finished" << endl;

	cout << "2. Start " << testScale_n << " random searches \n ..." << endl;
	for (int i = 0; i < testScale_n; i++)
	{
		int data = rand();
		myTestingTree.searchNode(data);
	}
	cout << "2. Finished" << endl;

}

void doAverageHeightTestOption()
{
	//Replace the following with your own code
	cout << " Not implemented yet: IntBinaryTree::height( )" << endl;
	return;

} 

void displayMenu()
{
	cout << endl << endl;
	cout << "******************************************************************" << endl;
	cout << "**   Currently, a Binary Search Tree as the data container      **" << endl;
	cout << "******************************************************************" << endl;
	cout << "Choose a data container for experiments" << endl;
	cout << "C. [CHOOSE & EMPTY] a Binary Search Tree" << endl;
	cout << endl;
	cout << "Basic Operations:" << endl;
	cout << "D. [DISPLAY]        Display the data in the container" << endl;
	cout << "I. [INSERT]         Insert a new number into the container" << endl;
	cout << "R. [REMOVE/DELETE]  Delete a number from the container" << endl;
	cout << "S. [SEARCH]         Search for a number in the container " << endl;
	cout << "H. [HEIGHT]         Show the height of the tree " << endl;
	cout << endl;
	cout << "Efficiency Tests:          Current Testing Scale testScale_n=" << testScale_n << endl;
	cout << "N. [Set Testing Scale]     Select testScale_n, the amount of random data for testing" << endl;
	cout << "T. [Insertion Efficiency]  Insert (random data) for testScale_n=" << testScale_n << " times" << endl;
	cout << "U. [Deletion Efficiency]   Delete (random data) for testScale_n=" << testScale_n << " times" << endl;
	cout << "V. [Search Efficiency]     Search (random data) for testScale_n=" << testScale_n << " times" << endl;
	cout << endl;
	cout << "W. [Experiments on tree heights]  Check the average of tree heights" << endl;
	cout << endl;
	cout << "Q. [QUIT]    Quit." << endl;
	cout << endl;

	cout << "****************************************************" << endl << endl;
}

int main()
{	// inMenuServiceMode is true when the program iteratively provides the menu and serves.
	// inMenuServiceMode is set to false to end the loop ends when the user wants to quit.
	bool inMenuServiceMode = true;

	// This variabke stores the menu option selected by the user.
	char keyPressed;	

	while (inMenuServiceMode)
	{	displayMenu();
		cout << "Your choice is: ";
		cin >> keyPressed;

		switch (keyPressed) {

		case 'C': case 'c':// Display the data
			cout << "[CHOOSE & EMPTY the container]:" << endl;
			doChooseEmptyContainerOption();

		break;

		case 'D': case 'd':// Display the data
			cout << "[DISPLAY the data]:" << endl;
			doDisplayDataOption();

			break;

		case 'I': case 'i':// Insert a data point (allowing redundancy)
			cout << "[INSERT a data point]:" << endl;
			doInsertDataOption();

			cout << ">>The data point is stored in the container now." << endl;

			break;

		case 'R': case 'r':// Delete a data point
			cout << "[Remove a data point from the container]:" << endl;
			doDeleteDataOption();
			cout << ">>A data point (if existed) has been removed." << endl;

			break;

		case 'S': case 's':// Search for a data point
			cout << "[Search for a data point in the container]:" << endl;
			doSearchDataOption();
			cout << ">>A data point (if existed) has been removed." << endl;

			break;

		case 'H': case 'h':// Show the height of myTree
			cout << "[Show the height of myTree]: " << endl;
			cout << myTree.height() << endl;

			break;
		case 'N': case 'n':// Set the testing size
			cout << "[Set testScale_n, the amount of random data for testing]:" << endl;
			do
			{
				cout << "Please enter the value for testScale_n:";
				cin >> testScale_n;

			} while (testScale_n<1);

			break;

		case 'T': case 't':// Insertion test
			cout << "[Efficiency Test: Insert testScale_n random data points]:" << endl;
			doInsertionTestOption();
			break;

		case 'U': case 'u':// Deletion test
			cout << "[Efficiency Test: Delete testScale_n random data points]:" << endl;
			doDeletionTestOption();
			break;

		case 'V': case 'v':// Search test
			cout << "[Efficiency Test: Search for testScale_n random data points]:" << endl;
			doSearchTestOption();
			break;

		case 'W': case 'w':// Average height test
			cout << "[Average tree height test]:" << endl;
			doAverageHeightTestOption();
		break;

		case 'Q': case 'q'://Quit
			cout << "[QUIT]:" << endl;
			inMenuServiceMode = false;
			break;

		default:
			cout << "[?? UNKNOWN COMMAND]:" << endl;
			// Unrecognized key, do nothing
			break;
		}

	} // End of while loop.


	//Finished
	return 1;
}
