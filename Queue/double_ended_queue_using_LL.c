#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Deque;

void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

int isEmpty(Deque* deque) {
    return (deque->front == NULL && deque->rear == NULL);
}

void insertFront(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;

    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void insertRear(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->prev = deque->rear;
    newNode->next = NULL;

    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;  // Assuming -1 represents an invalid value
    }

    Node* temp = deque->front;
    int deletedItem = temp->data;

    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->front = temp->next;
        deque->front->prev = NULL;
    }

    free(temp);
    return deletedItem;
}

int deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;  // Assuming -1 represents an invalid value
    }

    Node* temp = deque->rear;
    int deletedItem = temp->data;

    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = temp->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    return deletedItem;
}

void displayDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    Node* current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Deque deque;
    initDeque(&deque);

    insertFront(&deque, 1);
    insertRear(&deque, 2);
    insertFront(&deque, 3);
    insertRear(&deque, 4);

    displayDeque(&deque);

    printf("Deleted front: %d\n", deleteFront(&deque));
    printf("Deleted rear: %d\n", deleteRear(&deque));

    displayDeque(&deque);

    return 0;
}
