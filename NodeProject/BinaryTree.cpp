/**
@author Phillip Chow

BinaryTree.h

This is the cpp file for the Binary Tree data structure. Typically, Trees can be made simply with nodes,
using the head node as the root, storing children pointers, and calling static functions that will do tree behaviour.
However, this class will act as a container class, which will handle all the logic of the tree. Mainly, it will
track a root node, manage ordering, track height, and provide methods of Pre-order, post-order, and in order
 that can take function pointers to do whatever is necessary (e.g. deletion).

 TODO Because nodes use template data, will need to make this class template as well, to avoid
 type mismatch and issues with pointer sizes.

 TODO Need to re-learn rebalancing of trees, when they occur and how to do it. Will probably setupd member data for easier tracking
 of these conditions

 TODO !!!! Possibly make this an abstract class, and fully implement in child class of either AVL (Typical Binary tree learned), or Red-Black
*/

#include "BinaryTree.h"
#include "TraverseFunctor.h"



/*Traversal Functions

Requires the use of functor class TraverseFunctor to determine the actions taking place while traversing the tree
*/


/*
template<class Type>
void BinaryTree<Type>::inOrder(TreeNode<Type>* targetNode, TraverseFunctor<Type>* travFunct)
{
    //empty pointer case
    if (targetNode == nullptr) 
        return;

    if (targetNode->leftNode != nullptr)
        inOrder(targetNode->leftNode, travFunct);

        travFunct(targetNode);

    if (targetNode->rightNode != nullptr)
        inOrder(targetNode->rightNode, travFunct);
}

template<class Type>
void BinaryTree<Type>::postOrder(TreeNode<Type>* targetNode, TraverseFunctor<Type>* travFunct)
{
    //empty pointer case
    if (targetNode == nullptr)
        return;

    if (targetNode->leftNode != nullptr)
        postOrder(targetNode->leftNode, travFunct);
    
    if(targetNode->rightNode != nullptr)
        postOrder(targetNode->rightNode, travFunct);

    travFunct(targetNode);

}

template<class Type>
void BinaryTree<Type>::preOrder(TreeNode<Type>* targetNode, TraverseFunctor<Type>* travFunct)
{
    //empty pointer case
    if (targetNode == nullptr)
        return;

    travFunct(targetNode);

    if (targetNode->leftNode != nullptr)
        pretOrder(targetNode->leftNode, travFunct);

    if (targetNode->rightNode != nullptr)
        preOrder(targetNode->rightNode, travFunct);

    
}
*/




template<class Type>
void BinaryTree<Type>::inOrder(TreeNode<Type>* targetNode, int newBehavior)
{
    //empty pointer case
    if (targetNode == nullptr)
        return;

    if (targetNode->leftNode != nullptr)
        inOrder(targetNode->leftNode, newBehavior);



    //TODO maybe place error catching that prevents DELETE, since it can cause memory leaks

    travFunct(targetNode, newBehavior);

    if (targetNode->rightNode != nullptr)
        inOrder(targetNode->rightNode, newBehavior);
}

template<class Type>
void BinaryTree<Type>::postOrder(TreeNode<Type>* targetNode, int newBehavior)
{
    //empty pointer case
    if (targetNode == nullptr)
        return;

    if (targetNode->leftNode != nullptr)
        postOrder(targetNode->leftNode, newBehavior);

    if (targetNode->rightNode != nullptr)
        postOrder(targetNode->rightNode, newBehavior);

    travFunct(targetNode, newBehavior);

}

template<class Type>
void BinaryTree<Type>::preOrder(TreeNode<Type>* targetNode, int newBehavior)
{
    //empty pointer case
    if (targetNode == nullptr)
        return;



    //TODO maybe place error catching that prevents DELETE, since it can cause memory leaks

    travFunct(targetNode, newBehavior);

    if (targetNode->leftNode != nullptr)
        pretOrder(targetNode->leftNode, newBehavior);

    if (targetNode->rightNode != nullptr)
        preOrder(targetNode->rightNode, newBehavior);


}





