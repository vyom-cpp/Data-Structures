#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for a stack node
struct StackNode {
    char data;
    struct StackNode* next;
};

// Structure for stack
struct Stack {
    struct StackNode* top;
};

// Function to initialize an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
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

// Function to return the precedence of an operator
int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack* stack = createStack();
    int infixLength = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    for (int i = infixLength - 1; i >= 0; i--) {
        char currentSymbol = infix[i];

        // If current symbol is an operand, add it to the prefix expression
        if (isalnum(currentSymbol)) {
            prefix[prefixIndex++] = currentSymbol;
        }
        // If current symbol is a closing parenthesis, push it onto the stack
        else if (currentSymbol == ')') {
            push(stack, currentSymbol);
        }
        // If current symbol is an operator or an opening parenthesis
        else {
            while (!isEmpty(stack) && getPrecedence(stack->top->data) > getPrecedence(currentSymbol)) {
                prefix[prefixIndex++] = pop(stack);
            }
            if (currentSymbol == '(') {
                // Pop elements from the stack until a matching closing parenthesis is encountered
                pop(stack);
            } else {
                // Push the current symbol onto the stack
                push(stack, currentSymbol);
            }
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(stack)) {
        prefix[prefixIndex++] = pop(stack);
    }

    // Null-terminate the prefix expression
    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression to get the final result
    strrev(prefix);
}

int main() {
    char infix[100], prefix[100];

    // Input the infix expression
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Convert infix to prefix
    infixToPrefix(infix, prefix);

    // Print the prefix expression
    printf("Prefix expression: %s\n", prefix);

    return 0;
}