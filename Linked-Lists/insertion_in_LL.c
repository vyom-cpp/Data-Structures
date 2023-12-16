#include<stdio.h>
#include<stdlib.h>

// Defining a strucutre for a node in linked list
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

// Function to insert at the beginning
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
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
    head = insertAtFirst(head, 28);
    linkedlistTraversal(head);
    return 0;
}

// Time complexity for insertion at beginning of a node in Linked List is O(1).
// Time complexity for insertion in between of a node in Linked List is O(n).
// Time complexity for insertion at the end of a node in Linked List is O(n).
// Time complexity for insertion after a node in Linked List is O(n).
// Algorithm to insert a node at beginning
// Steps
/*
1. Make the first node of Linked List linked to the new node
2. Remove the head from the original first node of Linked List
3. Make the new node as the Head of the Linked List.
*/
// Approach
/*
void push(struct Node** head_ref, int new_data)
{
    // 1. allocate node 
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    // 2. put in the data  
    new_node->data = new_data;
 
    // 3. Make next of new node as head 
    new_node->next = (*head_ref);
 
    // 4. move the head to point to the new node 
    (*head_ref) = new_node;
}
*/
// Algorithm to insert a node after a given node
// Steps
/*
1. Check if the given node exists or not. 
2. If it do not exists, terminate the process.
3. If the given node exists,
4. Make the element to be inserted as a new node
5. Change the next pointer of given node to the new node
6. Now shift the original next pointer of given node to the next pointer of new node
*/
// Approach
/*
void insertAfter(struct Node* prev_node, int new_data)
{
    // 1. check if the given prev_node is NULL 
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
 
    // 2. allocate new node 
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    // 3. put in the data 
    new_node->data = new_data;
 
    // 4. Make next of new node as next of prev_node 
    new_node->next = prev_node->next;
 
    // 5. move the next of prev_node as new_node 
    prev_node->next = new_node;
}
*/
// Algorithm to insert a node at the end
// Steps
/*
1. Go to the last node of the Linked List
2. Change the next pointer of last node from NULL to the new node
3. Make the next pointer of new node as NULL to show the end of Linked List
*/
// Approach
/*
void append(struct Node** head_ref, int new_data)
{
    // 1. allocate node 
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    struct Node* last = *head_ref; // used in step 5
 
    // 2. put in the data 
    new_node->data = new_data;
 
    // 3. This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;
 
    // 4. If the Linked List is empty, then make the new * node as head 
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
 
    // 5. Else traverse till the last node 
    while (last->next != NULL)
        last = last->next;
 
    // 6. Change the next of last node 
    last->next = new_node;
    return;
}
*/