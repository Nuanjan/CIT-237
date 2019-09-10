#ifndef IntList_H
#define IntList_H
#include<iomanip>
#include<iostream>
class IntList
{
private:

	// Declare a structure for the list
	struct ListNode
	{
		int value; // The value in this node
		struct ListNode *next;// To point to the next node
	};

	ListNode *head;

	//private function
		   // List head pointer
	int countNodes(ListNode *nodePtr) const;
	void printH(ListNode *nodePtr);
	//void showReverse(ListNode *nodePtr)const;
	//int findSum(ListNode *nodePtr)const;
	//void displayRecursive(ListNode *nodePtr) const;

public:
	// Constructor
	IntList()
	{
		head = NULL;
	}



	// Destructor
	~IntList();
	// Linked list operations
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void print()const;

	void selectionSort(ListNode*);


	struct ListNode *getHead();



	void displayRecursive(ListNode *curr);
};

	
	
#endif
