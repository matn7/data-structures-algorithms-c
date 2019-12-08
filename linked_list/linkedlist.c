#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct LinkedList {
	struct Node *head;
	struct Node *tail;
	int nodeCount;
}LinkedList;

// function prototypes
void initList(LinkedList *);
int loadFromFile(LinkedList *, char *);
void createListFromRandomNumbers(LinkedList *, int);
void insertAtHead(LinkedList *, int);

// for queue will be equivalent to insertQueue operation
void insertAtTail(LinkedList *, int);
void printListDetail(LinkedList *);
void printList(LinkedList *);
Node * find(LinkedList *, int, Node **);

// for queue will be equivalent to deleteQueue operation 
int deleteFirst(LinkedList *);
int deleteLast(LinkedList *);
int deleteTarget(LinkedList *, int);
void reverse(LinkedList *);

void printListForward(LinkedList *);
void printListReverse(LinkedList *);

void printRecForward(Node *);
void printRecReverse(Node *);

// for stack
void push(LinkedList *, int);
int pop(LinkedList *);

void menu() {
	printf("		Singly Linked List Operations\n");
	printf("---------------------------------\n");
	printf("1. Load from file\n");
	printf("2. Create list with random numbers\n");
	printf("3. Insert at head\n");
	printf("4. Insert at tail\n");
	printf("5. Print List detail\n");
	printf("6. Print List data only\n");
	printf("7. Find\n");
	printf("8. Delete first\n");
	printf("9. Delete last\n");
	printf("10. Delete a target node\n");
	printf("11. Reverse\n");
	printf("12. Quit\n");
}

void initList(LinkedList *listptr) {
	listptr->head = NULL;
	listptr->tail = NULL;
	listptr->nodeCount = 0;
}

void insertAtTail(LinkedList *listPtr, int data) {
	Node *newNodePtr = (Node *) malloc(sizeof(Node));
	if (newNodePtr == NULL) {
		printf("Unable to allocate new node\n");
		return;
	}
	newNodePtr->data = data;
	newNodePtr->next = NULL;

	if (listPtr->nodeCount == 0) {
		// this is the case when the list is empty
		listPtr->head = newNodePtr;
		listPtr->tail = newNodePtr;
	} else {
		// this is the case when the list is not empty
		listPtr->tail->next = newNodePtr;
		listPtr->tail = newNodePtr;
	}
	listPtr->nodeCount++;
}

// To add a new node at the begining of the LinkedList
// Input parameters: pointer to struct LinkedList, an integer data that will
//									 be the contant of the new node.
// Precondition: The linkedList object must exist.
// Return Value: Nothing
void insertAtHead(LinkedList *listPtr, int data) {
	Node *newNodePtr = (Node*)malloc(sizeof(Node));
	if (newNodePtr == NULL) {
		printf("Unable to allocate new node\n");
		return;
	}
	newNodePtr->data = data;
	newNodePtr->next = NULL;

	if (listPtr->nodeCount == 0) {
		// this is the case when the list is empty
		listPtr->head = newNodePtr;
		listPtr->tail = newNodePtr;
	} else {
		// this is the case when the list is not empty
		newNodePtr->next = listPtr->head;
		listPtr->head = newNodePtr;
	}
	listPtr->nodeCount++;
}

// For stack insertAtHead is push
void push(LinkedList *listPtr, int data) {
  Node *newNodePtr = (Node*)malloc(sizeof(Node));
  if (newNodePtr == NULL) {
    printf("Unable to allocate new node\n");
    return;
  }
  newNodePtr->data = data;
  newNodePtr->next = NULL;

  if (listPtr->nodeCount == 0) {
    // this is the case when the list is empty
    listPtr->head = newNodePtr;
    listPtr->tail = newNodePtr;
  } else {
    // this is the case when the list is not empty
    newNodePtr->next = listPtr->head;
    listPtr->head = newNodePtr;
  }
  listPtr->nodeCount++;
}

void printListDetail(LinkedList *lstPtr) {
	if (lstPtr->nodeCount == 0) {
		printf("Linked List is empty\n");
		return;
	}

	printf("Printing linked list in details\n");
	printf("HEAD: %p\n", lstPtr->head);

	Node *current = lstPtr->head;
	int counter = 1;
	while(current != NULL) {
		printf("%d, (%p)[%d|%p]\n", counter, current, current->data, current->next);
		current = current->next;
		counter++;
	}
	printf("TAIL: %p\n", lstPtr->tail);
}

void printList(LinkedList *lstPtr) {
	if (lstPtr->nodeCount == 0) {
		printf("Linked List is empty\n");
		return;
	}
	Node *current = lstPtr->head;
	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->next;	
	}
	
}

Node * find(LinkedList *lstPtr, int target, Node **prevPtr) {

	Node * current = lstPtr->head;
	*prevPtr = NULL;
	while(current != NULL) {
		if (current->data == target) {
			break;
		}
		*prevPtr = current;
		current = current->next;
	}
	return current;
}

int deleteTarget(LinkedList *lstPtr, int target) {
	Node *current = NULL, *prev = NULL;
	current = find(lstPtr, target, &prev);
	if (current == NULL) {
		return -9999;
	}
	int data = current->data;
	if (current == lstPtr->head) {
		// if the target is the first Node
		return deleteFirst(lstPtr);
	} else if (current == lstPtr->tail) {
		return deleteLast(lstPtr);
	} else {
		prev->next = current->next;
		free(current);
		lstPtr->nodeCount--;
		return data;
	}
}

