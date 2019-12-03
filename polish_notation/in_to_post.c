#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

typedef struct {
	char item[SIZE];
	int top;
}OperatorStack;

// function prototypes

// function for operator stack operations
void opr_push(OperatorStack *, char);
char opr_pop(OperatorStack *);
int isEmpty(OperatorStack *);

// push operation
void opr_push(OperatorStack *sp, char v) {
	// checking overflow
	if (sp->top == SIZE-1) {
		printf("Stack overflow, terminating program\n");
		exit(1);
	}

	// otherwise push
	sp->item[++sp->top] = v;
}

// pop operation
char opr_pop(OperatorStack *sp) {
	if (isEmpty(sp)) {
		printf("Stack undeflow, terminating program\n");
		exit(1);
	}
	return sp->item[sp->top--];
}

// returns 1 if the stack is empty, 0 otherwise
int isEmpty(OperatorStack *sp) {
	return sp->top == -1;
}

/**
	prcd(op, '(') = FALSE
	prcd('(', op) = FALSE
	prcd(op, ')') = TRUE, except op = '('
	prcd('(', ')') = FALSE, instead of PUSH we will pop
*/

int prcd(char left, char right) {
	if (left == '(' || right == '(') 
		return 0;
	if (right == ')')
		return 1;

	if (left == '*' || left == '/') {
		if (right == '*' || right == '/' || right == '+' || right == '-')
			return 1;
		else
			return 0;
	}
	if (left == '+' || left == '-') {
		if (right == '+' || right == '-') 
			return 1;
		else
			return 0;
	}
	if (left == '$') {
		return 1;
	}
	else 
		return 0;
}

/*
	conversion: converts the supplied infix string to postfix string and assigns that
	postfix string to the postfix array supplied as parameter
*/
void convert(char infix[], char postfix[]) {
	OperatorStack stack;
	stack.top = -1;
	int i, j;
	i = 0;
	j = 0;
	while(infix[i] != '\0') {
		char token = infix[i];
		// if the token is an operand
		if (token >= '0' && token <= '9') {
			postfix[j++] = token;
		}
		// if the token is an operator
		else if (token == '+' || token == '-' || token == '/' || token == '*' || token == '$' || token == '(' || token == ')') {
			while(stack.top != -1 && prcd(stack.item[stack.top], token)) {
				char top_opr = opr_pop(&stack);
				postfix[j++] = top_opr;
			}
			if (token == ')') {
				opr_pop(&stack);
			}
			else {
				opr_push(&stack, token);
			}
		}
		else {
			printf("Invalid stmbol %c encountered\n", token);
			exit(1);
		}
		i++;	
	}	// end of the outer while

	while(stack.top != -1) {
		char top_opr = opr_pop(&stack);
		postfix[j++] = top_opr;
	}
	postfix[j] = '\0';
}


int main() {
	char infix[SIZE];
	char postfix[SIZE];

	printf("Input infix: ");
	scanf("%s", infix);

	convert(infix, postfix);
	printf("The equivalent postfix %s\n", postfix);

	return 0;
}









































