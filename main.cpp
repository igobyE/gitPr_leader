#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "BSTree.h"
#include "PQueue_list.h"

int solution (int A[], int n) {
	BSTree aTree = BSTree ();
	for (int i=0; i<n; ++i) {
		aTree.insert (A[i]);
	}
	aTree.printTree ();
	std::cout << " - - - - - \n";
	int maxK, maxV;
	aTree.getKeyWithMaxVal (maxK, maxV);
	std::cout << "Dominent key: " << maxK << " with value: " << maxV << std::endl;

	 return 0;
}

int* genRanArr (int s) {
	int *arr = new int[s];
	for (int i=0; i<s; ++i) {
		arr[i] = rand() % 5 + 1;
	}

	return arr;
}

void printArr (int *arr, int s) {
	for (int i=0; i<s; ++i) {
		std::cout << arr[i] <<" ";
	}
	std::cout << std::endl;
}

int main () {
	srand (time (NULL));
	int sizeArr = 10;
	int *arr = genRanArr (sizeArr);

	printArr (arr, sizeArr);
	std::cout << "Dominant: \n" << solution (arr, sizeArr) << std::endl;

	return 0;
}