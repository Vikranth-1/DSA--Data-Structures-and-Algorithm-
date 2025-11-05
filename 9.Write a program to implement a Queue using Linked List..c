#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to enqueue element at the rear
void enqueue(struct Node** front_ref, struct Node** rear_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (*rear_ref == NULL) {
        *front_ref = *rear_ref = new_node;
    } else {
        (*rear_ref)->next = new_node;
        *rear_ref = new_node;
    }
    printf("Enqueued %d to the queue.\n", data);
}

// Function to dequeue element from the front
void dequeue(struct Node** front_ref, struct Node** rear_ref) {
    if (*front_ref == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct Node* temp = *front_ref;
    int dequeued_value = temp->data;
    *front_ref = (*front_ref)->next;

    if (*front_ref == NULL)
        *rear_ref = NULL;

    free(temp);
    printf("Dequeued %d from the queue.\n", dequeued_value);
}

// Function to display the queue elements
void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

void main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;

    clrscr();
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
