/**
@author: Phillip Chow
@date: 3/24/2021

This is a Functor Class, which a tree will use to implement with pre/in/post order traversal
This is where functionality can be added for each use of order traversal in a tree. For now, the main action is
'Delete' for post order.

*/



#include "TraverseFunctor.h"

/* 4/10/2021 TODO Temp hide and put definition in .h, to try and resolve link issues

template<class Type>
void TraverseFunctor<Type>::operator()(TreeNode<Type>* targetNode, int newBehavior) {


    //TODO define functor action here, possibly using switch of traverseBehavior
    traverseBehavior = newBehavior;

    switch (traverseBehavior)
    {
    case FOO:
        break;
    case PRINT:


        //TODO print behavior, for now just print to console. In an ideal program, provide options to print to (ie console, file, etc...)
        std::cout << targetNode->getData() << " ";

        break;
    case DELETE:

        if (targetNode != NULL)
            delete targetNode;

        //Any other action placed here

        break;
    }


}


*/