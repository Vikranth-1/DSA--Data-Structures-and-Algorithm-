#include <stdio.h>
#include <conio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int element) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue Overflow! Cannot insert %d\n", element);
        return;
    }
    if (front == -1) { // Inserting first element
        front = rear = 0;
        queue[rear] = element;
    } else if (rear == MAX - 1 && front != 0)
        rear = 0;
    else
        rear++;
    if (front != -1 && queue[rear] != element)
        queue[rear] = element;
    printf("Enqueued %d\n", element);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Queue has become empty
    } else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void main() {
    int choice, element;

    clrscr();
    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
