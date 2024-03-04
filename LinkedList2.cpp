#include <stdio.h>
#include <stdlib.h>

struct data {
	int age;
	struct data *next;
	struct data *prev;
};

struct data *head = NULL;
struct data *tail = NULL;
struct data *mid = NULL;

struct data *createNode(int age){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->age = age;
	
	return newNode;
}

void printLinkedList(){
	struct data *temp;
	temp = head;
	int count = 1;
	
	while (temp!=NULL){
		printf("data ke-%d : %d\n",count, temp->age);
		temp = temp->next;
		count++;
	}
}

void pushHead(int age){
	struct data *newNode = createNode(age);
	// ambil address yang ada di head;}
	newNode->next = head;
	head->prev = newNode;
	
	head = newNode;
}

void pushTail(int age){
	struct data *newNode = createNode(age);
	
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;

}

void pushMid(int age){
	struct data *newNode = createNode(age);

	newNode->prev = mid;
	mid->next = newNode;
	mid = newNode;
}

void popHead(){
	struct data *temp;
	temp = head;
	
	head = head->next;
	head->prev = NULL;
	free(temp);
}

void popTail(){
	struct data *temp;
	temp = tail;
	
	tail = tail->prev;
	tail->next = NULL;
	
	free(temp);
}

void popMid(){
	struct data *temp;
	temp = mid;
	
	mid = mid->prev;
	mid = mid->next;
	
	mid->prev = NULL;
	
	free(temp);
}

int main(){
//	printf("double linked list");
	head = createNode(2);
	tail = createNode(5);
	mid = createNode(1);
	
	head->next = tail;
	head->prev = head;
	head->prev->next = mid;
	
	pushHead(1);
	pushHead(0);
	pushMid(1);
	pushTail(10);
	
	printLinkedList();
	
	return 0;
}
