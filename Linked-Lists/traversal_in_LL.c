// Time complexity for travelsal in Linked List is O(n).
#include<stdio.h>
#include<stdlib.h>

// Defining a strucuture for a node in Linked List
struct Node{
    int data;
    struct Node * next;
};

// Function to print data in linked list
void linkedlistTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
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
    linkedlistTraversal(head);
    return 0;
}