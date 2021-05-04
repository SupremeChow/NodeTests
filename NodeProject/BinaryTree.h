/**
@author Phillip Chow

BinaryTree.h

This is the header file for the Binary Tree data structure. Typically, Trees can be made simply with nodes,
using the head node as the root, storing children pointers, and calling static functions that will do tree behaviour.
However, this class will act as a container class, which will handle all the logic of the tree. Mainly, it will
track a root node, manage ordering, track height, and provide methods of Pre-order, post-order, and in order
 that can take function pointers to do whatever is necessary (e.g. deletion). 

 

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
    

    /************************************************************
       !!!!!!!!!!!!!!!!                     !!!!!!!!!!!!!!!!!!!
                            Un-used Misc.
       !!!!!!!!!!!!!!!!                     !!!!!!!!!!!!!!!!!!!
    ************************************************************/
    //Use functionals for simplicity
    //void inOrder(function<void(*TreeNode)> funct);
    //void postOrder(function<void(*TreeNode)> funct);
    //void preOrder(function<void(*TreeNode)> funct);



    //Use functors to have an object with state that can be used to handle extra data (ie a Type that can sum)
 //   void inOrder(TreeNode<Type>* targetNode, TraverseFunctor<Type> *travFunct);
 //   void postOrder(TreeNode<Type>* targetNode, TraverseFunctor<Type>*travFunct);
 //  void preOrder(TreeNode<Type>* targetNode, TraverseFunctor<Type>*travFunct);

    /************************************************************
                            Traversals
    ************************************************************/



    /* Inorder Traversal: Ideal for listing in increasing value */
    void inOrder(TreeNode<Type>* targetNode, int newBehavior) 
    {
        


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

    /*PostOrder Traversal: Ideal for delete*/
    void postOrder(TreeNode<Type>* targetNode, int newBehavior) 
    {
        //empty pointer case
        if (targetNode == nullptr)
            return;

        if (targetNode->getLeftNode() != nullptr)
            postOrder(targetNode->getLeftNode(), newBehavior);

        if (targetNode->getRightNode() != nullptr)
            postOrder(targetNode->getRightNode(), newBehavior);

        TraverseFunctor<Type>()(targetNode, newBehavior);

    };

    /*PreOrder Traversal: Ideal for copying tree node by node*/
    void preOrder(TreeNode<Type>* targetNode, int newBehavior)
    {
        //empty pointer case
        if (targetNode == nullptr)
            return;



        //TODO maybe place error catching that prevents DELETE, since it can cause memory leaks

        TraverseFunctor<Type>()(targetNode, newBehavior);

        if (targetNode->getLeftNode() != nullptr)
            preOrder(targetNode->getLeftNode(), newBehavior);

        if (targetNode->getRightNode() != nullptr)
            preOrder(targetNode->getRightNode(), newBehavior);


    };



public:
    /************************************************************
                     Constructor/Destructors
    ************************************************************/


    BinaryTree() 
    {
        root = nullptr;
        size = 0;
        //currentHeight = 0;
    };
    BinaryTree(TreeNode<Type>* newRoot) 
    {
        root = newRoot;
        size = 1;

    };


    //TODO Hold off, copy constructor
    //BinaryTree(const BinaryTree& otherBinaryTree);


    ~BinaryTree() 
    {
        postOrder(root, TraverseFunctor<Type>::DELETE);
    }; //Use PostOrder() to clean nodes from bottom up





    /************************************************************
                            Getters/Setters
    ************************************************************/


    TreeNode<Type>* getRoot()
    {
        return root;
    };


    int getSize()
    {
        return size;
    };

    /************************************************************
                            Insert
    ************************************************************/
    //Virtual inserts() allows for basic implementation, while providing option of child classes to do their own thing
   
    
    
    

     //*****   Main insert functions, implicitly start insert at root for simplicity and ease of use for outside calls. Calls generic inserts to handle


    //When given a constructed Node
    virtual int insert(TreeNode<Type>* newNode) 
    {
        return insert(newNode, root);
    }; 

    //When only given data, not node
    virtual int insert(Type newType) 
    {
        return insert(newType, root);
    }; 





    //******  Generic Insert functions, where the insert point is defined (used for recursion, or in rare instance user defines where to start insert process)


    //When given a constructed Node
    virtual int insert(TreeNode<Type>* newNode, TreeNode<Type>*& currentNode) 
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
            Type newNodeValue = newNode->getData();
            TreeNode<Type>* nextNode;
            
            if (newNodeValue <= currentNode->getData())
            {
                if (currentNode->getLeftNode() == nullptr) //At a null leaf, go ahead an create object
                {
                    currentNode->setLeftNode(newNode);
                    size++;
                    return 0;
                }
                nextNode = currentNode->getLeftNode();
            }
                
            else
            {
                if (currentNode->getRightNode() == nullptr) //At a null leaf, go ahead an create object
                {
                    currentNode->setRightNode(newNode);
                    size++;
                    return 0;
                }
                nextNode = currentNode->getRightNode();
            }
                



            int returnValue = insert(newNode, nextNode);



            //Ensure that child points back to parent
            if (nextNode->getParentNode() == nullptr)
            {
                nextNode->setParentNode(currentNode);
            }
            return returnValue;
        }
        //DON'T Rebalance, only child classes
    }; 



    //TODO 4/30/2021 Implement overloaded Constructor for a node to simplify creation of node and assigning it's pointer values

    //When only given data, not node
    virtual int insert(Type newType, TreeNode<Type>*& currentNode) 
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
            TreeNode<Type>* nextNode;
            if (newType <= currentNode->getData())
            {
                if (currentNode->getLeftNode() == nullptr) //At a null leaf, go ahead an create object
                {
                    TreeNode<Type>* newNode = new TreeNode<Type>(newType);
                    currentNode->setLeftNode(newNode);
                    size++;
                    return 0;
                }
                nextNode = currentNode->getLeftNode();
            }
                

            else
            {
                if (currentNode->getRightNode() == nullptr) //At a null leaf, go ahead an create object
                {
                    TreeNode<Type>* newNode = new TreeNode<Type>(newType);
                    currentNode->setRightNode(newNode);
                    size++;
                    return 0;
                }
                nextNode = currentNode->getRightNode();

            }
                

            int returnValue = insert(newType, nextNode);
            
            //Ensure that child points back to parent
            if (nextNode->getParentNode() == nullptr)
            {
                nextNode->setParentNode(currentNode);
            }
            return returnValue;
        }

        //DON'T Rebalance, only child classes
    }; 

    


    
    /************************************************************
                            Find
    ************************************************************/
    
    

    //Search by given data, starting at root by default
    TreeNode<Type>* find(Type data) 
    {
        return find(data, root);
    }; 

    //Search by given data, starting at given Node point
    TreeNode<Type>* find(Type data, TreeNode<Type>* currentNode) 
    {
        if (currentNode == nullptr)
            return currentNode;

        if (currentNode->getData() == data)
            return currentNode;
        else if (currentNode->getData() > data)
            find(data, currentNode->getLeftNode());
        else
            find(data, currentNode->getRightNode());

    }; 


   

