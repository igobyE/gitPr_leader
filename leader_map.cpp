#include <iostream>
#include <map>

#define SIZE 10

int solution (int A[], int n) {
	std::map<int, int> assArr;

	for (int i=0; i<n; i++) {
		std::map<int, int>::iterator it;
		it = assArr.find(A[i]);
		if (it == assArr.end()) {
			assArr[A[i]] = 1;
		}
		else {
			assArr[A[i]] += 1;
		}
	}

	for (std::map<int, int>::iterator it = assArr.begin (); it!= assArr.end ();
		++it) {
		if (it->second > n/2)
			return it->first;
	}

	return -1;
}

int main (int argc, char ** argv) {
	int A[SIZE] = {4, 2, 2, 3, 2, 4, 2, 2, 6, 4};

	std::cout << "Leader = " << solution (A, SIZE)<< std::endl;;

	return 0;
}