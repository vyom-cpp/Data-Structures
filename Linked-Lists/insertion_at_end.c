#include<stdio.h>
#include<stdlib.h>

// Defining a structure for node
struct Node{
    int data;
    struct Node * next;
};

// Function to print data
void printLinkedList(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Element: %d", ptr->data);
        ptr = ptr->next;
    }   
}

// Function to insert node at the end
struct Node * insertionAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    
}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;

    // Allocate memory for nodes 
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 14;
    second->next = third;

    // Terminate the list at the third node
    third->data = 21;
    third->next = NULL;

    // Function call
    printLinkedList(head);
    return 0;
}