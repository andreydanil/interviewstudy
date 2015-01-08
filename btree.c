// Binary tree
// hierarchal data: used for file system
// organize data: search, insertion, deletion
// trie - dictionary
// network routing algorithm

// Array
// search(x) - O(n)
// insert(x) - O(1)
// remove(x) - O(n)

// Linked list
// search(x) - O(n)
// insert(x) - O(1)
// remove(x) - O(n)

// BST
// search(x) - O(log n)
// insert(x) - O(log n)
// remove(x) - O(log n)

// Binary search
// sorted array search- O(logn)


struct Node {
	int data;
	Node *left;
	Node *right;
};

#include <iostream>

using namespace std;

class btree
{
	public:
		btree();
		~btree();
		
		void insert(int key);
		node *search (int key);
		void destroy_tree();
		
	private:
		void destroy_tree(node *leaf);
		void insert(int key, node *leaf);
		node *search(int key, node *leaf);
		
		node *root;
};

// Initializing tree.
btree::btree()
{
	root=NULL;
}

btree::~btree()
{
	root = NULL;
}

void btree::destroy_tree(nod	e *leaf)
{
	if(leaf!=NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}


node *btree::search(int key){
	return search(key,root);
}

