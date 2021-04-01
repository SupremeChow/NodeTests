/**
@author: Phillip Chow
@date: 3/24/2021

This is a Functor Class, which a tree will use to implement with pre/in/post order traversal
This is where functionality can be added for each use of order traversal in a tree. For now, the main action is
'Delete' for post order.

*/




#pragma once

#include "TreeNode.h"
#include <iostream> //Used for PRINT function
#include <string> //Used for print function

template<class Type>
class TraverseFunctor
{

public:

    //Member variables that can be used in conjunctions with traversal actions
    Type typeTrack; //This is a public memeber that can be used to hold type value dependent on how traverseStruct is used. For example, it can be used to track sum, or perhaps max/min
    int intTrack; //Similar to typeTrack, but used for int tracking. I.e. tracking height, number of iterations, etc


    //Possibly useful, but can use an int that is assigned at construction to define behavior for overloaded ()operator. Use enum for naming convention 
    //TODO finalize enum naming, only sure method is DELETE, which is used in post-traversal
    enum { FOO, PRINT, DELETE }traverseBehavior;

    void operator(TreeNode<Type>* targetNode, int newBehavior) {


        //TODO define functor action here, possibly using switch of traverseBehavior
        traverseBehavior = newBehaviour;

        switch (traverseBehavior)
        {
        case FOO:
            break;
        case PRINT:


            //TODO print behavior, for now just print to console. In an ideal program, provide options to print to (ie console, file, etc...)
            std::cout << targetNode->getData() << " ";

            break;
        case DELETE:

            if (targetNODE != NULL)
                delete targetNode;

            //Any other action placed here

            break;
        }


    }
};

