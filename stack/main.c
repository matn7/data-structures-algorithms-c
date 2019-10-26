#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
  int *item; // For the array to be dynamically allocated we need to have a pointer to hold the base
  // address of the array, also since the size will be different for different instances of Stack so
  // we need to keep the size inside the struct object
  int top;
  int size;
}Stack;

// prototype declarations
void init(Stack *, int);
void push(Stack *, int);
int pop(Stack *);
void deallocate(Stack *);
int isUnderflow(Stack *);
int isOverflow(Stack *);

int getSize(Stack *);

void printBinary(unsigned int);
// 10 -> to binary
// 10 / 2 = 5 reminder 0 (push 0 to stack)
// 5 / 2  = 2 reminder 1 (push 1 to stack)
// 2 / 2  = 1 reminder 0 (push 0 to stack)
// 1 / 2  = 0 reminder 1 (push 1 to stack)
// print content of stack

int getSize(Stack *sp) {
  return sp->size;
}

void push(Stack *sp, int value) {
  if (isOverflow(sp)) {
    int *temp;
    temp = (int *)malloc(sizeof(int) * sp->size * 2);
    if (temp == NULL) { // System is not able to give us more memory
      printf("Stack overflow\n");
      return;
    }
    // Copy exisiting content to temp array
    int i;
    for (i = 0; i <= sp->top; i++) {
      temp[i] = sp->item[i];
    }
    // deallocate existing intem array
    free(sp->item);
    // point to new array
    sp->item = temp;
    // double stack size
    sp->size *= 2;
  }
  sp->top++;
  sp->item[sp->top] = value;
}

int pop(Stack *sp) {
  if (isUnderflow(sp)) {
    printf("Stack Underflow\n");
    return -9999;
  }
  int value;
  value = sp->item[sp->top];
  sp->top--;
  return value;
}

void init(Stack *sp, int size) {
  sp->top = -1;
  sp->item = (int *)malloc(sizeof(int) * size);
  if (sp->item == NULL) {
    printf("Unable to allocate memory\n");
    exit(1);
  }
  sp->size = size;
}

void deallocate(Stack *sp) {
  if (sp->item != NULL) {
    free(sp->item);
  }
  sp->top = -1;
  sp->size = 0;
}

int isOverflow(Stack *sp) {
  return sp->top == sp->size - 1;
}

int isUnderflow(Stack *sp) {
  return sp->top == -1;
}

void printBinary(unsigned int n) {
  Stack s;
  const int BASE = 2;
  int temp = n;
  init(&s, 10);
  
  while (n > 0) {
    // Calculate reminder
    int rem = n % BASE;
    // push rem on stack
    push(&s, rem);
    n /= BASE;
  }

  printf("Binary equivalent of %d is: \n", temp);
  while (!isUnderflow(&s)) {
    printf("%d", pop(&s));
  }
  // deallocate memory
  deallocate(&s);
  printf("\n");
}

int main() {
  Stack s1;
  init(&s1, 3);
  //init(&s2);
  //push(&s1, 100);
  //push(&s1, 200);

  //push(&s2, 10);
  //push(&s2, 20);

  //printf("deleted from s1 : %d\n", pop(&s1)); // 200
  //printf("deleted from s1 : %d\n", pop(&s1)); // 100

  //printf("deleted from s2 : %d\n", pop(&s2)); // 20
  //printf("deleted from s2 : %d\n", pop(&s2)); // 10

  printf("Decimal to binary equivalence\n");
  printBinary(10);
  printBinary(18);

  printf("\nPush on stack program\n");
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Exit\n");

  int choice, value;

  while(1) {
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("Size of Stack: %d\n", getSize(&s1));
    switch(choice) {
      case 1: printf("Enter value: ");
	      scanf("%d", &value);
  	      push(&s1, value);
	      break;
      case 2: 
  	      value = pop(&s1);
	      if (value != -9999) {
		printf("Popped data: %d\n", value);
	      }
	      break;
      case 3: deallocate(&s1);
              exit(0);
      default: printf("Invalid choice\n");
    }
  }

  return 0;
}



























