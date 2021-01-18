/**
@author Phillip Chow

TreeNode.cpp

Implementation of TreeNode class. This class extends the Node class, to be implemented in a binary tree type data structure
*/


#include "TreeNode.h"

//Constructors
template<class Type>
TreeNode<Type>::TreeNode()
{
	data = null;

	leftNode = null;
	rightNode = null;

	parentNode = null;
}

template<class Type>
ListNode<Type>::ListNode(Type newData)
{
	data = newData;

	leftNode = null;
	rightNode = null;

	parentNode = null;
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
	return tail;
}

template<class Type>
TreeNode<Type>* TreeNode<Type>::parentNode()
{
	return parent;
}



template<class Type>
Type TreeNode<Type>::getData()
{
	return data;
}

//Setters
template<class Type>
void TreeNode<Type>::setParentNode(TreeNode<Type>* newParent)
{
	parentNode = newPArent;
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
	data = newData;
}

