#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* s;
	int* p;
	int i;

	// use malloc first to allocate some memory and see what is in it
	s = (char*)malloc(6 * sizeof(char));		// malloc will return NULL (0) is it fails
	for (i = 0; i < 6; i++) {
		printf("s[%d]=%d\n", i, s[i]);
	}
	free(s);		// use 'free' to return memory
	printf("\n");

	// now we'll use calloc to do the same - note that the memory is 'zeroed out'
	s = (char*)calloc(6, sizeof(char));	// calloc will return 0 if it fails
	for (i = 0; i < 6; i++) {
		printf("s[%d]=%d\n",i, s[i]);
	}	
	free(s);
	printf("\n");

	p = (int*)calloc(6, sizeof(int));
	for (i = 0; i < 6; i++) {
		printf("p[%d]=%d\n", i, p[i]);
	}
	free(p);

	return 0;
}
