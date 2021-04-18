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

	cout << "\n \n Printing in Order \n";


	//Print in-order to check if correct ordering
	//TODO perhaps add function in BinaryTree that returns traversal ordering as  vector for analysis. For now just print
		
	testTree->printInOrder();
	//TODO instead take a vector of output, analyze, and evaluate

	cout << "\n Now deleting... \n";
	//DELETE Tree
	delete testTree;


	cout << "\n Test finished, going back to main...\n";

	return 0;


}