/************************************************************
                      Delete Node
************************************************************/


//find by data and delete, start at root by default
    bool deleteNode(Type data) 
    {
        return deleteNode(data, root);
    }; 


    //find by data and delete
    bool deleteNode(Type data, TreeNode<Type>* currentNode) 
    {
        TreeNode<Type>* searchedNode = find(data, currentNode);
        if (searchedNode == nullptr)
            return false; //Didn't find node, no deletion
        else
        {
            //First, if only the node had only one child branch, move it up...
            if (searchedNode->getLeftNode() != nullptr && searchedNode->getRightNode() == nullptr)
            {
                
                searchedNode->getLeftNode()->setParentNode(searchedNode->getParentNode());

                if (searchedNode == root) //if this is the root...
                    root = searchedNode->getLeftNode();
                else
                {
                    if (searchedNode->getParentNode()->getData() >= searchedNode->getData())
                        searchedNode->getParentNode()->setLeftNode(searchedNode->getLeftNode());
                    else
                        searchedNode->getParentNode()->setRightNode(searchedNode->getLeftNode());
                }

            }
            else if (searchedNode->getLeftNode() == nullptr && searchedNode->getRightNode() != nullptr)
            {
               
                searchedNode->getRightNode()->setParentNode(searchedNode->getParentNode());

                if (searchedNode == root) //if this is the root...
                    root = searchedNode->getRightNode();
                else
                {
                    if (searchedNode->getParentNode()->getData() >= searchedNode->getData())
                        searchedNode->getParentNode()->setLeftNode(searchedNode->getRightNode());
                    else
                        searchedNode->getParentNode()->setRightNode(searchedNode->getRightNode());
                }

            }
            //...Or, if there are no children
            else if (searchedNode->getLeftNode() == nullptr && searchedNode->getRightNode() == nullptr)
            {
                if (searchedNode == root) //if this is the root...
                    root = nullptr;
                //otherwise, will need to make sure parent no longer points to this node
                if (searchedNode->getParentNode()->getData() >= searchedNode->getData())
                {
                    searchedNode->getParentNode()->setLeftNode(nullptr);
                }
                else
                {
                    searchedNode->getParentNode()->setRightNode(nullptr);
                }
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
                else
                {
                    if (searchedNode->getParentNode()->getData() >= searchedNode->getData())
                        searchedNode->getParentNode()->setLeftNode(replacementNode);
                    else
                        searchedNode->getParentNode()->setRightNode(replacementNode);
                }
            }



            delete searchedNode;
            size--;
            return true;
        }

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


    


    /************************************************************
                            Tree Utilities
    ************************************************************/


    //******* Tree Print Functions ***********

    void printInOrder() 
    {
        inOrder(root, TraverseFunctor<Type>::PRINT);
    };
    void printPreOrder() 
    {
        preOrder(root, TraverseFunctor<Type>::PRINT);
    };
    
    




    //********* Min/Max of Tree **********


    //Find Right Most (Max value), starting from root
    TreeNode<Type>* findRightMostChild() 
    {
        if (root == nullptr)
            return nullptr;
        else
            return findRightMostChild(root);
    };


    //Find Right Most (Max value), starting from given Node
    TreeNode<Type>* findRightMostChild(TreeNode<Type>* currentNode) 
    {
        //TODO repetitive of root condition, however there is a chance given null Node. Setup try throw to ensure that the issue doesn't persist
        if (currentNode == nullptr)
            return nullptr;
        else
        {
            if (currentNode->getRightNode() != nullptr)
                findRightMostChild(currentNode->getRightNode());
            else
                return currentNode;
        }
    };




    //Find Left Most (Min value), starting from root
    TreeNode<Type>* findLeftMostChild() 
    {
        if (root == nullptr)
            return nullptr;
        else
            return findLeftMostChild(root);
    };

    //Find Left Most (Min value), starting from given Node
    TreeNode<Type>* findLeftMostChild(TreeNode<Type>* currentNode) 
    {
        //TODO repetitive of root condition, however there is a chance given null Node. Setup try throw to ensure that the issue doesn't persist
        if (currentNode == nullptr)
            return nullptr;
        else
        {
            if (currentNode->getLeftNode() != nullptr)
                findRightMostChild(currentNode->getLeftNode());
            else
                return currentNode;
        }
    };

};

