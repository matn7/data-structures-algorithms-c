#include <stdio.h>
#include <stdlib.h>

void adjust(int heapArray[], int i, int n) {
	int j = 2 * i; // left child of i
	int item = heapArray[i];	

	// iterate as long as there is an element at j
	while (j <= n) {
		// compare if j siblings exists
		if (j < n && heapArray[j] < heapArray[j+1]) {
			j = j + 1;
		}
		if (item >= heapArray[j]) {
			break;
		}
		heapArray[j/2] = heapArray[j];
		j = 2 * j;
	}
	heapArray[j/2] = item;
}

void heapSort(int array[], int n) {
	heapify(array, n);
	int i;
	int temp;
	for (i = n; i >= 2; --i) {
		// getting the largest element from the root
		temp = array[1];
		// copying the last element from the heap root
		array[1] = array[i];
		// adjust root
		adjust(array, 1, i-1);
		// place the largest element thet we just deleted into the index i
		array[i] = temp;
	} 
}

void heapify(int array[], int n) {
	int i;
	for (i = n/2; i >= 1; --i) {
		adjust(array, i, n);
	}
}

int main() {

	return 0;
}





















