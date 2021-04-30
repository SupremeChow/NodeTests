/**

@author Phillip Chow

BinaryTreeTest.cpp

Simple test file for checking if BinaryTree data structure works. Primarily creates multiple random integer object nodes that will be inserted/deleted and testing various features of
BinaryTree. Not concerned with efficiency since tests will include both standard BinaryTree and AVL tree. Will primarily test for correct ordering, ensuring output is correct.

*/

#include "BinaryTreeTest.h"

   
using namespace std;

int BinaryTreeTest::mainTest(int numNodes, int nodeValueRange)
{
	cout << "Starting test... \n";


	mt19937_64 mt(RANDOM_SEED); //Use a constant Seed to create numbers
	uniform_int_distribution<int> distribution(0, nodeValueRange); //Distribution of [0, nodeValueRange]

	//********* Teting Tree creation and insertion
	BinaryTree<int>* testTree = new BinaryTree<int>();
	int functionReturns;
	cout << "Printing numbers: ";
	for (int i = 0; i < numNodes; i++)
	{
		int randomNumber = distribution(mt);

		cout << randomNumber << " ";
		functionReturns = testTree->insert(randomNumber);
		if (functionReturns != 0) //TODO maybe setup error code constants in BinaryTree
		{
			cout << "\n \n ********* Error!!!!! ******* \n Inserting into Tree with value (" << randomNumber << ") resulted in error after (" << i << ") entries. Aborting....\n";
			return 1;
		}
	}


	testTree->insert(69); //For delte test later


	cout << "\n \n Printing in Order \n";





	//*********Print in-order to check if correct ordering
	//TODO perhaps add function in BinaryTree that returns traversal ordering as  vector for analysis. For now just print
		
	testTree->printInOrder();
	//TODO instead take a vector of output, analyze, and evaluate



	//*********Print in-order to check if correct ordering
	cout << "\n \n printing pre-order \n";
	testTree->printPreOrder();



	
	//**********Testing delete() function

	//Delete of non-existant number
	cout << "\n \n testing delete of non-available number \n"; //Becuase we did determenistic random numbers, we know what numbers will and will not show in test
	
	bool deleteTest = testTree->deleteNode(100);
	cout << "Delete of non-existant number: ";
	if (!deleteTest)
		cout << "(PASS), returned false for not finding/deleting unavailable node";
	else
		cout << "(FAILED), Returned a true value for deletion";

	cout << "\n";
	testTree->printInOrder();


	//Delete of existing number
	

	cout << "\n \n testing delete of available number \n"; 
	deleteTest = testTree->deleteNode(69);
	cout << "Delete of non-existant number: ";
	
	if (deleteTest)
		cout << "(PASS), returned true for not finding/deleting available node";
	else
		cout << "(FAILED), Returned a flase value for deletion";
	
	cout << "\n";
	testTree->printInOrder();



	//********* Deleting Tree

	cout << "\n Now deleting... \n";
	//DELETE Tree
	delete testTree;


	cout << "\n Test finished, going back to main...\n";

	return 0;


}

