#include <iostream>

struct Node {
	int key;
	int val;
	Node *ptrL;
	Node *ptrR;

	Node () : key (0), val (0), ptrL (NULL), ptrR (NULL) {	}
	Node (int k, int v) {
		key = k;
		val = v;
		ptrL = NULL;
		ptrR = NULL;
	}
	// ~Node () {
	// 	// if (ptrL != NULL)
	// 		delete ptrL;
	// 		ptrL = NULL;
	// 	// if (ptrR != NULL)
	// 		delete ptrR;
	// 		ptrR = NULL;
	// }
};

class BTree {
private:
	Node *root;

	void insert (Node* ptrNode, int key) {
		if (key < ptrNode->key) {
			if (ptrNode->ptrL != NULL) {
				insert (ptrNode->ptrL, key);
			}
			else {
				ptrNode->ptrL = new Node (key, 1);
			}
		}
		else if (key > ptrNode->key) {
			if (ptrNode->ptrR != NULL) {
				insert (ptrNode->ptrR, key);
			}
			else {
				ptrNode->ptrR = new Node (key, 1);
			}
		}
		else {
			ptrNode->val += 1;
		}
	}

	void destroy (Node *ptrNode) {
		if (ptrNode != NULL) {
			// if (ptrNode->ptrL != NULL)
				destroy (ptrNode->ptrL);
			// if (ptrNode->ptrR != NULL)
				destroy (ptrNode->ptrR);
			delete ptrNode;
		}
	}

	void inOrder (Node* const ptrNode) {
		if (ptrNode != NULL) {
			inOrder (ptrNode->ptrL);
			std::cout << ptrNode->key << ": " << ptrNode->val << std::endl;
			inOrder (ptrNode->ptrR);
		}
	}

	int getMax (Node* const ptrNode) {
		if (ptrNode != NULL) {
			int valL = getMax (ptrNode->ptrL);
			int valR = getMax (ptrNode->ptrR);
			inOrder (ptrNode->ptrR);
		}
	}

public:
	BTree () : root (NULL){ }
	~BTree () {
		destroy (root);
	}

	void insert (int k) {
		if (root == NULL) {
			root = new Node (k, 1);
		}
		else {
			insert (root, k);
		}
	}
	void printTree () {
		inOrder (root);
	}

	void getKeyWithMaxVal () {

	}
};

int solution (int A[], int n) {
	BTree aTree = BTree ();
	for (int i=0; i<n; ++i) {
		aTree.insert (A[i]);
	}

	aTree.insert (2);
	aTree.insert (2);
	aTree.insert (3);
	aTree.insert (2);
	aTree.insert (4);
	aTree.insert (2);
	aTree.insert (2);
	aTree.insert (6);
	aTree.insert (4);
	aTree.printTree ();

	return -1;
}

int main () {
	std::cout << "START:" << std::endl;
	// 4, 2, 2, 3, 2, 4, 2, 2, 6, 4


	return 0;
}