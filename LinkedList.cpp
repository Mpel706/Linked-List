#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	int age;
	struct data *next;
};

struct data *createNode(int age){
	// Dynamic memory allocation
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->age = age;
	
	return newNode;
}

struct data *pushTail(struct data *head, int age){
	struct data *newNode = createNode(age);
	struct data *temp;
	temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}

struct data *pushHead(struct data *head, int age){
	struct data *newNode = createNode(age);
	newNode->next = head;
	
	return head = newNode;
}

struct data *pushMid(struct data *head, int age, int position){
	struct data *newNode = createNode(age);
	struct data *temp, *prev;
	temp = head;
	int count = 1;

	while (count < position && temp != NULL){
		prev = temp;
		temp = temp->next;
		count++;
	}

	if (temp == NULL && count < position) {
		free(newNode);
		return head;
	}

	newNode->next = temp;
	prev->next = newNode;

	return head;
}

// delete node
struct data *popHead(struct data *head){
	struct data *temp;
	temp = head;
	head = head->next;
	temp->next = NULL;
	free(temp);
	
	return head;
}

struct data *popTail (struct data *head){
	struct data *temp;
	struct data *curr;
	temp = head;
	curr = head;
	
	while(curr->next != NULL){
		temp = curr;
		curr = curr->next;
	}
	temp->next = NULL;
	free(curr);
	
	return head;
}

struct data *popSearch(struct data *head, int age){
	struct data *temp, *prev;
	temp = head;
	prev = NULL;

	while (temp != NULL && temp->age != age){
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL){
		return head;
	}

	if (prev == NULL){
		head = head->next;
	} else {
		prev->next = temp->next;
	}

	free(temp);
	return head;
}

void printLinkedList(struct data *head){
	struct data *temp;
	temp = head;
	int count = 1;
	while(temp != NULL){
		printf("Data ke-%d: %d\n", count, temp->age);
		temp = temp->next;
		count++;
	}
}

int main(){
	struct data *head = NULL;
	head = createNode(10);
	head = pushTail(head, 20);
	head = pushHead(head, 5);
	
	head = pushMid(head, 15, 2);
	head = popSearch(head, 15);
	
//	head = popHead(head);
//	head = popTail(head);
	
	printLinkedList(head);
	
	return 0;
}
