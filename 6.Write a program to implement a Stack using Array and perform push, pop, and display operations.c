#include <stdio.h>
#include <conio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", element);
        return;
    }
    stack[++top] = element;
    printf("Pushed %d onto the stack.\n", element);
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    printf("Popped %d from the stack.\n", stack[top--]);
}

// Function to display elements of the stack
void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

void main() {
    int choice, element;

    clrscr();
    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
