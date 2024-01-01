#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    // If the list is empty, make the new node the head and link it to itself
    if (!*head) *head = newNode, newNode->next = *head;
    else {
        // Traverse to the end and insert the new node
        struct Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node at a specific position in the circular linked list
void deleteAtLocation(struct Node** head, int position) {
    // If the list is empty, print a message and return
    if (!*head) return printf("List is empty\n");

    struct Node *current = *head, *previous = NULL;
    // Move to the specified position
    for (int i = 1; i < position; ++i) {
        previous = current, current = current->next;
        // If position exceeds the size of the list, print a message and return
        if (current == *head) return printf("Position exceeds the size of the list\n");
    }

    // Delete the node
    if (!previous) {
        // Deleting the head node
        struct Node* lastNode = *head;
        while (lastNode->next != *head) lastNode = lastNode->next;
        *head = (*head == (*head)->next) ? NULL : lastNode->next;
        lastNode->next = (*head == lastNode->next) ? NULL : lastNode->next->next;
        free(current);
    } else previous->next = current->next, free(current);
}

// Function to print the circular linked list
void printList(struct Node* head) {
    // If the list is empty, print a message and return
    if (!head) return printf("List is empty\n");
    struct Node* temp = head;
    // Traverse the list and print the data of each node
    do printf("%d ", temp->data), temp = temp->next;
    while (temp != head);
    printf("\n");
}

// Function to free memory allocated for the circular linked list
void freeList(struct Node** head) {
    // If the list is empty, return
    if (!*head) return;
    struct Node* current = *head, *nextNode;
    // Traverse the list and free the memory of each node
    do nextNode = current->next, free(current), current = nextNode;
    while (current != *head);
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    
    // Insert nodes at the end
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    // Print the circular linked list
    printf("Circular Linked List: ");
    printList(head);

    // Delete a node at a specific position
    deleteAtLocation(&head, 2);

    // Print the modified circular linked list
    printf("Modified Circular Linked List: ");
    printList(head);

    // Free allocated memory
    freeList(&head);

    return 0;
}