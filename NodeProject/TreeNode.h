/**
@author Phillip Chow

	TreeNode is an extension of the Node class, to be implemented in list based applications
	The main characteristics that define it are:
	* Two pointers to left and right child
	* A node to the parent

	Unlike ListNode, will not also track a head node of the entire tree. Will leave this to the data structure to handle
*/


#pragma once

#include "Node.h"


template<class Type>
class TreeNode : public Node<Type>
{
private:
	TreeNode<Type>* leftNode; //Pointer to previous Node
	TreeNode<Type>* rightNode; //Pointer to previous Node
	TreeNode<Type>* parentNode; //Pointer to previous Node

	
public:

	TreeNode() : Node<Type>()
	{

		leftNode = nullptr;
		rightNode = nullptr;

		parentNode = nullptr;
	};
	TreeNode(Type newData) : Node<Type>() {
		this->data = newData;

		leftNode = nullptr;
		rightNode = nullptr;

		parentNode = nullptr;
	};

	//TODO 4/6/2021 Hold off, copy constructor
	//TreeNode(const TreeNode& otherNode);


	//TODO 4/7/2021 seeing if this is causing linking issue
	//~TreeNode();




	Type getData() {
		return this->data;
		
	};

	TreeNode<Type>* getLeftNode() {
		return leftNode;
		
	}; //returns a pointer to the left child node

	TreeNode<Type>* getRightNode() {
		return rightNode;
		
	}; //returns a pointer to the right child node


	TreeNode<Type>* getParentNode() {
		return parentNode;
	}; //return the parent node of this TreeNode


	void setParentNode(TreeNode<Type>* newParent) {
		parentNode = newParent;
	};
	void setLeftNode(TreeNode<Type>* newLeftNode) {
		leftNode = newLeftNode;
		if(newLeftNode != nullptr)
			newLeftNode->setParentNode(this);
	};
	void setRightNode(TreeNode<Type>* newRightNode) {
		rightNode = newRightNode;
		if (newRightNode != nullptr)
			newRightNode->setParentNode(this);
	};
	

	void setData(Type newData) {
		this->data = newData;
	};

	//TODO 4/6/2021 Hold off on this
	//void operator=(TreeNode<Type>* targetNode); // overloaded copy assignment operator
};

