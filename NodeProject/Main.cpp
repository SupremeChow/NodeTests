/**
@author Phillip Chow

	This project is simply a utilization of a node class, and implementing in various forms for demonstrating algorithms and data structures

	Main.cpp is the main class for starting and running
*/

#include "BinaryTree.h"
#include "BinaryTreeTest.h"

#include "Tries.h"
#include "TriesNode.h"


#include <stdio.h>   
#include <string>

using namespace std;

//int numArgs, char* argList
int main()
{


	//Tries Data Structures test

	Tries* testTries = new Tries();

	testTries->insertWord("A");
	testTries->insertWord("Alphalpha");
	testTries->insertWord("Alphalphe");
	testTries->insertWord("Temple");

	if (testTries->isWord("A"))
		cout << "A is a word \n";
	else
		cout << "ERROR, A is deemeed not a word \n";

	if (!testTries->isWord("B"))
		cout << "B is NOT word \n";
	else
		cout << "ERROR, B is deemeed a word \n";


	TriesNode* aTriesNode = testTries->findWord("ShouldBeNull \n");

	if (aTriesNode == nullptr)
		cout << "Find Word returned a nullptr, as expected \n";
	else
		cout << "ERROR, returned a ptr to a word that doesn't exist \n";


	aTriesNode = testTries->findWord("Alphalpha");

	if (aTriesNode != nullptr)
	{
		cout << "Word Alphalpha found, testing to see if last char is correct...";
		if (aTriesNode->getCurrentChar() == 'a')
			cout << "current character is correct, it's " << aTriesNode->getCurrentChar() << "\n";
		else
			cout << "ERROR !!! current character is incorrect, it's " << aTriesNode->getCurrentChar() << "\n";
	}
		
	else
		cout << "ERROR, returned a ptr to a word that doesn't exist  \n";



	bool wasDeleted = testTries->deleteWord("Wrong");

	if (!wasDeleted)
		cout << "Word \'Wrong\' was not in Tries, and was not deleted \n";
	else
		cout << "ERORR!!! Word \'Wrong\' was not in Tries, and returned True on deletion \n";

	wasDeleted = testTries->deleteWord("Alphalphe");
	if (wasDeleted)
		cout << "Word \'Alphalphe\' was in Tries, and was deleted \n";
	else
		cout << "ERORR!!! Word \'Alphalphe\' was in Tries, and returned False on deletion \n";


	//Double check on find

	if (!testTries->isWord("Alphalphe"))
		cout << "Alphalphe really was deleted \n";
	else
		cout << "ERROR, Alplhalphe still appears in Tries \n";


	//Double check A Tree properly maintained

	if (testTries->isWord("Alphalpha"))
		cout << "Alphalpha maintained \n";
	else
		cout << "ERROR, Alplhalpha is now having issues for some reason \n";


	//BinaryTreeTest::mainTest(5, 100);




	/*
	BinaryTree<int>* testTree = new BinaryTree<int>();
	TreeNode<int>* targetNode;


	testTree->insert(10);

	targetNode = testTree->getRoot();

	
	cout << targetNode->getData() << "\n";

	testTree->insert(5);
	testTree->printInOrder();
	*/










	return 0;
}