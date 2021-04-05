/**
@author Phillip Chow

TreeNode.cpp

Implementation of TreeNode class. This class extends the Node class, to be implemented in a binary tree type data structure
*/


#include "TreeNode.h"

//Constructors
template<class Type>
TreeNode<Type>::TreeNode():Node()
{

	leftNode = nullptr;
	rightNode = nullptr;

	parentNode = nullptr;
}

template<class Type>
TreeNode<Type>::TreeNode(Type newData)
{
	this->data = newData;

	leftNode = nullptr;
	rightNode = nullptr;

	parentNode = nullptr;
}



//Getters
template<class Type>
TreeNode<Type>* TreeNode<Type>::getLeftNode()
{
	return leftNode;
}

template<class Type>
TreeNode<Type>* TreeNode<Type>::getRightNode()
{
	return rightNode;
}

template<class Type>
TreeNode<Type>* TreeNode<Type>::getParentNode()
{
	return parentNode;
}



template<class Type>
Type TreeNode<Type>::getData()
{
	return this->data;
}

//Setters
template<class Type>
void TreeNode<Type>::setParentNode(TreeNode<Type>* newParent)
{
	parentNode = newParent;
}

template<class Type>
void TreeNode<Type>::setLeftNode(TreeNode<Type>* newLeftNode)
{
	leftNode = newLeftNode;
}

template<class Type>
void TreeNode<Type>::setRightNode(TreeNode<Type>* newRightNode)
{
	rightNode = newRightNode;
}


template<class Type>
void TreeNode<Type>::setData(Type newData)
{
	this->data = newData;
}


//Implementation of Node's virutal assignment operator
template<class Type>
void TreeNode<Type>::operator=(TreeNode<Type>* targetNode) //Virtual overloaded copy assignment operator
{
	this->data = targetNode->data;
	this->parent = targetNode->parent;
	this->leftNode = targetNode->leftNode;
	this->rightNode = targetNode->rightNode;
	
}
