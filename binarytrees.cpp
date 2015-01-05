#include <iostream>

using namespace std;

struct node
{
	int key_value;
	int *left;
	int *right;
};

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

void btree::insert(int key, node *leaf)
{
	if(key < leaf->key_value)
	{
		if(leaf->left!=NULL)
			insert(key, leaf->left);
		else {
				leaf->left=new node;
				leaf->left->key_value=key;
				leaf->left->left=NULL;
				leaf->left->right=NULL;
		}
	}
	else if(key>=leaf->key_value)
	{
		if(leaf->right=leaf!=NULL)
			insert(key, leaf->right);
		else {
			leaf->right=new node;
			leaf->right->key_value=key;
			leaf->right->left=NULL;
			leaf->right->right=NULL;
		}
	}
		
}

node *btree::search(int key, node *leaf)
{
	if(leaf!=NULL)
	{
		if(key==leaf->key_value)
			return leaf;
		if(key < leaf->key_value)
			return search(key, leaf->left);
		else {
			return search(key, leaf->right);
		}
	}
	else return NULL;
}


int main(int argc, char *argv[]) {
	cout << "Implementation of binary tree, search insert, and destroy in C++" << endl
		 << "Tutorial source: http://www.cprogramming.com/tutorial/lesson18.html" << endl;
}