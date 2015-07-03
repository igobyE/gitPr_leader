#include "BSTree.h"

void BSTree::insert (Tnode* ptrTnode, int key) {
	if (key < ptrTnode->key) {
		if (ptrTnode->ptrL != NULL) {
			insert (ptrTnode->ptrL, key);
		}
		else {
			ptrTnode->ptrL = new Tnode (key, 1);
		}
	}
	else if (key > ptrTnode->key) {
		if (ptrTnode->ptrR != NULL) {
			insert (ptrTnode->ptrR, key);
		}
		else {
			ptrTnode->ptrR = new Tnode (key, 1);
		}
	}
	else {
		ptrTnode->val += 1;
	}
}

void BSTree::destroy (Tnode *ptrTnode) {
	if (ptrTnode != NULL) {
		destroy (ptrTnode->ptrL);
		destroy (ptrTnode->ptrR);
		delete ptrTnode;
	}
}

void BSTree::inOrder (Tnode* const ptrTnode) {
	if (ptrTnode != NULL) {
		inOrder (ptrTnode->ptrL);
		std::cout << ptrTnode->key << ": " << ptrTnode->val << std::endl;
		inOrder (ptrTnode->ptrR);
	}
}

BSTree::BSTree () : root (NULL){ }
BSTree::~BSTree () {
	destroy (root);
}

void BSTree::insert (int k) {
	if (root == NULL) {
		root = new Tnode (k, 1);
	}
	else {
		insert (root, k);
	}
}
void BSTree::printTree () {
	inOrder (root);
}

void BSTree::popPQueue (Tnode* const ptrTnode, PQueue& aQueue) {
	if (ptrTnode != NULL) {
		popPQueue (ptrTnode->ptrL, aQueue);
		aQueue.insert (ptrTnode->key, ptrTnode->val);
		// aQueue.print ();
		// std::cout << " - - - - - \n";
		popPQueue (ptrTnode->ptrR, aQueue);
	}
}

void BSTree::getKeyWithMaxVal (int &k, int &v) {
	PQueue aQueue = PQueue ();
	popPQueue (root, aQueue);
	std::cout << "priority queue:\n";
	aQueue.print ();
	aQueue.getFirst (k, v);
}