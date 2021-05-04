/**
@author Phillip Chow

AVLNode.h


	AVLNode is an extension of the TreeNode class, to be implemented in AVL Tree Structure
	This Node will add the new fields and functionalities that track and update based on children height so that
	the AVLTree can properly balance itself

	
*/



#pragma once


#include "TreeNode.h"


template<class Type>
class AVLNode : public TreeNode<Type>
{
private:
	int maxHeight;

public:

};