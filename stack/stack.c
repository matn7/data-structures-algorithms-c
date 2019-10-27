#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
  int *item; 
  int top;
  int size;
}Stack;

// Prototype declarations
void init(Stack *, int);
void push(Stack *, int);
int pop(Stack *);
void deallocate(Stack *);
int isUnderflow(Stack *);
int isOverflow(Stack *);
int getSize(Stack *);

int getSize(Stack *sp) {
  return sp->size;
}

void push(Stack *sp, int value) {
  if (isOverflow(sp)) {
    int *temp;
    temp = (int *)malloc(sizeof(int) * sp->size * 2);
    if (temp == NULL) { 
      printf("Stack overflow\n");
      return;
    }
    int i;
    for (i = 0; i <= sp->top; i++) {
      temp[i] = sp->item[i];
    }
    free(sp->item);
    sp->item = temp;
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

int main() {
  return 0;
}



























