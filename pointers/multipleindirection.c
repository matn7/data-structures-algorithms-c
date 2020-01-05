#include <stdio.h>

#define LENGTH 4

int data[LENGTH];

int main(int argc, char **argv) {
	int *pi;		// a pointer to an integer
	int **ppi;	// a pointer to a pointer to an integer

	printf("multiple indirection example\n");

	// initialize integer array
	for (int i = 0; i < LENGTH; i++) {
		data[i] = i;
	}

	for (int i = 0; i < LENGTH; i++) {
		printf("%d\n", data[i]);
	}

	// A: simple pointer to a pointer to an integer
	pi = data;		// set the pointer to an integer to the start of the data array
	ppi = &pi;		// and set the pointer to a pointer to pi itself

	for (int i = 0; i < LENGTH; i++) {
		printf("\nLoop[%d] array address is %p\n", i, data);
		printf("item pointed to by pi is %d\n", *pi);
		printf("item pointed to by ppi is %p\n", *ppi);
		printf("item pointed to by double indirection of ppi is %d\n\n", **ppi);
		printf("The address of pi is %p and the value of pi is %p\n\n", &pi, ppi);
		printf("The value of pi is %p and it points to %d\n\n", pi, *pi);
	
		pi += 1;	// advance the pointer to point to the next element of the data array
	}

	return 0;
}
