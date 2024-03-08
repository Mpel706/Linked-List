#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data {
	int priority;
	char name[100];
	struct data *next;
};

struct data *createNode(int priority, char name[100]){
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->next = NULL;
	node->priority = priority;
	strcpy(node->name, name);
	
	return node;
}

void printQueue(struct data *head){
	struct data *temp = head;
	while(temp != NULL){
		printf("%d: %s -> ", temp->priority, temp->name);
		temp = temp->next;
	}
}

struct data *push(struct data *head, int priority, char name[100]){
	struct data *node = createNode(priority, name);
	struct data *temp = head;
	
	while(temp->next->priority <= priority){
		temp = temp->next;
		if(temp->next == NULL)
		   break;
	}
	node->next = temp->next;
	temp->next = node;
	
	return head;
}

struct data *pop(struct data *head){
	struct data *temp = head;
	head = head->next;
	free(temp);
	
	return head;
}

int main(){
	struct data *head = createNode(1, "alpha");
	
	struct data *newNode = createNode(2, "bravo");
	head->next = newNode;
	
	struct data *newNode2 = createNode(3, "charlie");
	newNode->next = newNode2;
	printQueue(head);
	
	head = push(head, 2, "delta");
	printf("\n");
	printQueue(head);
	
	head = pop(head);
	printf("\n");
	printQueue(head);
		
	return 0;
	
}
