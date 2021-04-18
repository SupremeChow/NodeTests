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

 TODO !!!! Possibly make this an abstract class, and fully implement in child class of either AVL (Typical Binary tree learned), or Red-Black
*/




#pragma once

#include "TreeNode.h"

#include <functional> //For passing functions to tree traversal functions

#include "TraverseFunctor.h" //Functor is now in seperate class, so that other classes can access

using namespace std;



template<class Type>
class BinaryTree
{
private: 
    TreeNode<Type>* root;

    int size;
    //int currentHeight; //TODO may be redundant, but may use to track if unbalance. Height should be no more than ln(size), if not then there is an unbalance.

    //TODO for now, make inorder, postorder, and preorder part of private. Need to determine if needed to be public

    //TODO figure out how to implement functors or function pointers to take in as parameters
    

    //Use functionals for simplicity
    //void inOrder(function<void(*TreeNode)> funct);
    //void postOrder(function<void(*TreeNode)> funct);
    //void preOrder(function<void(*TreeNode)> funct);



    //Use functors to have an object with state that can be used to handle extra data (ie a Type that can sum)
 //   void inOrder(TreeNode<Type>* targetNode, TraverseFunctor<Type> *travFunct);
 //   void postOrder(TreeNode<Type>* targetNode, TraverseFunctor<Type>*travFunct);
 //  void preOrder(TreeNode<Type>* targetNode, TraverseFunctor<Type>*travFunct);
    void inOrder(TreeNode<Type>* targetNode, int newBehavior) {
        //empty pointer case
        if (targetNode == nullptr)
            return;

        if (targetNode->getLeftNode() != nullptr)
            inOrder(targetNode->getLeftNode(), newBehavior);



        //TODO maybe place error catching that prevents DELETE, since it can cause memory leaks

        TraverseFunctor<Type>()(targetNode, newBehavior);

        if (targetNode->getRightNode() != nullptr)
            inOrder(targetNode->getRightNode(), newBehavior);
    };
    void postOrder(TreeNode<Type>* targetNode, int newBehavior) {
        //empty pointer case
        if (targetNode == nullptr)
            return;

        if (targetNode->getLeftNode() != nullptr)
            postOrder(targetNode->getLeftNode(), newBehavior);

        if (targetNode->getRightNode() != nullptr)
            postOrder(targetNode->getRightNode(), newBehavior);

        TraverseFunctor<Type>()(targetNode, newBehavior);

    };
    void preOrder(TreeNode<Type>* targetNode, int newBehavior) {
        //empty pointer case
        if (targetNode == nullptr)
            return;



        //TODO maybe place error catching that prevents DELETE, since it can cause memory leaks

        TraverseFunctor<Type>()(targetNode, newBehavior);

        if (targetNode->getLeftNode() != nullptr)
            pretOrder(targetNode->getLeftNode(), newBehavior);

        if (targetNode->rightNode != nullptr)
            preOrder(targetNode->getRightNode(), newBehavior);


    };




    //TODO relearn rebalance. If making BinaryTree a abstract parent class, implement in extended classes for AVL and red-Black. For now, focus on AVL

    // 3/24/2021: Doubling back, Binary Tree will be a accesible class, But will not rebalance. It will be general use, and any updated tree feature (like rebalance) will be implemented in child classes
    //virtual void rebalance(TreeNode<Type>* rebalanceNode) = 0;

public:
    BinaryTree() {
        root = nullptr;
        size = 0;
        //currentHeight = 0;
    };
    BinaryTree(TreeNode<Type>* newRoot) {
        root = newRoot;
        size = 1;

    };

    //TODO Hold off, copy constructor
    //BinaryTree(const BinaryTree& otherBinaryTree);

    ~BinaryTree() {
        postOrder(root, TraverseFunctor<Type>::DELETE);
    }; //Use PostOrder() to clean nodes from bottom up


    //Virtual inserts() allows for basic implementation, while providing option of child classes to do their own thing


    //Main insert functions, implicitly start insert at root for simplicity and ease of use for outside calls. Calls generic inserts to handle
    virtual int insert(TreeNode<Type>* newNode) {
        return insert(newNode, root);
    }; //When given a constructed Node
    virtual int insert(Type newType) {
        return insert(newType, root);
    }; //When only given data, not node


