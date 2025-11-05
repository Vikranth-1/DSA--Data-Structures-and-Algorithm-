#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define a node of circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Insert a node at the end of the list
void insert(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = data;

    // If list is empty: new_node points to itself in next and prev
    if (*head_ref == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head_ref = new_node;
        return;
    }

    // Otherwise, find last node
    while (last->next != *head_ref)
        last = last->next;

    // Adjust pointers for new_node insertion at end
    last->next = new_node;
    new_node->prev = last;
    new_node->next = *head_ref;
    (*head_ref)->prev = new_node;
}

// Delete a node by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* curr = *head_ref;

    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Searching node to delete
    while (curr->data != key) {
        curr = curr->next;
        if (curr == *head_ref) {
            printf("Node with value %d not found.\n", key);
            return;
        }
    }

    // If only one node in list
    if (curr->next == curr) {
        *head_ref = NULL;
        free(curr);
        printf("Node with value %d deleted; list is now empty.\n", key);
        return;
    }

    // Update links
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    // If deleting head node, update head
    if (curr == *head_ref)
        *head_ref = curr->next;

    free(curr);
    printf("Node with value %d deleted.\n", key);
}

// Display the list elements
void display(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

void main() {
    struct Node* head = NULL;
    int choice, value;

    clrscr();
    while (1) {
        printf("\nCircular Doubly Linked List Menu:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
