/**
@author Phillip Chow

	ListNode is an extension of the Node class, to be implemented in list based applications
	The main characteristics that define it are:
	* A pointer to a preceding Node element
	* A pointer to the following Node element

	In addition, will also have added functionality of pointers pointing to a head node (for simplicity of tracking representatives) and tail
	These will be utilized as pointers to pointers. In other words, each node will have a pointer that points to a single representative pointer. 
	This pointer then points to the target head/tail. This way, if the Node object is deleted or changed, only a single pointer needs to change its value,
	instead of changing it for each node. The parent data structure will need to handle managing these pointers, thus will need interface methods to use them
*/



#pragma once


#include "Node.h"


template<class Type>
class ListNode : public Node<Type>
{
private:
	ListNode* previous; //Pointer to previous Node
	ListNode* next; //Pointer to next Node
		
	//Head and tail pointer pointers. Not only for making access to parts of data structure easier, but also for use with representatives and such
	ListNode** head;//Pointer that will point to a figurative head pointer. This makes accessing this unified for all related ListNodes (NOTE: this can be left for the data structure to handle, but for this example, we will allow elements to have this info as well) 
	ListNode** tail;//Pointer that will point to a figurative tail pointer. This makes accessing this unified for all related ListNodes (NOTE: this can be left for the data structure to handle, but for this example, we will allow elements to have this info as well) 

public:
	ListNode();
	ListNode(Type newData);
	

	ListNode** getHeadNode(); //returns a pointer to the head node this node belongs to
	ListNode** getTailNode(); //returns a pointer to the head node this node belongs to

	ListNode* getNextNode(); //return the next node in the list
	ListNode* getPreviousNode(); //returns the node previous to this one

	Type getData();

	void setHead(ListNode** newHead);
	void setTail(ListNode** newTail);
	void setNextNode(ListNode* newNext);
	void setPreviousNode(ListNode* newPrevious);

	void setData(Type newData);

};

