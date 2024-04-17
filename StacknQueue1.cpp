/*

Stack = analogi cuci piring, piring paling atas cuci pertama (LIFO)
Cara
1. Array, size static2. Linked list, dynamic allocation

Analogi
TOP = NULL (-1) --> Stack is empty
TOP = MAX - 1 --> Stack is full
Misal, MAX = 4, kalau top di index 4-1 = 3, data baru udah gabisa masuk
TOP tugasnya menyimpan index (data baru terakhir disimpan)

Misal
STEP 1
	TOP
	 A   , mau ditambahkan B
	 
STEP 2
	TOP
	 A   B 

dst...

*/ 

#include <stdio.h>
#define MAX 4
int top = -1; // belum punya top (inisialisasi)
int stackArray[MAX]; // sampai indeks 4 aja

void push (int data) {
	if (top == MAX - 1) {
		printf ("Stack is Full\n\n");
		return;
	}
	top = top + 1;
	stackArray[top] = data;
}

void printStack () {
	for (int i = top; i >= 0; i--) {
		printf ("%d\n", stackArray[i]);
	}	
}

void pop () { // pop index ter atas
//	stack_array[top] = "";
	printf ("Element to be deleted: %d\n", stackArray[top]);
		top = top - 1; // nge pop 2x			
}

void peek () {
	printf ("\nElement at the top of stack: %d\n", stackArray[top]);
}
int main () {							
	push(1);
	push(2);
	push(3);
	push(4);
	push(5); // ga keinsert soalnya udah define MAX = 4 [FAILED, STACK FULL]
	printStack(); // output = 4 3 2 1 
	
	puts(" ");
	
	// delete top element
	pop();
	printStack(); // output = 3 2 1
	peek();
	return 0;
}



