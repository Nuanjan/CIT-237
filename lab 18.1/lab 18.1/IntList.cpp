#include<iostream>
#include<iomanip>
#include "IntList.h"
using namespace std;
void IntList::appendNode(int num)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list
						// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;
	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else  // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}    //    end else-if

	//print();
}    //    end function appendNode
void IntList::print() const
{
	ListNode *nodePtr;  // To move through the list
	cout << "Head=" << head << endl;
	nodePtr = head;
	
	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{

		
		cout <<&nodePtr->value<<":    Value= " 
			<< setw(5) << nodePtr->value << setw(5);
		cout << " next= " << setw(5) << &nodePtr->next << endl;;
	// Move to the next node.
		
		nodePtr = nodePtr->next;
		
		
	}    //    end while
	
}    //    end function print


	void IntList::insertNode(int num)
	{
		ListNode *newNode;             // A new node
		ListNode *nodePtr;             // To traverse the list
		ListNode *previousNode = NULL; // The previous node
									   // Allocate a new node and store num there.
		newNode = new ListNode;
		newNode->value = num;
		newNode->next = NULL;
		// If there are no nodes in the list
		// make newNode the first node
		if (!head)
			head = newNode;
		else  // Otherwise, insert newNode
		{
			// Position nodePtr at the head of list.
			nodePtr = head;
			//    Initialize previousNode to NULL.
			previousNode = NULL;
			//    Skip all nodes whose value is less than num.
			while (nodePtr != NULL && nodePtr->value < num)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}//    If the new node is to be the 1st in the list,
			 //    insert it before all other nodes.
			if (previousNode == NULL)
			{
				head = newNode;
				newNode->next = nodePtr;
			}
			else  // Otherwise insert after the previous node.
			{
				previousNode->next = newNode;
				newNode->next = nodePtr;
			}
		}    //    end else-if
		//print();
	}    //    end function insertNode

	void IntList::selectionSort(ListNode * nodePtr)
	{
		ListNode * temp = nodePtr;
		ListNode * curr;

		for (bool Swap = true; Swap; )
		{
			Swap = false;
			for (curr = nodePtr; curr->next != NULL; curr = curr->next)
			{
				if (curr->value > curr->next->value)
				{
					temp->value = curr->value;
					curr->value = curr->next->value;
					curr->next->value = temp->value;
					Swap = true;
				}
			}
		}
	}

	void IntList::deleteNode(int num)
	{
		ListNode *nodePtr=NULL;       // To traverse the list
		ListNode *previousNode=NULL;  // To point to the previous node

								 // If the list is empty, do nothing.
		if (!head)
		{
			cout << "\n\tFailed to delete as list is empty.";
			return;
		}        // Determine if the first node is the one.
		if (head->value == num)
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{        // Initialize nodePtr to head of list
			nodePtr = head;

			// Skip all nodes whose value member is
			// not equal to num.
			while (nodePtr != NULL && nodePtr->value != num)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			// If nodePtr is not at the end of the list,
			// link the previous node to the node after
			// nodePtr, then delete nodePtr.
			if (nodePtr)
			{
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
			else
				cout << "Data value" << num
				<< " not found." << endl;
		}    //    end else-if

		//print();
	}    //    end function deleteNode
	IntList::~IntList()
	{
		ListNode *nodePtr;   // To traverse the list
		ListNode *nextNode;  // To point to the next node
							 // Position nodePtr at the head of the list.
		nodePtr = head;
		// While nodePtr is not at the end of the list...
		while (nodePtr != NULL)
		{
			// Save a pointer to the next node.
			nextNode = nodePtr->next;

			// Delete the current node.
			delete nodePtr;

			// Position nodePtr at the next node.
			nodePtr = nextNode;
		}    //    end while
	}    //    end destructor

	int IntList::countNodes(ListNode *nodePtr) const {
		if (nodePtr != NULL)
			return 1 + countNodes(nodePtr->next);
		else
			return 0;
	}

	void IntList::showReverse(ListNode *nodePtr)const {
		if (nodePtr != nullptr) {
			showReverse(nodePtr->next);
			
		}
	}