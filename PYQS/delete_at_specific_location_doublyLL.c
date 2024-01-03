#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!*head) *head = newNode;
    else {
        struct Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node at a specific position in the doubly linked list
void deleteAtLocation(struct Node** head, int position) {
    if (!*head) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = *head;
    int count = 1;

    // Traverse to the specified position
    while (count < position && current != NULL) {
        current = current->next;
        count++;
    }

    // Check if the specified position is valid
    if (current == NULL) {
        printf("Position exceeds the size of the list\n");
        return;
    }

    // Adjust pointers to delete the node
    if (current->prev != NULL) current->prev->next = current->next;
    else *head = current->next;

    if (current->next != NULL) current->next->prev = current->prev;

    // Free memory of the deleted node
    free(current);
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated for the doubly linked list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;

    // Traverse the list and free memory of each node
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    // Print the doubly linked list
    printList(head);

    // Delete a node at a specific position
    deleteAtLocation(&head, 2);

    // Print the modified doubly linked list
    printList(head);

    // Free allocated memory
    freeList(&head);

    return 0;
}