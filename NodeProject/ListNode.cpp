/**
@author Phillip Chow

ListNode.cpp

Implementation of ListNode class. This class extends the Node class, to be implemented in a list type data structure
*/


#include "ListNode.h"

//Constructors
template<class Type>
ListNode<Type>::ListNode()
{
	data = null;

	head = null;
	tail = null;

	next = null;
	previous = null;
}

template<class Type>
ListNode<Type>::ListNode(Type newData)
{
	data = newData;

	head = null;
	tail = null;

	next = null;
	previous = null;
}



//Getters
template<class Type>
ListNode<Type>** ListNode<Type>::getHeadNode()
{
	return head;
}

template<class Type>
ListNode<Type>** ListNode<Type>::getTailNode()
{
	return tail;
}

template<class Type>
ListNode<Type>* ListNode<Type>::getNextNode()
{
	return next;
}

template<class Type>
ListNode<Type>* ListNode<Type>::getPreviousNode()
{
	return previous;
}

template<class Type>
Type ListNode<Type>::getData()
{
	return data;
}

//Setters
template<class Type>
void ListNode<Type>::setHead(ListNode<Type>** newHead)
{
	head = newHead;
}

template<class Type>
void ListNode<Type>::setTail(ListNode<Type>** newTail)
{
	tail = newTail;
}

template<class Type>
void ListNode<Type>::setNextNode(ListNode<Type>* newNext)
{
	next = newNext;
}

template<class Type>
void ListNode<Type>::setPreviousNode(ListNode<Type>* newPrevious)
{
	previous = newPrevious;
}

template<class Type>
void ListNode<Type>::setData(Type newData)
{
	data = newData;
}
