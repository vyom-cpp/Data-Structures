#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackNode {
    char data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    struct StackNode* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void reverseString(char* input) {
    struct Stack* stack = createStack();
    for (int i = 0; i < strlen(input); i++) push(stack, input[i]);
    for (int i = 0; i < strlen(input); i++) input[i] = pop(stack);
    input[strlen(input)] = '\0';
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    reverseString(input);
    printf("Reversed string: %s\n", input);
    return 0;
}