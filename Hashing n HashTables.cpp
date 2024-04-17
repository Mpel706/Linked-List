#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash Table -> Key untuk menentukan index

// Collision:
// 1. Opened Address: Linear Packing
// 2. Closed Address: Chaining 

// Linear Probing

const int tableSize = 10;
struct hashNode{
	char key[100];
	int value;
};

int convertStringToInt(char *key){
	int ascii = 0;
	int i;
	for(i = 0; i < strlen(key); i++){
		ascii += key[i];
	}
	
	return ascii;
}

int hashFunctionDivision(int keyInt){
	return keyInt % tableSize;
}

void insert(char *key, int value, struct hashNode *hashTable[]){
	struct hashNode *newNode = (struct hashNode*)malloc(sizeof(struct hashNode));
	strcpy(newNode->key, key);
	newNode->value = value;
	
	int keyInt = convertStringToInt(key);
	int index = hashFunctionDivision(keyInt);
	
	while(hashTable[index] != NULL){
		index++; //check mungkin kurang
	}
	hashTable[index] = newNode;
}

void show(struct hashNode *hashTable[]){
	int i;
	for(i = 0; i < tableSize; i++){
		printf("[%d]", i);
		if(hashTable[i] != NULL){
			printf("Key: %s, Value %d\n", hashTable[i]->key, hashTable[i]->value);
		} else{
			printf("NULL\n");
		}
	}
}

void retrieve(char *key, struct hashNode *hashTable[]){
	int keyInt = convertStringToInt(key);
	int index = hashFunctionDivision(keyInt);
	printf("%d", index);
	
	if(hashTable[index] == NULL){
		printf("\n %s Nein Found", key);
	} else{
		while(hashTable[index] != NULL){
			if(strcmp(hashTable[index]->key, key) == 0){
				printf("\n\n%s is found. Value is %d", hashTable[index]->key, hashTable[index]->value);
				break;
			}
			index++;
		}
	}
	
	// function pass-by-value
	//                  reference
	//                  address
}

int main(){
	
	struct hashNode *hashTable[tableSize];
	int i;
	for(i = 0; i < tableSize; i++){
		hashTable[i] = NULL;	
	}
	
	insert("Arif", 10, hashTable);
	insert("Budi", 11, hashTable);
	insert("Citra", 12, hashTable);
	insert("Dwi", 13, hashTable);
	insert("Fajar", 14, hashTable);
	insert("Eka", 15, hashTable);
	insert("Indah", 16, hashTable);
	insert("Kurniawan", 17, hashTable);
	
	show(hashTable);
	
	retrieve("Dwi", hashTable);
	
	return 0;
}
