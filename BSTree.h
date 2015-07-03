#ifndef BSTREE_H
#define BSTREE_H

#include "PQueue_list.h"

struct Tnode {
	int key;
	int val;
	Tnode *ptrL;
	Tnode *ptrR;

	Tnode () : key (0), val (0), ptrL (NULL), ptrR (NULL) {	}
	Tnode (int k, int v) {
		key = k;
		val = v;
		ptrL = NULL;
		ptrR = NULL;
	}
};

class BSTree {
private:
	Tnode *root;

	void insert (Tnode* ptrTnode, int key);
	void destroy (Tnode *ptrTnode);
	void inOrder (Tnode* const ptrTnode);
	void popPQueue (Tnode* const ptrTnode, PQueue& aQueue);

public:
	BSTree ();
	~BSTree ();

	void insert (int k);
	void printTree ();
	void getKeyWithMaxVal (int& k, int& v);
};
#endif