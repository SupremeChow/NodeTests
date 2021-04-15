/**
@author Phillip Chow

	Node is a generic class to be implemented for data structures like trees and such
	Rather than be a simple node with a data of int, will use templates, and have child classes provide implementations for comparisons and such
	This will therefore act as an interface
*/

#include "Node.h"




/* TODO 4/15/2021 Move to .h since template


template<class Type>
Node<Type>::Node() : data() {}; //Default Constructor

template<class Type>
Node<Type>::Node(Type newData) : data(newData) {}; //Overloaded constructor (default constructor for data's Type)


*/




/*Implemenation of Node Comparison Functions*/
//TODO 4/6/2021 Hold off on this
/*
template<class Type>
bool Node<Type>::compare(Node<Type>* targetNode) //Virtual method needed to compare, return true if items are the same (By pointed object, not just value)
{
	return (this == targetNode) ? true : false;
}
*/



/* TODO 4/15/2021 Moving to .h since template


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

*/