#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct definition for a node
typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct DblList{
	struct Node *head;
	struct Node *tail;
	int nodeCount;
}DblList;

// function prototypes
void initList(DblList *lstPtr);

void addFirst(DblList *lstPtr, int data);

void addLast(DblList *lstPtr, int data);

int loadFromFile(DblList *lstPtr, char *fileName);

void createListFromRandomNumber(DblList *lstPtr, int n);

void printListDetail(DblList *list);

void printForward(DblList *lstPtr);

void printReverse(DblList *lstPtr);

Node* find(DblList *lstPtr, int target);

int insertAfter(DblList *lstPtr, int target, int data);

int insertBefore(DblList *lstPtr, int target, int data);

int deleteFirst(DblList *lstPtr);

int deleteLast(DblList *lstPtr);

int deleteTarget(DblList *lstPtr, int target);

void menu();

// initialize linked list
void initList(DblList *lstPtr) {
	lstPtr->head = NULL;
	lstPtr->tail = NULL;
	lstPtr->nodeCount = 0;
}

void addFirst(DblList *lstPtr, int data) {
	/*
		1. Create the new node dynamically using malloc.
		2. Assign the node content with data.
		3. Initialize the prev and next pointer with NULL.
		4. 	IF THE nodeCount = 0 then
					head = tail = assign the address of the new node
				ELSE
					p->NEXT = HEAD;
					HEAD->PREV = p;
					HEAD = p;
				END IF
	*/
	Node *p = (Node *) malloc(sizeof(Node));
	if (p == NULL) {
		printf("Unable to create nde for the double linked list\n");
		return;
	}
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
	if (lstPtr->nodeCount == 0) {
		lstPtr->head = p;
		lstPtr->tail = p;
	} else {
		p->next = lstPtr->head;
		lstPtr->head->prev = p;
		lstPtr->head = p;
	}
	lstPtr->nodeCount++;
}

void addLast(DblList *lstPtr, int data) {
  Node *p = (Node *) malloc(sizeof(Node));
  if (p == NULL) {
    printf("Unable to create nde for the double linked list\n");
    return;
  }
  p->data = data;
  p->next = NULL;
  p->prev = NULL;
  if (lstPtr->nodeCount == 0) {
    lstPtr->head = p;
    lstPtr->tail = p;
  } else {
		p->prev = lstPtr->tail;
		lstPtr->tail->next = p;
		lstPtr->tail = p;
  }
  lstPtr->nodeCount++;
}

void printForward(DblList *lstPtr) {
	Node *p = lstPtr->head;
	if (p == NULL) {
		printf("LinkedList is empty\n");
		return;
	}

	printf("Content of the double linkedlist: \n");
	while(p != NULL) {
		printf("%4d", p->data);
		p = p->next;
	}
	printf("\n-- End --\n");	
}

void printReverse(DblList *lstPtr) {
	Node *p = lstPtr->tail;
	if (p == NULL) {
		printf("LinkedList is empty\n");
		return;
	}
	
	printf("Content of the double linkedlist in the reverse order: \n");
	while(p != NULL) {
		printf("%4d", p->data);
		p = p->prev;
	}
	printf("\n-- End --\n");
}

Node* find(DblList *lstPtr, int target) {
	Node *p;
	for (p = lstPtr->head; p != NULL; p = p->next) {
		if (p->data == target) {
			return p;
		}
	}
	return NULL;
}

int insertAfter(DblList *lstPtr, int target, int data) {
	Node *p = find(lstPtr, target);
	if (p == NULL) {
		return 0;
	}
	// CASE 1
	if (p == lstPtr->tail) {
		addLast(lstPtr, data);
	} else {
		// CASE 2
		Node *q = (Node *)malloc(sizeof(Node));
		q->data = data;
		// No space for new NODE	
		if (q == NULL) {
			printf("Unable to create node\n");
			return 0;
		}
		// I cannot use tail for instance because it is not necessary we insert to second to last element
		q->next = p->next;
		q->prev = p;
		p->next = q;
		(q->next)->prev = q;	
	}
	// Do not forget to increment counter
	lstPtr->nodeCount++;
	return 1;
}

int insertBefore(DblList *lstPtr, int target, int data) {
	Node *p = find(lstPtr, target);
	if (p == NULL) {
		return 0;
	}
	// CASE 1: p = lstPtr->head addFirst
	if (p == lstPtr->head) {
		addFirst(lstPtr, data);
	} else {
		// CASE 2
		// Create new NODE
		Node *q = (Node *)malloc(sizeof(Node));
		q->data = data;
		// No space
		if (q == NULL) {
			printf("Unable to create node\n");
			return 0;
		}
		q->prev = p->prev;
		q->next = p;
		p->prev = q;
		q->prev->next = q;
	}
	// increment counter
	lstPtr->nodeCount++;
	return 1;
}

int deleteFirst(DblList *lstPtr) {
	if (lstPtr->nodeCount == 0) {
		return 0;
	}
	// CASE-1 only one NODE
	Node *p = lstPtr->head;
	if (lstPtr->nodeCount == 1) {
		lstPtr->head = NULL;
		lstPtr->tail = NULL;
	} else {
		// CASE-2 many NODES
		lstPtr->head = lstPtr->head->next;
		lstPtr->head->prev = NULL;
	}
	free(p);
	lstPtr->nodeCount--;
	return 1;
}

