#ifndef PQUEUE_LIST_H
#define PQUEUE_LIST_H

#include <iostream>

struct Lnode {
	int key;
	int val;
	Lnode *ptrNext;

	Lnode () : key (0), val (0), ptrNext (NULL) {}
	Lnode (int k, int v) : key (k), val (v), ptrNext (NULL) {}
};

class PQueue {
private:
	Lnode *ptrHead;

public:
	PQueue ();
	void insert (int k, int v);
	void getFirst (int& k, int& v);
	void print ();

};

#endif