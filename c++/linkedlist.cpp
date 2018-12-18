// A class template for holding a linked list.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
	private:
	// Declare a structure for the list.
	struct ListNode
	{
		T value;					// Node value.
		struct ListNode *next;	// Point to next node
	};
	
	ListNode *head; 				// Head pointer
	
	public:
		// Constructor
		NumberList() {
			head = NULL;
		}
		// Destructor
		~NumberList();
		// Operations
		void appendNode(T);
		void insertNode(T);
		void deleteNode(T);
		void displayList() const;
};

//**************************************************
// appendNode appends a node containing the value  *
// passed into newValue, to the end of the list.   *
//**************************************************

template <class T>
void Linkedist<T>::appendNode( T newValue)
{
	ListNode *newNode;		// Point to a new node
	ListNode *nodePtr;		// Move through the list
	
	// Allocate a new node and store number.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;
	
	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else {
		nodePtr = head;
		
		//Find teh last node in the list
		while (nodePtr->next)
			nodePtr = nodePtr->next;
			
		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

template <class T>
void LinkedList<T>::displayList()
{
	ListNode *nodePtr;		// to move through the list
	
	// Place nodePtr at the head of the list
	nodePtr = head;
	
	// While nodePtr points to a node, traverse the list
	
	while(nodePtr)
	{
		// Display the value in this node
		cout << nodePtr->value << endl;
		
		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template <class T>
void LinkedList<T>::insertNode( T newValue)
{
	ListNode *newNode;			// a new node
	ListNOde *nodePtr;			// used to traverse the list
	ListNode *previousNode = NULL;	// the previous node
	
	// allocate a new node and store num
	newNode = new ListNode;
	newNode->value = num;
	
	// if there are no nodes in the list, make newNode the first node.
	
	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else {
		// Position nodePtr at the head of the list
		nodePtr = head;
		
		// Init previousNode to NUll.
		previousNode = NULL;
		
		// Skip all nodes whose value is less than num
		while ( nodePtr != NULL && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		// If the new node is to the 1st in the list,
		// insert it vefore other nodes.
		
		if (previousNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template <class T>
void LinkedList<T>::deleteNode( T searchValue)
{
	ListNode *nodePtr;
	ListNode *previousNode;
	
	// If hte list is emply, do nothing
	if (!head)
		return;
		
	// Find if the first node is the one to delete
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		// Initialize notePtr to head of the list.
		nodePtr = head;
		
		// Skip all nodes whose value member is not equal to num
		while (nodePtr != NULL && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		/* If node ptr is not a the end of the list,
			link the previous node ot the node after
			nodeptr, then delete nodeptr
		*/
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	
	nodePtr = head;
	
	while (nodePtr != Null)
	{
		nextNode = nodePtr->next;
		
		// Delete the current node
		delete nodePtr;
		
		// Position nodePtr at the next node
		nodePtr = nextNode;
	}
}
int main(int argc, char *argv[]) {
	cout << "Call linked list template functions" << endl;
	
	// Define a LinkedList object.
	LinkedList<FeetInches> list;
	
	// Define FeetInches objects.
	FeetInches distance(5,4);
	
	// Store FeetInches objects in the list.
	list.appendNode(distance);
	
	// Display the values in the list
	cout << "Initial values" << endl;
	list.displayList();
	
	// Delete the last node.
	cout << "Deleting the last node.\n"
	FeetInches distance(5,4);
	list.deleteNode(distance);
	
	// Display the values in the list
	cout << "Here are the nodes left.\n"
	list.displayList();
	
	return 0;
}