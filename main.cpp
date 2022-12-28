#include <iostream>
#include "BinaryTree.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	BinaryTree *bin = new BinaryTree();
	
	Node *tmp = new Node(10);
	bin->insertNode(tmp);
	bin->insertNode(new Node(20));
	bin->insertNode(new Node(5));
	bin->insertNode(new Node(15));
	
	// cout << bin->root->left->value << endl;
	bin->inOrder();
	
	bin->deleteNode(10);
	
	cout << endl;
	bin->inOrder();
	cout << "\n root:" << bin->root->value;
	
	
	return 0;
}
