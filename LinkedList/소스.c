#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Node {
	struct Node* next;
	struct Node* prev;
	char element;
}Node;
typedef struct List {
	Node* head;
	Node* trail;
}List;
void Initialize(List* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->trail = (Node*)malloc(sizeof(Node));

	list->head->next = list->trail;
	list->head->prev = NULL;
	list->trail->prev = list->head;
	list->trail->next = NULL;
	list->head->element = '\0';
	list->trail->element = '\0';
	return;
}
void Add(List* list, int rank, char element) {
	Node* current = list->head;
	int i;
	for (i = 1;i < rank;i++) {
		current = current->next;
		if (current == NULL || current->next == NULL) {
			printf("invalid position\n");
			return;
		}
	}
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->element = element;
	newnode->prev = current;
	newnode->next = current->next;
	current->next->prev = newnode;
	current->next = newnode;
	return;
}
void Delete(List* list, int rank) {
	Node* current = list->head;
	int i;
	for (i = 1;i <= rank;i++) {
		current = current->next;
		if (current == NULL || current->next == NULL) {
			printf("invalid position\n");
			return;
		}
	}
	current->element = '\0';
	current->next->prev = current->prev;
	current->prev->next = current->next;
	free(current);
	return;
}
void Get(List* list, int rank) {
	Node* current = list->head;
	int i;
	for (i = 1;i <= rank;i++) {
		current = current->next;
		if (current == NULL || current->next == NULL) {
			printf("invalid position\n");
			return;
		}
	}
	printf("%c\n", current->element);
	return;
}
void Print(List* list) {
	Node* current = list->head->next;
	while (current != list->trail) {
		printf("%c", current->element);
		current = current->next;
	}
	return;
}
int main() {
	List* list = (List*)malloc(sizeof(List));
	Initialize(list);
	int N,i, rank;
	char element;
	scanf("%d", &N);
	getchar();
	char operation;
	for (i = 0;i < N;i++) {
		scanf("%c", &operation);
		getchar();
		if (operation == 'A') {
			scanf("%d", &rank);
			getchar();
			scanf("%c", &element);
			getchar();
			Add(list, rank, element);
		}
		if (operation == 'D') {
			scanf("%d", &rank);
			getchar();
			Delete(list, rank);
		}
		if (operation == 'G') {
			scanf("%d", &rank);
			getchar();
			Get(list, rank);
		}
		if (operation == 'P') {
			Print(list);
		}
	}
	return 0;
}