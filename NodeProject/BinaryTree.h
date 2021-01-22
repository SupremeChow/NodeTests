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

template<class Type>
class BinaryTree
{
private: 
    TreeNode<Type>* root;

    int size;
    int currentHeight; //TODO may be redundant, but may use to track if unbalance. Height should be no more than ln(size), if not then there is an unbalance.

    //TODO for now, make inorder, postorder, and preorder part of privat. Need to determine if needed to be public

    //TODO figure out how to implement functors or function pointers to take in as parameters
    
    //void inOrder();
    //void postOrder();
    //void preOrder();


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

