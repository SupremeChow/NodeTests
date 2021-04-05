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
protected:
	Type data; //Template data
	virtual bool compare(Node<Type>* targetNode) = 0; //Virtual method needed to compare, return true if items are the same (by pointed object, not just value)

	
public:
	Node() {}; //Default Constructor
	Node(Type newData):data() {}; //Overloaded constructor (default constructor for data's Type)

	/* TODO 4/5/2021 Making NON pure virtual, since all child classes should use the same orperator comparison 
	virtual bool operator<(Node<Type>* targetNode) = 0; //Virtual method for checking if less than
	virtual bool operator<=(Node<Type>* targetNode) = 0; //Virtual method for checking if less than or equal
	virtual bool operator==(Node<Type> * targetNode) = 0; //Virtual method for checking if equal
	virtual bool operator>=(Node<Type>* targetNode) = 0; //Virtual method for checking if greater than or equal
	virtual bool operator>(Node<Type>* targetNode) = 0; //Virtual method for checking if greater than
	*/

	bool operator<(Node<Type>* targetNode); //Virtual method for checking if less than
	bool operator<=(Node<Type>* targetNode); //Virtual method for checking if less than or equal
	bool operator==(Node<Type>* targetNode); //Virtual method for checking if equal
	bool operator>=(Node<Type>* targetNode); //Virtual method for checking if greater than or equal
	bool operator>(Node<Type>* targetNode); //Virtual method for checking if greater than



	virtual void operator=(Node<Type>* targetNode) = 0; //Virtual overloaded copy assignment operator

};

/*Implemenation of Node Virtual Functions*/
template<class Type>
bool Node<Type>::compare(Node<Type>* targetNode) //Virtual method needed to compare, return true if items are the same (By pointed object, not just value)
{
	return (this == targetNode) ? true : false;
}
template<class Type>
bool Node<Type>::operator<(Node<Type>* targetNode) //Virtual method for checking if less than
{
	return (this->data < targetNode->data) ? true : false;
}

template<class Type>
bool Node<Type>::operator<=(Node<Type>* targetNode) //Virtual method for checking if less than or equal
{
	return (this->data <= targetNode->data) ? true : false;
}

template<class Type>
bool Node<Type>::operator==(Node<Type>* targetNode) //Virtual method for checking if equal
{
	return (this->data == targetNode->data) ? true : false;
}

template<class Type>
bool Node<Type>::operator>=(Node<Type>* targetNode) //Virtual method for checking if greater than or equal
{
	return (this->data >= targetNode->data) ? true : false;
}

template<class Type>
bool Node<Type>::operator>(Node<Type>* targetNode)  //Virtual method for checking if greater than
{
	return (this->data > targetNode->data) ? true : false;
}
