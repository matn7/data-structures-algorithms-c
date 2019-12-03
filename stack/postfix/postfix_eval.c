#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

typedef struct {
  double item[SIZE];
  int top;
}OperandStack;

// function prototypes

// function for stack operations
void push(OperandStack *, double);
double pop(OperandStack *);
int isEmpty(OperandStack *);

// push operation
void push(OperandStack *sp, double v) {
	// checking overflow
	if (sp->top == SIZE - 1) {
		printf("Stack overflow, terminating program\n");
		exit(1);
  }
	// otherwise push
	sp->item[++sp->top] = v;
}

// pop operation
double pop(OperandStack *sp) {
	if (isEmpty(sp)) {
		printf("Stack underflow, terminating program\n");
		exit(1);
	}
	return sp->item[sp->top--];
}

// retruns 1 if the stack is empty, 0 otherwise
int isEmpty(OperandStack *sp) {
	return sp->top == -1;
}

double operate(double leftOpnd, double rightOpnd, char opr) {
	double result = 0.0;
	switch(opr) {
		case '+': result = leftOpnd + rightOpnd;
							break;
		case '-': result = leftOpnd - rightOpnd;
							break;
		case '*': result = leftOpnd * rightOpnd;
							break;
		case '/': result = leftOpnd / rightOpnd;
							break;
		case '$': result = pow(leftOpnd, rightOpnd);
							break;
		default: printf("%c is not a valid operator\n", opr);
						 exit(1);
	}
	return result;
}

double evalPostfix(char postfix[]) {
	OperandStack stack;
	stack.top = -1;
	int i = 0;
	while(postfix[i] != '\0') {
		char token = postfix[i];
		if (token >= '0' && token <= '9') {
			int v = token - '0';
			push(&stack, (double) v);
		}
		else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '$') {
			double opnd1 = pop(&stack);
			double opnd2 = pop(&stack);
			double result = operate(opnd2, opnd1, token);
			push(&stack, result);
		}
		else {
			printf("Invalid symbol encountered\n");
			exit(1);
		}
		++i;
	}
  return pop(&stack);	
}

int main() {
	char postfix[SIZE];
	printf("Input postfix expression: ");
	scanf("%s", postfix);

	double result = evalPostfix(postfix);
	printf("Result: %lf\n", result);
	return 0;
}







