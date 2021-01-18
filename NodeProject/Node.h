/**
@author Phillip Chow

	Node is a generic class to be implemented for data structures like trees and such
	Rather than be a simple node with a data of int, will use templates, and have child classes provide implementations for comparisons and such
	This will therefore act as an interface
*/



#pragma once


template<class Type>



class Node
{
private:
	Type data; //Template data
	virtual bool compare(Node<Type>* targetNode) = 0; //Virtual method needed to compare, return true if items are the same

	
public:

	virtual bool operator<(Node<Type>* targetNode) = 0; //Virtual method for checking if less than
	virtual bool operator<=(Node<Type>* targetNode) = 0; //Virtual method for checking if less than or equal
	virtual bool operator>= = (Node<Type> * targetNode) = 0; //Virtual method for checking if equal
	virtual bool operator>=(Node<Type>* targetNode) = 0; //Virtual method for checking if greater than or equal
	virtual bool operator>(Node<Type>* targetNode) = 0; //Virtual method for checking if greater than

	virtual Node<Type> operator=(Node<Type>* targetNode) = 0; //Virtual overloaded copy assignment operator

};

