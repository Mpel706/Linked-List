#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *rightChild;
	struct node *leftChild;
};

struct node *createNode(int data){
	struct node *newNode = (struct node *) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	
	return newNode;
}

struct node *insertion(struct node *root, int data){
	if(root == NULL){
		return createNode(data);
	}
	else if(data < root->data){
		root->leftChild = insertion(root->leftChild, data);
	}
	else {
		root->rightChild = insertion(root->rightChild, data);
	}
	return root;
}

// inorder traversal
void inorderTraversal(struct node *root){
	if(root != NULL){
		inorderTraversal(root->leftChild); // traversing left child
		printf(" %d ", root->data);
		inorderTraversal(root->rightChild); // traversing right child
	}
	
}

struct node *searching(struct node *root, int data){
	if(root == NULL || data == root->data){
		return root;
	} 
	else if (data > root->data){
		// traversing right child
		return searching(root->rightChild, data);
	}
	else{
		// traversing left child
		return searching(root->leftChild, data);
	}
}

struct node *deletion(struct node *root, int data){
	// searching node to be deleted
	if(root == NULL){
		return NULL;
	}
	if(data < root->data){
		root->leftChild = deletion(root->leftChild, data);
	}
	else if(data > root->data){
		root->rightChild = deletion(root->rightChild, data); 
	}
	else{
		// Case 1, no child node
		if(root->leftChild == NULL && root->rightChild == NULL){
			free(root);
			return NULL;
		}
		// Case 2, one child node
		else if(root->leftChild == NULL || root->rightChild == NULL){
			struct node *temp;
			if (root->leftChild == NULL){
				temp = root->rightChild;
			}
			else{
				temp = root->leftChild;
			}
			free(root);
			return temp;
		}
	}
	
	return root;
}

int main(){
	struct node *root;
	
	root = createNode(20);
	insertion(root, 5);
	insertion(root, 30);
	insertion(root, 1);
	insertion(root, 15);
	insertion(root, 9);
	insertion(root, 7);
	insertion(root, 12);
	insertion(root, 25);
	insertion(root, 40);
	insertion(root, 45);
	insertion(root, 42);
	
//	printf("%d", root->data);
//	printf(" %d ", root->leftChild->data);
//	printf("%d", root->rightChild->data);
	
	inorderTraversal(root);
	printf("\n\n");
	
//	struct node *temp = NULL;
//	temp = searching(root, 42);
//	if(temp != NULL)
//	    printf("%d", temp->data);
//	else
//	    printf("Nein found!");

    root = deletion(root, 1);
    root = deletion(root, 45);
    inorderTraversal(root);
	
	return 0;
}
