#include <iostream>
#include "BinaryTree.h"
using namespace std;

// INSERT node
void BinaryTree::insertNode(Node *tmp){
	root = insertNode(root, tmp);
}

Node *BinaryTree::insertNode(Node *currentNode, Node *tmp){
	
	if (currentNode==NULL){
		currentNode = tmp;
	}
	
	else if (tmp->value<currentNode->value){
		currentNode->left = insertNode(currentNode->left, tmp);
	}
	
	else if (tmp->value>currentNode->value){
		currentNode->right = insertNode(currentNode->right, tmp);
	}
 	
	return currentNode;
}

// SEARCH
Node *BinaryTree::searchNode(int searchVal){
	return searchNode(root, searchVal);
}

Node *BinaryTree::searchNode(Node *currentNode, int searchVal){
	
	if (currentNode->value == searchVal){
		return currentNode;
	}
	
	else if (searchVal < currentNode->value){
		return searchNode(currentNode->left, searchVal);
	}
	
	else if (searchVal > currentNode->value){
		return searchNode(currentNode->right, searchVal);
	}
	
	else
		return NULL;
		
}

// TRAVERSAL
void BinaryTree::inOrder(){
	inOrder(root);
}

void BinaryTree::inOrder(Node *currentNode){
	
	if (currentNode!=NULL){
		inOrder(currentNode->left);
		cout << currentNode->value << ", ";
		inOrder(currentNode->right);
	}
	
}

// DELETE, saat delete node pertama cari value nya, hapus node berdasarkan value nya
void BinaryTree::deleteNode(int delVal){
	root = deleteNode(root, delVal); //dimulai dari root, lalu value nya
}

Node *BinaryTree::deleteNode(Node *currentNode, int delVal){
	
	//jika curentNode=NULL/belum ketemu, return null
	if (currentNode==NULL)
		return NULL;
	
	//lebih kecil, jika lebih kecil kekiri, lalu delete currentNode->kiri
	else if (delVal < currentNode->value){
		currentNode->left = deleteNode(currentNode->left, delVal); 
	}
	
	//lebih besar, jika lebih besar kekiri, lalu delete currentNode->kanan
	else if (delVal > currentNode->value){
		currentNode->right = deleteNode(currentNode->right, delVal); 
	}
	
	else if (currentNode->value == delVal){ // jika ditemukan
		
		if (currentNode->left==NULL && currentNode->right==NULL){ // leaf, kirikanan NULL=leaf
			
			//jika leaf simpan dulu currentNodenya di *tmp, lalu NULL kan, setelah itu del
			Node *tmp = currentNode; 
			currentNode = NULL;
			
			delete tmp;
			
		}
		
		//jika sebelah kiri tidak NULL, maka sebelah kiri ke atas/simpan *tmp
		else if (currentNode->left!=NULL && currentNode->right==NULL){ // menghapus node sebelah kiri
			Node *tmp = currentNode;
			currentNode = currentNode->left; //ambil di kiri
			delete tmp;
			
		}
		
		else if (currentNode->left==NULL && currentNode->right!=NULL){ // menghapus node sebelah kanan, dengan 1 child
			Node *tmp = currentNode;
			currentNode = currentNode->right; //ambil kanan
			delete tmp;
			
					
		}
		
		// else if (currentNode->left!=NULL && currentNode->right!=NULL){ // JIKA ADA 2 CHILDREN
		else {
			
			Node *minNode = findMin(currentNode->right); //cari node sebelah kanan yg paling kecil, dpt node yg paling kecilkanan
			currentNode->value = minNode->value; //lalu copy ke currentNode
			
			currentNode->right = deleteNode(currentNode->right, minNode->value); //delete node kanan yg paling kecil
			
			
		}
		
		
	}	
	
	//jalankan curentNode diatas
	return currentNode;
}

//algo findmin
Node *BinaryTree::findMin(Node *tmp){
		
	if (tmp->left==NULL) //jika tidak ada di sebelah kiri, dia lah yg paling kecil
		return tmp;
	else
		return findMin(tmp->left); //jika masih ada di sebelah kiri, cari sebelah kkiri sampi gk ada node di sebelah kiri
}
