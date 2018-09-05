#include <stdio.h>

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};

void print_list(struct Node *linked) {
	struct Node *start = linked;
	while (start != NULL) {
		printf("%d\n", start->data);
		start = start->next;
	}
}

void front_insert_node(struct Node *head, struct Node *newNode) {
	newNode->next = head;
	head->prev = newNode;
}
void back_insert_node(struct Node *back, struct Node *newNode) {
	back->next = newNode;
	newNode->prev = back;
}
void front_delete_node(struct Node *head, int index) {
	struct Node *cursor = head;
	for (int i=0; i<index; i++) {
		cursor = cursor->next;
	}
	
	cursor->prev->next = cursor->next;
	cursor->next->prev = cursor->prev;
}
void back_delete_node(struct Node *back, int index) {
	struct Node *cursor = back;
	for (int i=0; i<index; i++) {
		cursor = cursor->prev;
	}
	
	cursor->prev->next = cursor->next;
	cursor->next->prev = cursor->prev;
}



int main() { 

	/* Testing insertion to head */
	struct Node node1 = {.data = 56, .prev = (struct Node *) NULL, .next = (struct Node *) NULL};
	struct Node node2 = {.data = 57, .prev = (struct Node *) NULL, .next = (struct Node *) NULL};
	struct Node node3 = {.data = 58, .prev = (struct Node *) NULL, .next = (struct Node *) NULL};
	struct Node node4 = {.data = 59, .prev = (struct Node *) NULL, .next = (struct Node *) NULL};
	front_insert_node(&node4, &node3);	
	front_insert_node(&node3, &node2);	
	front_insert_node(&node2, &node1);	
	print_list(&node1);

	printf("---\n");

	/* Testing insertion to tail */
	struct Node node5 = {.data = 60, .prev = (struct Node *) NULL, .next = (struct Node *) NULL};
	struct Node node6 = {.data = 61, .prev = (struct Node *) NULL, .next = (struct Node *) NULL};
	struct Node node7 = {.data = 62, .prev = (struct Node *) NULL, .next = (struct Node *) NULL};
	struct Node node8 = {.data = 63, .prev = (struct Node *) NULL, .next = (struct Node *) NULL};
	back_insert_node(&node4, &node5);
	back_insert_node(&node5, &node6);	
	back_insert_node(&node6, &node7);	
	back_insert_node(&node7, &node8);	
	print_list(&node1);

	front_delete_node(&node8, 3);
	back_delete_node(&node8, 3);
	printf("---\n");
	print_list(&node1);
}