template<class Type>
BinaryTree<Type>::BinaryTree() 
{
    root = nullptr;
    size = 0;
    //currentHeight = 0;
}

template<class Type>
BinaryTree<Type>::BinaryTree(TreeNode<Type>* newRoot) 
{
    root = newRoot;
    size = 1;

}


//Use PostOrder() to clean nodes from bottom up
template<class Type>
BinaryTree<Type>::~BinaryTree() 
{
    postOrder(root, TraverseFunctor::DELETE);
} 





//********** Insert functions


//**** Insert at root
template<class Type>
int BinaryTree<Type>::insert(TreeNode<Type>* newNode)
{
    return insert(newNode, root);
}

template<class Type>
int BinaryTree<Type>::insert(Type newType)
{
    return insert(newType, root);
}


//**** Insert at given node
template<class Type>
int BinaryTree<Type>::insert(TreeNode<Type>* newNode, TreeNode<Type>* currentNode)
{
    //Recursively find place
    

    if (currentNode == nullptr)
    {
        currentNode = newNode;
        size++;
        return 0;
    }
    else
    {
        if (newNode->getData <= currentNode->getData)
            return insert(newNode, currentNode->getLeftNode);
        else
            return insert(newNode, currentNode->getRightNode);
    }

    //DON'T Rebalance, only child classes
}

template<class Type>
int BinaryTree<Type>::insert(Type newType, TreeNode<Type>* currentNode)
{

    //Recursively find place


    if (currentNode == nullptr)
    {
        TreeNode<Type>* newNode = new TreeNode<Type>(newType);
        currentNode = newNode;
        size++;
        return 0;
    }
    else
    {
        if (newType <= currentNode->getData)
            return insert(newType, currentNode->getLeftNode);
        else
            return insert(newType, currentNode->getRightNode);
    }

    //DON'T Rebalance, only child classes
}




//********* Find() functions


template<class Type>
TreeNode<Type>* BinaryTree<Type>::find(Type data)
{
    return find(data, root);
}



template<class Type>
TreeNode<Type>* BinaryTree<Type>::find(Type data, TreeNode<Type>* currentNode)
{
    if (currentNode == nullptr)
        return currentNode;

    if (currentNode->getData() == data)
        return currentNode;
    else if (currentNode->getData() < data)
        find(data, currentNode->getLeftNode());
    else
        find(data, currentNode->getRightNode());

}



//********* delete() functions



template<class Type>
bool BinaryTree<Type>::deleteNode(Type data)
{
    return deleteNode(data, root);
}

template<class Type>
bool BinaryTree<Type>::deleteNode(Type data, TreeNode<Type>* currentNode)
{
    TreeNode<Type>* searchedNode = find(data, currentNode);
    if (searchedNode == nullptr)
        return false; //Didn't find node, no deletion
    else
    {
        //First, if only the node had only one child branch, move it up...
        if (searchedNode->getLeftNode() != nullptr && searchedNode->getRightNode() == nullptr)
        {
            if (searchedNode == root) //if this is the root...
                root = searchedNode->getLeftNode();
            searchedNode->getLeftNode()->setParentNode(searchedNode->getParentNode()) ;

        }
        else if (searchedNode->getLeftNode() == nullptr && searchedNode->getRightNode() != nullptr)
        {
            if (searchedNode == root) //if this is the root...
                root = searchedNode->getRightNode();
            searchedNode->getRightNode()->setParentNode(searchedNode->getParentNode);
            

        }
        //...Or, if there are no children
        else if (searchedNode->getLeftNode() == nullptr && searchedNode->getRightNode() == nullptr)
        {
            if (searchedNode == root) //if this is the root...
                root = nullptr;
        }


        //...else, we will try and replace with leftChild's right-most leaf and make right sibling it's right child...
        else
        {
            //Recursive call to find right most grandchild of left child
            TreeNode<Type>* replacementNode = findRightMostChild(searchedNode->getLeftNode());

            if (replacementNode == searchedNode->getLeftNode()) //if just left child of node to be deleted...
            {
                replacementNode->setParentNode(searchedNode->getParentNode());

                replacementNode->setRightNode(searchedNode->getRightNode());

                searchedNode->getRightNode()->setParentNode(replacementNode);
            }
            else
            {
                replacementNode->getParentNode()->setRightNode(nullptr);

                replacementNode->setLeftNode(searchedNode->getLeftNode());
                searchedNode->getLeftNode()->setParentNode(replacementNode);
                

                replacementNode->setRightNode(searchedNode->getRightNode());
                searchedNode->getRightNode()->setParentNode(replacementNode);


                replacementNode->setParentNode(searchedNode->getParentNode());
                
                
            }

            if (searchedNode == root)
                root = replacementNode;
        }



        delete searchedNode;
        size--;
        return true;
    }
    
}



