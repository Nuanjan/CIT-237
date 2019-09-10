#ifndef IntList_H
#define IntList_H
class IntList
{
private:
	
	// Declare a structure for the list
	struct ListNode
	{
		int value;        // The value in this node
		struct ListNode *next;// To point to the next node
	};
	ListNode *head;        // List head pointer

	//private function
	int countNodes(ListNode *nodePtr) const;
	void showReverse(ListNode *) const;
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
	void print()const ;
	void selectionSort(ListNode*);
	int numNodes()const
	{
		return countNodes(head);
	}
	void displayBackwards()const
	{
		showReverse(head);
	}
	
};
#endif
