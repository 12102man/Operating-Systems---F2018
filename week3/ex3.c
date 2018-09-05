#include <stdio.h>

struct Node
{
	int data;
	struct Node *p;
};

void print_list(struct Node *linked) {
	struct Node *start = linked;
	while (start != NULL) {
		printf("%d\n", start->data);
		start = start->p;
	}
}

void insert_node(struct Node *linked, struct Node *newNode) {
	struct Node *start = linked;
	while (start->p != NULL) {
		start = start->p;
	}
	start->p = newNode;
}

void delete_node(struct Node *linked, struct Node *toDelete) {
	struct Node *start = linked;
	while (start->p != toDelete) {
		start = start->p;
	}
	start->p = toDelete->p;
}


int main() {
	struct Node linkedList = {.data = 7, .p = (struct Node *) NULL};
	struct Node node1 = {.data = 56, .p = (struct Node *) NULL};
	struct Node node2 = {.data = 57, .p = (struct Node *) NULL};
	struct Node node3 = {.data = 58, .p = (struct Node *) NULL};
	insert_node(&linkedList, &node1);	
	insert_node(&linkedList, &node2);	
	insert_node(&linkedList, &node3);	
	print_list(&linkedList);
	printf("----\n");
	delete_node(&linkedList, &node2);
	print_list(&linkedList);
}