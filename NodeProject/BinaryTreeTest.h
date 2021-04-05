/**

@author Phillip Chow

BinaryTreeTest.h

Simple test file for checking if BinaryTree data structure works. Primarily creates multiple random integer object nodes that will be inserted/deleted and testing various features of
BinaryTree. Not concerned with efficiency since tests will include both standard BinaryTree and AVL tree. Will primarily test for correct ordering, ensuring output is correct.

*/



#pragma once
#include "BinaryTree.h"
#include "TreeNode.h" //May be redundant

#include <stdio.h>   

//Don't use in c++11 standards, use <random> isntead
//#include <cstdlib>     
//#include <ctime> 

#include <random>

#define RANDOM_SEED 16 //Use to seed Mt19937 (Not sure if value of seed is important)


using namespace std;



class BinaryTreeTest
{

	//Generating random number using <random> library. 
	//From my un-educated perspective, will use mt19937 to seed random number. This is for because mt19937 is determenistic, meaning if given same seed, should expect same random set.
	//This is ideal if needed to reproduce tests to get same results. In reality, this project is simple and isn't trying to be academic in terms of testing efficiency and reproducability.
	//However, it is nice to have if needed to do academic comparisons. The alternative is seed mt19937 with random_device "mt(rd())" to get non-determenistic, which is truly random, but not repeatable



public:
	//Test function 
	static int mainTest(int numNodes, int nodeValueRange);


};