#include <iostream>
using namespace std;

class Node {
	public:
		int value;
		
		Node *left;
		Node *right;
		
		Node(int val){
			value = val;
			right = left = NULL;
		}
};

class BinaryTree {
	public:
		Node *root;
		
		BinaryTree(){
			root = NULL;
		}
		
		// INSERT
		void insertNode(Node *tmp);
		Node *insertNode(Node *currentNode, Node *tmp);
		
		// TRAVERSAL
		void preOrder();
		Node *preOrder(Node *currentNode);
		
		void inOrder();
		void inOrder(Node *currentNode);
		
		void postOrder();
		void postOrder(Node *currentNode);
		
		// SEARCH
		Node *searchNode(int searchVal); // mengakses root pertama
		Node *searchNode(Node *currentNode, int searchVal); // mengakses setelah root
		
		// DELETE
		void deleteNode(int delVal);
		Node *deleteNode(Node *currentNode, int delVal);
		
		Node *findMin(Node *tmp);
		
};
