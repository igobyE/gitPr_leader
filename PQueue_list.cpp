#include "PQueue_list.h"

PQueue::PQueue () : ptrHead (NULL) { }

void PQueue::insert (int k, int v) {
	Lnode *ptrTmp = ptrHead;
	Lnode *ptrNew = new Lnode (k, v);
	if (ptrHead == NULL) {
		ptrHead = ptrNew;
	}
	else {
		if (v >= ptrHead->val) {
			ptrNew->ptrNext = ptrHead;
			ptrHead = ptrNew;
		}
		else {
			while (v < ptrTmp->val && ptrTmp->ptrNext != NULL) {
				ptrTmp = ptrTmp->ptrNext;
			}
			ptrNew->ptrNext = ptrTmp->ptrNext;
			ptrTmp->ptrNext = ptrNew;
		}
	}
}

void PQueue::print () {
	Lnode *ptrTmp = ptrHead;
	while (ptrTmp != NULL) {
		std::cout << ptrTmp->key << ": " << ptrTmp->val << std::endl;
		ptrTmp = ptrTmp->ptrNext;
	}
}

void PQueue::getFirst (int& k, int& v) {
	if (ptrHead != NULL) {
		k = ptrHead->key;
		v = ptrHead->val;
	}
}

