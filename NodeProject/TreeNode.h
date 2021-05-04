/**
@author Phillip Chow

	TreeNode is an extension of the Node class, to be implemented in tree based applications
	The main characteristics that define it are:
	* Two pointers to left and right child
	* A node to the parent

*/


#pragma once

#include "Node.h"


template<class Type>
class TreeNode : public Node<Type>
{
private:
	TreeNode<Type>* leftNode; //Pointer to Left Node
	TreeNode<Type>* rightNode; //Pointer to Right Node
	TreeNode<Type>* parentNode; //Pointer to Parent Node

	
public:

/************************************************************
				Constructor/Destructors
************************************************************/
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

	//TODO Add overloaded constrtructor with given pointers (!!! Need method to check if new pointers are valid after creation !!!!)
	//TreeNode(Type newData, TreeNode*& newLeftNode, TreeNode*& newRightNode, TreeNode*& newParentNode,)


	//TODO 4/6/2021 Hold off, copy constructor
	//TreeNode(const TreeNode& otherNode);


	//TODO 4/7/2021 seeing if this is causing linking issue
	//~TreeNode();



/************************************************************
					Getters/Setters
************************************************************/



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

