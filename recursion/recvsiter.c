#include <stdio.h>
#include <stdlib.h>

void fun2() {

}

void fun1() {
	// OS creates stack
	int i = 5, j = 10;
	fun2();
}

int main() {
	int x[] = {1,2,3};
	int p = 0;
	char str[] = "Hello";

	fun1();

	// want to preserve state information after fun1() x, p, str, OS puts them into stack

	printf("%d %s\n", x[p], str);

	// do not want to preserve info after fun1() x, p, str, OS do not push them into stack
	// printf("%d %s\n", x[p], str);

	return 0;
}


// STACK
// --------------
// 
// --------------
// fun1, i, j
// --------------
// main, p,x, str
// --------------