    //Generic Insert functions, where the insert point is defined (used for recursion, or in rare instance user defines where to start insert process)
    virtual int insert(TreeNode<Type>* newNode, TreeNode<Type>*& currentNode) {
        //Recursively find place


        if (currentNode == nullptr)
        {
            currentNode = newNode;
            size++;
            return 0;
        }
        else
        {
            Type newNodeValue = newNode->getData();
            TreeNode<Type>* nextNode;
            
            if (newNodeValue <= currentNode->getData())
                nextNode = currentNode->getLeftNode();
            else
                nextNode = currentNode->getRightNode();

            int returnValue = insert(newNode, nextNode);

            //Ensure that child points back to parent
            if (nextNode->getParentNode() == nullptr)
            {
                nextNode->setParentNode(currentNode);
            }
            return returnValue;
        }
        //DON'T Rebalance, only child classes
    }; //When given a constructed Node
    virtual int insert(Type newType, TreeNode<Type>*& currentNode) {

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
            TreeNode<Type>* nextNode;
            if (newType <= currentNode->getData())
                nextNode = currentNode->getLeftNode();

            else
                nextNode = currentNode->getRightNode();

            int returnValue = insert(newType, nextNode);
            
            //Ensure that child points back to parent
            if (nextNode->getParentNode() == nullptr)
            {
                nextNode->setParentNode(currentNode);
            }
            return returnValue;
        }

        //DON'T Rebalance, only child classes
    }; //When only given data, not node

    
    
    
    
    
    TreeNode<Type>* find(Type data) {
        return find(data, root);
    }; //Search by given data, default at root
    TreeNode<Type>* find(Type data, TreeNode<Type>* currentNode) {
        if (currentNode == nullptr)
            return currentNode;

        if (currentNode->getData() == data)
            return currentNode;
        else if (currentNode->getData() < data)
            find(data, currentNode->getLeftNode());
        else
            find(data, currentNode->getRightNode());

    }; //Search by given data




    //TreeNode<Type>* find(Type data); //Search by given TreeNode pointer, default at root (TODO hold off until figure out if using Root reprasentative)
    //TreeNode<Type>* find(Type data, TreeNode<Type>* currentNode); //Search by given TreeNode pointer (TODO hold off until figure out if using Root reprasentative)
   






    bool deleteNode(Type data) {
        return deleteNode(data, root);
    }; //find by data and delete, default at root
    bool deleteNode(Type data, TreeNode<Type>* currentNode) {
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
                searchedNode->getLeftNode()->setParentNode(searchedNode->getParentNode());

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

    }; //find by data and delete






    TreeNode<Type>* getRoot()
    {
        return root;
    };



    //TODO Hold off on this, may use system where nodes of trees all have reference to a reprasentative Root. That way, if searched for node has that rep, we know it is in tree

    /*
    bool deleteNode(TreeNode<Type> targetNode);//find by givenNode and delete, default at root
    bool deleteNode(TreeNode<Type> targetNode, TreeNode<Type>* currentNode);//find by data and delete
    */

    //bool deleteNode(TreeNode<Type> targetNode); //TODO maybe be incorrect, but perhaps implement a delete that deletes a node from a given pointer.
    //In This case, may need to implement a representative node pointer(pointer) in TreeNode.
    //The representative would be the root, and all nodes will have a pointer to this node, thus ensuring that nodes know they belong to a ceratin tree
    //Therefore, to verify, need to check if targetNode's representive node pointer(pointer) equates to the BinaryTree root. If so its part of the tree
    //else, it isnt and can break out. Could implement this for search as well. Would need to figure ways to handle when root needs to be removed and changed.


    

    void printInOrder() {
        inOrder(root, TraverseFunctor<Type>::PRINT);
    };
    void printPreOrder() {
        preOrder(root, TraverseFunctor<Type>::PRINT);
    };
    
    
    int getSize() {
        return size;
    };


    //Utilities
    TreeNode<Type>* findRightMostChild() {
        if (root == nullptr)
            return nullptr;
        else
            return findRightMostChild(root);
    };//Called from root



    TreeNode<Type>* findRightMostChild(TreeNode<Type>* currentNode) {
        //TODO repetitive of root condition, however there is a chance given null Node. Setup try throw to ensure that the issue doesn't persist
        if (currentNode == nullptr)
            return nullptr;
        else
        {
            if (currentNode->getRightNode != nullptr)
                findRightMostChild(currentNode->getRightNode);
            else
                return currentNode;
        }
    };//Called custom node
    TreeNode<Type>* findLeftMostChild() {
        if (root == nullptr)
            return nullptr;
        else
            return findLeftMostChild(root);
    };//Called from root
    TreeNode<Type>* findLeftMostChild(TreeNode<Type>* currentNode) {
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
    };//Called custom node

};

