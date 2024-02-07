#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the stack structure
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; postfix[i] != '\0'; ++i) {
        if (isdigit(postfix[i])) {
            // If the character is a digit, push it onto the stack
            push(&stack, postfix[i] - '0');
        } else {
            // If the character is an operator, pop operands from the stack,
            // perform the operation, and push the result back onto the stack
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        }
    }

    // The result is the only element left on the stack
    return pop(&stack);
}

int main() {
    char postfix[100];

    // Input the postfix expression from the user
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    // Evaluate and print the result
    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}
