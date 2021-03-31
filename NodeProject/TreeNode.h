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

	TreeNode();
	TreeNode(Type newData);

	~TreeNode();

	Type getData();

	TreeNode<Type>* getLeftNode(); //returns a pointer to the left child node
	TreeNode<Type>* getRightNode(); //returns a pointer to the right child node


	TreeNode<Type>* getParentNode(); //return the parent node of this TreeNode


	void setParentNode(TreeNode<Type>* newParent);
	void setLeftNode(TreeNode<Type>* newTail);
	void setRightNode(TreeNode<Type>* newNext);
	

	void setData(Type newData);

};

