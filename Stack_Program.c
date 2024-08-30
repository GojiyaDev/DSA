//stack program in C Language
#include <stdio.h>
#include <stdlib.h>

// Maximum size of the stack
#define MAX_SIZE 100

// Function declarations
void push(int stack[], int *top, int element, int maxSize);
int pop(int stack[], int *top);
void display(int stack[], int top);
void reverseArray(int stack[], int size);
int isFull(int top, int maxSize);
int isEmpty(int top);

int main() {
    int maxSize;  // Maximum size of the stack set by the user
    int element;  // Element to be pushed
    int top = -1; // Stack pointer initialized to -1
    int stack[MAX_SIZE];  // Static stack array with maximum size of 100
    int choice;  // User's menu choice

    // User input for size of the stack
    printf("Enter the size of the stack (max %d): ", MAX_SIZE);
    scanf("%d", &maxSize);

    // Check if user input is within the maximum size
    if (maxSize > MAX_SIZE || maxSize <= 0) {
        printf("Invalid stack size. It should be between 1 and %d.\n", MAX_SIZE);
        return -1;
    }

    // Menu loop
    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Display the stack\n");
        printf("4. Reverse the stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push an element
                if (isFull(top, maxSize)) {
                    printf("Stack is full. Cannot push element.\n");
                } else {
                    printf("Enter the element to push: ");
                    scanf("%d", &element);
                    push(stack, &top, element, maxSize);
                }
                break;

            case 2: // Pop an element
                if (isEmpty(top)) {
                    printf("Stack is empty. Cannot pop element.\n");
                } else {
                    element = pop(stack, &top);
                    printf("Popped element: %d\n", element);
                }
                break;

            case 3: // Display the stack
                printf("Stack elements:\n");
                display(stack, top);
                break;

            case 4: // Reverse the stack
                reverseArray(stack, top + 1);
                printf("Stack has been reversed.\n");
                printf("Reversed stack elements:\n");
                display(stack, top);
                break;

            case 5: // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to push an element onto the stack
void push(int stack[], int *top, int element, int maxSize) {
    if (isFull(*top, maxSize)) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        stack[++(*top)] = element;
    }
}

// Function to pop an element from the stack
int pop(int stack[], int *top) {
    if (isEmpty(*top)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1; // Return -1 to indicate stack is empty
    } else {
        return stack[(*top)--];
    }
}

// Function to display the elements of the stack
void display(int stack[], int top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to reverse the stack array
void reverseArray(int stack[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap elements
        int temp = stack[start];
        stack[start] = stack[end];
        stack[end] = temp;
        start++;
        end--;
    }
}

// Function to check if the stack is full
int isFull(int top, int maxSize) {
    return top == maxSize - 1;
}

// Function to check if the stack is empty
int isEmpty(int top) {
    return top == -1;
}
