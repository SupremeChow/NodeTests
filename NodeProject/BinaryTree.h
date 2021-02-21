/**
@author Phillip Chow

BinaryTree.h

This is the header file for the Binary Tree data structure. Typically, Trees can be made simply with nodes,
using the head node as the root, storing children pointers, and calling static functions that will do tree behaviour.
However, this class will act as a container class, which will handle all the logic of the tree. Mainly, it will
track a root node, manage ordering, track height, and provide methods of Pre-order, post-order, and in order
 that can take function pointers to do whatever is necessary (e.g. deletion). 

 TODO Because nodes use template data, will need to make this class template as well, to avoid
 type mismatch and issues with pointer sizes.

 TODO Need to re-learn rebalancing of trees, when they occur and how to do it. Will probably setupd member data for easier tracking
 of these conditions
*/




#pragma once

#include "TreeNode.h"

#include <functional> //For passing functions to tree traversal functions

using namespace std;



// Setting up a Functor struct in the event we don't want to use functional. Functor gives some flexibility in the tree traversal and what it can do
template<class Type>
struct TraverseFunctor
{


    Type typeTrack; //This is a public memeber that can be used to hold type value dependent on how traverseStruct is used. For example, it can be used to track sum, or perhaps max/min
    int intTrack; //Similar to typeTrack, but used for int tracking. I.e. tracking height, number of iterations, etc

    //Possibly useful, but can use an int that is assigned at construction to define behavior for overloaded ()operator. Use enum for naming convention 
    //TODO finalize enum naming, only sure method is DELETE, which is used in post-traversal
    enum {FOO, BAR, DELETE}traverseBehavior;

    void operator(TreeNode<Type>* targetNode) {
    
    
    //TODO define functor action here, possibly using switch of traverseBehavior

        switch (traverseBehavior) 
        {
            case FOO:
                break;
            case BAR:
                break;
            case DELETE:

                if (targetNODE != NULL)
                    delete targetNode;

                //Any other action placed here

                break;
        }


    }

};



template<class Type>
class BinaryTree
{
private: 
    TreeNode<Type>* root;

    int size;
    int currentHeight; //TODO may be redundant, but may use to track if unbalance. Height should be no more than ln(size), if not then there is an unbalance.

    //TODO for now, make inorder, postorder, and preorder part of private. Need to determine if needed to be public

    //TODO figure out how to implement functors or function pointers to take in as parameters
    

    //Use functionals for simplicity
    //void inOrder(function<void(*TreeNode)> funct);
    //void postOrder(function<void(*TreeNode)> funct);
    //void preOrder(function<void(*TreeNode)> funct);

    //Use functors to have an object with state that can be used to handle extra data (ie a Type that can sum)
    //void inOrder(TraverseFunctor *travFunct);
    //void postOrder(TraverseFunctor *travFunct);
    //void preOrder(TraverseFunctor *travFunct);

    //TODO relearn rebalance
    //void rebalance(TreeNode<Type>* pivot, TreeNode<Type>* leftPoint, TreeNode<Type>* rightPoint);

public:
    BinaryTree();
    BinaryTree(TreeNode<Type> newRoot);

    ~BinaryTree(); //Use PostOrder() to clean nodes from bottom up


    int insert(TreeNode<Type>* newRoot);
    TreeNode<Type>* find(Type data);

    bool deleteNode(Type data); //find by data and delete

    //bool deleteNode(TreeNode<Type> targetNode); //TODO maybe be incorrect, but perhaps implement a delete that deletes a node from a given pointer.
    //In This case, may need to implement a representative node pointer(pointer) in TreeNode.
    //The representative would be the root, and all nodes will have a pointer to this node, thus ensuring that nodes know they belong to a ceratin tree
    //Therefore, to verify, need to check if targetNode's representive node pointer(pointer) equates to the BinaryTree root. If so its part of the tree
    //else, it isnt and can break out. Could implement this for search as well. Would need to figure ways to handle when root needs to be removed and changed.


    int getSize();

};