int loadFromFile(LinkedList *lstPtr, char *fileName) {
	FILE *inputFile = fopen(fileName, "r");
	if (inputFile == NULL) {
		return 0;
	}
	int data;
	fscanf(inputFile, "%d", &data);
	while(!feof(inputFile)) {
		insertAtTail(lstPtr, data);
		fscanf(inputFile, "%d", &data);
	}
	fclose(inputFile);
	return 1;
}

void createListFromRandomNumbers(LinkedList *lstPtr, int n) {
	int i;
	srand(time(NULL));
	for (i = 1; i <= n; ++i) {
		int k = rand() % 1000;
		insertAtTail(lstPtr, k);
	}	
}

int deleteFirst(LinkedList *lstPtr) {
	if (lstPtr->nodeCount == 0) {
		return -9999;	
	}
	
	Node *first = lstPtr->head;
	int data = first->data;
	if (lstPtr->nodeCount == 1) {
		// there is only one node
		lstPtr->head = NULL;
		lstPtr->tail = NULL;
	} else {
		// there are many nodes and we need to delete the first
		lstPtr->head = first->next;
	}
	// deallocate space
	free(first);
	lstPtr->nodeCount --;
	return data;
}

// stack deleteFirst is pop
int pop(LinkedList *lstPtr) {
  if (lstPtr->nodeCount == 0) {
    return -9999;
  }

  Node *first = lstPtr->head;
  int data = first->data;
  if (lstPtr->nodeCount == 1) {
    // there is only one node
    lstPtr->head = NULL;
    lstPtr->tail = NULL;
  } else {
    // there are many nodes and we need to delete the first
    lstPtr->head = first->next;
  }
  // deallocate space
  free(first);
  lstPtr->nodeCount --;
  return data;
}


int deleteLast(LinkedList *lstPtr) {
	// if linked list is empty
	if (lstPtr->nodeCount == 0) {
		return -9999;
	}
	
	Node * current = lstPtr->head;
	Node * last = lstPtr->tail;
	int data = last->data;

	if (lstPtr->nodeCount == 1) {
		// if there is only one node, then we need to delete that node,
		// so we must assign NULL to both head and tail pointer, as the
		// linked list would be empty after this operation.
		lstPtr->head = NULL;
		lstPtr->tail = NULL;
	} else {
		// there are many nodes and we need to search for the second last node and
		// assign that to tail.
		while (current->next != lstPtr->tail) {
			current = current->next;
		}		
		lstPtr->tail = current;
		lstPtr->tail->next = NULL;
	}

	free(last);
	lstPtr->nodeCount--;
	return data;
}

void reverse(LinkedList *lstPtr) {
	if (lstPtr->nodeCount <= 1) {
		return;
	}
	// declaring 3 Node pointers for doing the reversal
	Node *p, *q, *r;

	// p is current node, q is just previous to p and r is just immediate next to p
	q = NULL;
	p = lstPtr->head;
	r = p->next;
	while (1) {
		// reverse the link
		p->next = q;
		if (p == lstPtr->tail) {
			break;
		}
		// shift the pointers towards right
		q = p;
		p = r;
		r = r->next;
	}
	lstPtr->tail = lstPtr->head;
	lstPtr->head = p;
}

void printListForward(LinkedList *lstPtr) {
	printRecForward(lstPtr->head);
}

void printListReverse(LinkedList *lstPtr) {
	printRecReverse(lstPtr->head);
}

void printRecForward(Node *p) {
	if (p == NULL) {
		return;
	}
	printf("%4d", p->data);
	printRecForward(p->next);
}

void printRecReverse(Node *p) {
	if (p == NULL) {
		return;
	}
	printRecReverse(p->next);
	printf("%4d", p->data);	
}

int main() {
	LinkedList list;
	initList(&list);

	createListFromRandomNumbers(&list, 10);
	printListForward(&list);
	printf("\n");
	printListReverse(&list);
	printf("\n");

	int choice;

	menu();

	int quit = 0;
	int data, n, target;
	int success;
	Node *current = NULL, *prev = NULL;

	while (!quit) {
		printf("Please input your choices: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1: 
						success =	loadFromFile(&list, "data.txt");
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
						insertAtHead(&list, data);
						break;
			case 4:
						printf("Input data to insert at tail: ");
						scanf("%d", &data);
						insertAtTail(&list, data);
						break;
			case 5:
						printListDetail(&list);
						break;
			case 6:
						printList(&list);
						break;
			case 7: 
						printf("Enter target to find: ");
						scanf("%d", &data);
						current = find(&list, data, &prev);
						if (current == NULL) {
							printf("Target not found in the LinkedList\n");
						} else {
							printf("Target node exists, address of the target node: %p, previous: %p\n", current, prev);
						}
						break;
			case 8: 
						data = deleteFirst(&list);
						if (data == -9999) {
							printf("LinkedList is empty\n");
						} else {
							printf("First node has been deleted, data: %d\n", data);
						}
						break;
			case 9: 
						data = deleteLast(&list);
						if (data == -9999) {
							printf("LinkedList is empty\n");
						} else {
							printf("Last node has been deleted, data: %d\n", data);
						}
						break;
			case 10: 
						printf("Enter target to find: ");
						scanf("%d", &target);
						data = deleteTarget(&list, target);
						if (data == -9999) {
							printf("Target %d does not exists in the list\n", target);
						} else {
							printf("Target node with data: %d, deleted successfully\n", data);
						}
						break;
			case 11: 
						reverse(&list);
						break;
			case 12:
						quit = 1;
						break;
			default:
						printf("Default");
					
		}
	}
	return 0;
}



























