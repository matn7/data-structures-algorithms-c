#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  char *item; 
  int top;
  int size;
}Stack;

// Prototype declarations
void init(Stack *, int);
void push(Stack *, char);
char pop(Stack *);
void deallocate(Stack *);
int isUnderflow(Stack *);
int isOverflow(Stack *);
int getSize(Stack *);



int getSize(Stack *sp) {
  return sp->size;
}

void push(Stack *sp, char value) {
  if (isOverflow(sp)) {
    char *temp;
    temp = (char *)malloc(sizeof(char) * sp->size * 2);
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

char pop(Stack *sp) {
  if (isUnderflow(sp)) {
    printf("Stack Underflow\n");
    return '\0';
  }
  char value;
  value = sp->item[sp->top];
  sp->top--;
  return value;
}

void init(Stack *sp, int size) {
  sp->top = -1;
  sp->item = (char *)malloc(sizeof(char) * size);
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

int reverseIt(char source[], char dest[]) {
  FILE *fps, *fpd;
  const int SIZE = 50;
  fps = fopen(source, "r");
  if (fps == NULL) {
    printf("Error opening file %s\n", source);
    return 0;
  }
  fpd = fopen(dest, "w");
  if (fpd == NULL) {
    printf("Error opening file %s\n", dest);
    return 0;
  }
  Stack s;
  init(&s, SIZE);
  char buff;
  buff = fgetc(fps);
  while (!feof(fps)) {
    push(&s, buff);
    buff = fgetc(fps);
  }

  while (!isUnderflow(&s)) {
    fputc(pop(&s), fpd);
  }
  fclose(fps);
  fclose(fpd);
  deallocate(&s);
  return 1;
}

int main() {

  int f = reverseIt("/home/matikomp/udemy_courses/C/stack/input_text.txt", "/home/matikomp/udemy_courses/C/stack/rev_text.txt");

  if (f) {
    printf("File copied successfully\n");
  } else {
    printf("Error -- copy failed\n");
  }

  return 0;
}



