int deleteLast(DblList *lstPtr) {
	if (lstPtr->nodeCount == 0) {
		return 0;
	}	
	Node *p = lstPtr->tail;
	if (lstPtr->nodeCount == 1) {
		lstPtr->head = NULL;
		lstPtr->tail = NULL;
	} else {
		lstPtr->tail = lstPtr->tail->prev;
		lstPtr->tail->next = NULL;
	}
	free(p);
	lstPtr->nodeCount--;
	return 1;
}

int deleteTarget(DblList *lstPtr, int target) {
	Node *p = find(lstPtr, target);
	if (p == NULL) {
		return 0;
	}
	// CASE-1 target is first NODE
	if (p == lstPtr->head) {
		return deleteFirst(lstPtr);
	}
	// CASE-2 target is last NODE
	else if (p == lstPtr->tail) {
		return deleteLast(lstPtr);
	}
	else {
		p->next->prev = p->prev;
		p->prev->next = p->next;
	}
	free(p);
	lstPtr->nodeCount--;
	return 1;
}

int loadFromFile(DblList *lstPtr, char *fileName) {
	FILE *inputFile = fopen(fileName, "r");
  if (inputFile == NULL) {
  	return 0;
  }
  int data;
  fscanf(inputFile, "%d", &data);
  while(!feof(inputFile)) {
  	addLast(lstPtr, data);
    fscanf(inputFile, "%d", &data);
  }
  fclose(inputFile);
  return 1;
}

void createListFromRandomNumbers(DblList *lstPtr, int n) {
  int i;
  srand(time(NULL));
  for (i = 1; i <= n; ++i) {
    int k = rand() % 1000;
    addLast(lstPtr, k);
  }
}

void menu() {
	printf("	Doubly Linked List Operations\n	");
	printf("-----------------------------------\n");
	printf("1. Load from file\n");
	printf("2. Create list with random numbers\n");
	printf("3. Add first\n");
	printf("4. Add last\n");
	printf("5. Print List (detail)\n");
	printf("6. Print List first to last (data only)\n");
	printf("7. Print List last to first (data only)\n");
	printf("8. Find\n");
	printf("9. Insert After\n");
	printf("10. Insert Before\n");
	printf("11. Delete first\n");
	printf("12. Delete last\n");
	printf("13. Delete a target node\n");
	printf("14. Quit\n");
}	

int main() {
	DblList list;
	initList(&list);
	int choice;
	menu();
	int quit = 0;
	int data, n, target;
	int success;
	Node *current = NULL, *prev = NULL;
	while(!quit) {
	printf("Please input your choices: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
            success = loadFromFile(&list, "data.txt");
            if (success == 1) {
              printf("File has been loaded successfully\n");
            } else {
              printf("There was some error while loading and creating the list\n");
            }
            break;
      case 2:
            printf("Enter number of integers to be generated and added into the list: ");
            scanf("%d", &n);
            createListFromRandomNumbers(&list, n);
            break;
      case 3:
            // ask to input
            printf("Input data to insert at head: ");
            scanf("%d", &data);
            addFirst(&list, data);
            break;
			case 4:
            printf("Input data to insert at tail: ");
            scanf("%d", &data);
            addLast(&list, data);
            break;
      case 5:
            // printListDetail(&list);
            break;
      case 6:
            printForward(&list);
            break;
			case 7:
						printReverse(&list);
						break;
			case 8:
						// call find
						printf("Enter target");
						scanf("%d", &target);
						current = find(&list, target);
						if (current == NULL) {
							printf("LinkedList does not contain the target specified\n");
						} else {
							printf("Target exists in the linkedlist\n");
						}
						break;
			case 9:
						printf("Enter target: ");
						scanf("%d", &target);
						printf("Input data: ");
						scanf("%d", &data);	
						if (insertAfter(&list, target, data) == 1) {
							printf("Insert after was successful\n");
						}	else {
							printf("Insert after failed\n");
						}
						break;
      case 10:
            printf("Enter target: ");
            scanf("%d", &target);
            printf("Input data: ");
            scanf("%d", &data);
            if (insertBefore(&list, target, data) == 1) {
              printf("Insert before was successful\n");
            } else {
              printf("Insert before failed\n");
            }
            break;
			case 11:
						if (deleteFirst(&list)) {
							printf("First node deleted successfully\n");
						} else {
							printf("Unable to delete first node\n");
						}
						break;
			case 12:
						if (deleteLast(&list)) {
							printf("Last node deleted successfully\n");
						} else {
							printf("Unable to delete last node\n");
						}
						break;
			case 13:
						printf("Enter target: ");
						scanf("%d", &target);
						if (deleteTarget(&list,target)) {
							printf("Target node deleted successfully\n");
						} else {
							printf("Unable to delete the target node\n");
						}
						break;
      case 14:
            quit = 1;
            break;
      default:
            printf("Invalid operation");

    }
  }
  return 0;
}























