#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* s;
	int stringsize;

	stringsize = sizeof("hello");
	printf("size of 'hello' is %d\n", stringsize); // SIX bytes long (5 charc plus \0)

	s = (char*)malloc(stringsize);
	if (s == NULL) {
		printf("malloc failed!\n");
		exit(0);
	}

	// copy string into the newly allocated memory
	strncpy(s, "hello", stringsize);

	// change the first character
	printf("s is %s\n", s);
	s[0] = 'c';
	printf("s is now %s\n", s);
	free(s);
	return 0;
}