/* TODO Hold off until figure out representative Root system for determining if within tree



//template<class Type>
//bool deleteNode(TreeNode<Type> targetNode); //TODO maybe be incorrect, but perhaps implement a delete that deletes a node from a given pointer.
//In This case, may need to implement a representative node pointer(pointer) in TreeNode.
//The representative would be the root, and all nodes will have a pointer to this node, thus ensuring that nodes know they belong to a ceratin tree
//Therefore, to verify, need to check if targetNode's representive node pointer(pointer) equates to the BinaryTree root. If so its part of the tree
//else, it isnt and can break out. Could implement this for search as well. Would need to figure ways to handle when root needs to be removed and changed.


template<class Type>
bool BinaryTree<Type>::deleteNode(TreeNode<Type> targetNode)
{
    return false;
}

template<class Type>
bool BinaryTree<Type>::deleteNode(TreeNode<Type> targetNode, TreeNode<Type>* currentNode)
{
    return false;
}

*/






template<class Type>
void BinaryTree<Type>::printInOrder()
{
    inOrder(root, TraverseFunctor::PRINT);
}

template<class Type>
void BinaryTree<Type>::printPreOrder()
{
    preOrder(root, TraverseFunctor::PRINT);
}

template<class Type>
int BinaryTree<Type>::getSize()
{
    return size;
}




//****** Utilities


//Function call for finding the right most child from root of tree (aka the max value)
template<class Type>
TreeNode<Type>* BinaryTree<Type>::findRightMostChild()
{
    if (root == nullptr)
        return nullptr;
    else
        return findRightMostChild(root);
}

//Function call for finding the left most child selected node (aka the local max value)
template<class Type>
TreeNode<Type>* BinaryTree<Type>::findRightMostChild(TreeNode<Type>* currentNode)
{
    //TODO repetitive of root condition, however there is a chance given null Node. Setup try throw to ensure that the issue doesn't persist
    if(currentNode == nullptr)
        return nullptr;
    else
    {
        if (currentNode->getRightNode != nullptr)
            findRightMostChild(currentNode->getRightNode);
        else
            return currentNode;
    }
}

//Function call for finding the left most child from root of tree (aka the min value)
template<class Type>
TreeNode<Type>* BinaryTree<Type>::findLeftMostChild()
{
    if (root == nullptr)
        return nullptr;
    else
        return findLeftMostChild(root);
}

//Function call for finding the left most child selected node (aka the local min value)
template<class Type>
TreeNode<Type>* BinaryTree<Type>::findLeftMostChild(TreeNode<Type>* currentNode)
{
    //TODO repetitive of root condition, however there is a chance given null Node. Setup try throw to ensure that the issue doesn't persist
    if (currentNode == nullptr)
        return nullptr;
    else
    {
        if (currentNode->getLeftNode != nullptr)
            findRightMostChild(currentNode->getLeftNode);
        else
            return currentNode;
    }
}
