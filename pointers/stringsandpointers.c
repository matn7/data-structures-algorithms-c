#include <stdio.h>

int main(int argc, char **argv) {
	char str1[] = "Hello world";
	printf("%s %c %p %p %s\n", str1, str1[0], &str1, &str1[0], str1);
	return 0;
}
