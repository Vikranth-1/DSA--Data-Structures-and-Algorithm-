#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert node at the end
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

// Function to delete a node by value (data)
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    // Find node with given key
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    // Node not found
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // If node to be deleted is head
    if (*head_ref == temp)
        *head_ref = temp->next;

    // Change next only if node to be deleted is NOT the last node
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    // Change prev only if node to be deleted is NOT the first node
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Function to display the doubly linked list
void display(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void main() {
    struct Node* head = NULL;
    int choice, value;

    clrscr();
    while (1) {
        printf("\nDoubly Linked List Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("\n");
    }
}
