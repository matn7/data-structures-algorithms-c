#include <stdio.h>

#define LENGTH 3

char* words[LENGTH];

int main(int argc, char **argv) {
	char *pc;		// a pointer to a char
	char **ppc;	// a pointer to a pointer to a char

	printf("multiple indirection example\n");

	// initialize integer array
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";

	for (int i = 0; i < LENGTH; i++) {
		printf("%s\n", words[i]);
	}

	// B: Pointer to an array of strings the same as a pointer to pointer to character
	printf("\nNow print the characters in each string ...\n");
	ppc = words;
	for (int i = 0; i < LENGTH; i++) {
		ppc = words + i;
		pc = *ppc;
		while (*pc != 0) {
			printf("%c ", *pc);
			pc += 1;
		}
		printf("\n");
	}

	return 0;
}
