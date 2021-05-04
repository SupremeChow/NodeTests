/**
@author Phillip Chow

AVLTree.h

    Header File for AVLTree data structure, which extends BinaryTree structure. AVLTree has updated capability
    of self balancing after insert/delete, inorder to provide O(nLog(n)) functionality.



*/



#pragma once

#include "BinaryTree.h"
#include "AVLNode.h"


template<class Type>
class AVLTree : public BinaryTree<Type>
{
private:
    /************************************************************
                            Rebalance
    ************************************************************/

public:


    /************************************************************
                            Insert
    ************************************************************/
    //Overloaded Insert Functions that will add the functionality of rebalance


};