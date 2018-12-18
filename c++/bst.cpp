// BST, left is less than or equal to right
// prerequisites: pointers, dynamic memory allocation
// similar to linked list: nodes, links
// Can be done recursivelly

// Node, left and right chicld

#include<iostream>

using namespace std;

struct BstNode {
	int data;
	BstNode* left; // pointer to left child
	BstNode* right; // pointer to right child
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data) {
	if(root == NULL) { //empty tree
		root = GetNewNode(data);
		return root;
	}
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

bool Search(BstNode* root, int data) {
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if(data <= root->data) return Search(root->left,data);
	else return Search(root->right,data);
}

int main(int argc, char *argv[]) {
	
	BstNode* root = NULL; // empty tree
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	
	int number;
	cout << "Enter number to be searched\n";
	cin >> number;
	if(Search(root,number) == true)  
		cout << "Found\n";
	else cout <<"Not found\n";
}