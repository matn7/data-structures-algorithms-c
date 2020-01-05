#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXSTRLEN 100

char * string_function(char *astring) {
	char* s;
	// malloc allocates memory on the HEAP
	// local variables declared inside a function are allocated memory in STACK
	// when exit function variables on a STACK are cleaned up
	// variables stored at HEAP exists after function when there were allocated
	s = (char*)malloc(MAXSTRLEN);
	s[0] = 0;	// need this to initialize the buffer created by malloc
	strcat(s, "Hello ");
	strcat(s, astring);
	strcat(s, "\n");
	return s;
}

int main(int argc, char **argv) {
	printf(string_function("Fred"));
	printf(string_function("Mike Tyson"));
	return 0;
}
