#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define structure for stack node
struct Node {
    int data;
    struct Node* next;
};

// Push operation: insert element at the beginning (top) of the stack
void push(struct Node** top_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Stack overflow! Could not allocate memory.\n");
        return;
    }
    new_node->data = data;
    new_node->next = *top_ref;
    *top_ref = new_node;
    printf("Pushed %d onto the stack.\n", data);
}

// Pop operation: remove element from the top of the stack
void pop(struct Node** top_ref) {
    if (*top_ref == NULL) {
        printf("Stack underflow! No elements to pop.\n");
        return;
    }
    struct Node* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    printf("Popped %d from the stack.\n", temp->data);
    free(temp);
}

// Display the stack elements from top to bottom
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements:\n");
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

void main() {
    struct Node* stackTop = NULL;
    int choice, value;

    clrscr();
    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stackTop, value);
                break;
            case 2:
                pop(&stackTop);
                break;
            case 3:
                display(stackTop);
                break;
            case 4:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
