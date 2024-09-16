/*
hashing is a searching technick which takes constant time 
in hashing table the formala is h(ki)=ki%m;
m is a size of the keys/elements that we are going to store in the table 
**** cologen***
if using using formula when more than one key has the same index it is called 
cologen
-> the method to resolve these type of cologen there are two technick
                open hashing(closed addressing)
                            ||
                           chaining

                closed hashing(open addressing)
                            || 
            ------------------------------------
            ||              ||                || 
     liner probing     quadratic        double hashing
                        probing            

******chaining method******
in chaining method when cologen happens the elements are store in linked list
******liner probing*******
in liner probing when cologen happens the elements are store in the next free block/space 
definition-> insert key at first free location (u+i)%m where i=0 to (m-1)
here u is the location and, m is the size of the hash, i is the index. 
*****quadratic probing******
definition-> insert key at first free location (u+i^2)%m where i=0 to (m-1)
*****double hashing*********
here 2 hash functions are given 
if the cologen occers insert at first free positoin from (u+v*i)%m where i=0 to (m-1)
where v is calaculated using second hash funtion
v=h2(k)%m  
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Structure for each node in the hash table
struct Node {
    int key;
    int value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to calculate the hash value
int hashCode(int key) {
    return key % SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct Node** hashTable, int key, int value) {
    int hashIndex = hashCode(key);
    struct Node* newNode = createNode(key, value);

    // If the bucket is empty, insert the node as the first element
    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newNode;
    }
    // If the bucket is not empty, append the node at the end of the linked list
    else {
        struct Node* temp = hashTable[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a key in the hash table and return its value
int search(struct Node** hashTable, int key) {
    int hashIndex = hashCode(key);
    struct Node* temp = hashTable[hashIndex];

    // Traverse through the linked list until the key is found
    while (temp != NULL) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }

    // If the key is not found, return -1
    return -1;
}

// Function to display the hash table
void display(struct Node** hashTable) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("(%d, %d) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Create the hash table array
    struct Node** hashTable = (struct Node**)malloc(SIZE * sizeof(struct Node*));
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert key-value pairs into the hash table
    insert(hashTable, 2, 10);
    insert(hashTable, 12, 5);
    insert(hashTable, 22, 6);
    insert(hashTable, 32, 15);
    insert(hashTable, 42, 25);

    // Display the hash table
    display(hashTable);

    // Search for a key and display its value
    int keyToSearch = 32;
    int value = search(hashTable, keyToSearch);
    if (value != -1)
        printf("\nValue for key %d is %d\n", keyToSearch, value);
    else
        printf("\nKey %d not found\n", keyToSearch);

    // Free allocated memory
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            struct Node* prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(hashTable);

    return 0;
}
